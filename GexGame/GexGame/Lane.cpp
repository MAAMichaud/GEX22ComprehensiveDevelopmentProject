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
#include "Lane.h"



Lane::Lane(const TextureHolder_t& _textures, LaneData data)
	: textures(_textures)
	, enemyType()
	, spawnRate(1.0f)
	, timeRemaining(sf::Time::Zero)
	, route(data.route)
{
	setPosition(data.position);
}



void Lane::loadEnemy(AnimatedNode::Type _enemyType)
{
	enemyType = _enemyType;
}



void Lane::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	while (dt > timeRemaining)
	{
		dt -= timeRemaining;
		timeRemaining += sf::seconds(1.f);

		auto lichNode{ std::make_unique<AnimatedNode>(textures, enemyType)};
		this->attachChild(std::move(lichNode));

	}

	timeRemaining -= dt;
}
