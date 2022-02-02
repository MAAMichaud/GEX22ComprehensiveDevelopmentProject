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
	, velocity(-30.0f, 20.0f)
	, animation()
	, type(_type)
	, animations()
	, direction(Direction::DownLeft)
{
	for (auto a : ENEMY_DATA.at(type).animations)
	{
		animations[a.first] = a.second;
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

	move(velocity * dt.asSeconds());
}
