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

#include "Animation2.h"
#include "Particle.h"
#include "ResourceIdentifiers.h"

#include <map>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>



enum class LevelType
{
	Forest,
	Cemetery,
	Beach,
	Mountain,
};



enum class EnemyType
{
	Lich,
	Zombie,
	Skeleton,
	AncientZombie,
};



enum class Direction
{
	UpRight,
	DownRight,
	DownLeft,
	UpLeft
};



struct EnemyData
{
	TextureID										texture;
	std::map<Direction, Animation2>					animations;
	sf::Time										speed;

};



struct WaveData
{
	EnemyData										enemyData;
	std::size_t										enemyCount;
	float											spawnRate;

};



struct LaneData
{
	sf::Vector2f									position;
	std::vector<Direction>							route;

};



struct LevelData
{
	TextureID										backgroundTexture;
	std::string										backgroundTexturePath;
	std::vector<LaneData>							lanes;
	std::vector<WaveData>							waves;

};



struct ParticleData
{
	sf::Color			color;
	sf::Time			lifetime;

};



std::map<LevelType, LevelData> initializeLevelData();
std::map<EnemyType, EnemyData> initializeEnemyData();
std::map<Particle::Type, ParticleData> initializeParticleData();