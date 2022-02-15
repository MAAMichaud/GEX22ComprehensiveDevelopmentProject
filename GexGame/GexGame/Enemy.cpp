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
#include "Enemy.h"
#include "Animation2.h"
#include "JsonFrameParser.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>



Enemy::Enemy(const TextureHolder_t& textures, EnemyData enemyData, std::vector<Direction>& _route)
	: sprite(textures.get(enemyData.texture))
	, velocity(HORIZONTAL_HOP_LENGTH / enemyData.speed.asSeconds(), VERTICAL_HOP_LENGTH / enemyData.speed.asSeconds())
	, bearing(-1, 1)
	, animations()
	, direction(Direction::DownLeft)
	, movementSpeed(enemyData.speed)
	, timeRemaining(enemyData.speed)
	, route(_route)
	, routeIndex(0)
{
	for (auto a : enemyData.animations)
	{
		animations[a.first] = a.second;
	}
}



void Enemy::turn(Direction _direction)
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



void Enemy::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



void Enemy::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	auto frame = animations.at(direction).update(dt);

	sprite.setTextureRect(frame.intRect);
	//sprite.setColor(frame.isRotated ? sf::Color(0, 255, 255, 255) : sf::Color(255, 0, 255, 255));
	if (direction == Direction::UpRight || direction == Direction::DownRight)
	{
		sprite.setRotation(frame.isRotated ? -90.f : 0.f);
	}
	else
	{
		sprite.setRotation(frame.isRotated ? 90.f : 0.f);
	}
	sprite.setPosition(frame.offset.first, frame.offset.second);


	while (dt > timeRemaining)
	{
		dt -= timeRemaining;
		move(velocity * timeRemaining.asSeconds());
		timeRemaining = movementSpeed;

		turn(route.at(routeIndex % route.size()));
		routeIndex += 1;

	}

	timeRemaining -= dt;
	move(velocity.x * bearing.x * dt.asSeconds(), velocity.y * bearing.y * dt.asSeconds());
}



bool Enemy::isDestroyed() const
{
	return routeIndex >= route.size();
}