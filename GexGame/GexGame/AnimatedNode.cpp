/**
* author  Marc-Andre Michaud
*
* 
* @section DESCRIPTION
*  Gex Game
*  Based SFML Game Development Textbook 
*  
* @section Academic Integrity
*  I certify that this work is solely my own and complies with 
*  NBCC Academic Integrity Policy (policy 1111)
*/
#include "AnimatedNode.h"
#include "Animation2.h"
#include "DataTables.h"
#include "JsonFrameParser.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>



namespace
{
	const std::map<AnimatedNode::Type, EnemyData> ENEMY_DATA{ initializeEnemyData() };
}

AnimatedNode::AnimatedNode(const TextureHolder_t& textures, Type _type)
	: sprite(textures.get(ENEMY_DATA.at(_type).texture))
	//, velocity(-30.0f, 20.0f)
	, velocity(HORIZONTAL_HOP_PER_FRAME, VERTICAL_HOP_PER_FRAME)
	, bearing(-1, 1)
	, animation()
	, type(_type)
	, animations()
	, direction(Direction::DownLeft)
	, movementSpeed(sf::seconds(2.0f))
	, timeRemaining(movementSpeed)
{
	for (auto a : ENEMY_DATA.at(type).animations)
	{
		animations[a.first] = a.second;
	}

}



void AnimatedNode::turn(Direction _direction)
{
	direction = _direction;

	switch (direction)
	{
	case Direction::UpRight:
		bearing.x = 1;
		bearing.y = -1;
		break;

	case Direction::DownRight:
		bearing.x = 1;
		bearing.y = 1;
		break;

	case Direction::DownLeft:
		bearing.x = -1;
		bearing.y = 1;
		break;

	case Direction::UpLeft:
		bearing.x = -1;
		bearing.y = -1;
		break;

	}
}



void AnimatedNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



void AnimatedNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	auto frame = animations.at(direction).update(dt);

	sprite.setTextureRect(frame.intRect);
	sprite.setPosition(frame.offset.first, frame.offset.second);


	while (dt > timeRemaining)
	{
		dt -= timeRemaining;
		move(velocity * timeRemaining.asSeconds());
		timeRemaining = movementSpeed;

		switch (direction)
		{
		case Direction::UpRight:
			turn(Direction::UpLeft);
			break;

		case Direction::DownRight:
			turn(Direction::UpRight);
			break;

		case Direction::DownLeft:
			turn(Direction::DownRight);
			break;

		case Direction::UpLeft:
			turn(Direction::DownLeft);
			break;

		}
	}

	timeRemaining -= dt;
	move(velocity.x * bearing.x * dt.asSeconds(), velocity.y * bearing.y * dt.asSeconds());
}
