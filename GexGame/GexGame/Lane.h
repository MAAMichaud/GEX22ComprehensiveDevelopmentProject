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
#pragma once

#include "DataTables.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"

class Enemy;



class Lane: public SceneNode
{
public:
	explicit									Lane(const TextureHolder_t& textures, LaneData data);
	void										spawnEnemy();
	void										loadEnemy(EnemyData enemyData);
	std::vector<Enemy*>							getEnemiesAt(const int tileX, const int tileY);

private:
	const TextureHolder_t&						textures;
	EnemyData									enemyData;
	std::vector<Direction>						route;

};