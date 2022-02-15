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
#include "Lane.h"
#include "Utility.h"



Lane::Lane(const TextureHolder_t& _textures, LaneData data)
	: textures(_textures)
	, enemyData()
	, route(data.route)
{
	setPosition(data.position);
}



void Lane::spawnEnemy()
{
	auto enemyNode{ std::make_unique<Enemy>(textures, enemyData, route)};
	this->attachChild(std::move(enemyNode));
}



void Lane::loadEnemy(EnemyData _enemyData)
{
	enemyData = _enemyData;
}