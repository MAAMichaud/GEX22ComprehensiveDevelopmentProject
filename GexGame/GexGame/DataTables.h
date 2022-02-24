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

#include <fstream>



enum class LevelType
{
	Forest,
	Cemetery,
	Beach,
	Mountain,
};



enum class ProjectileType
{
	None,
	MagicArrow,
	IceBall,
	Fireball,
	Lightning,
	Poison,
};



enum class AttackEffect
{
	None,
	Freeze,
	DeepFreeze,
	Area,
	BigArea,
	Stun,
	Poison,
	GreatPoison,
	GreaterPoison,
};



enum class EnemyType
{
	AxeGrandmaster,
	Lich,
	Zombie,
	Skeleton,
	AncientZombie,
};



enum class TowerType
{
	ClubWarrior,
	SwordWarrior,
	SwordMaster,
	SwordGrandmaster,
	AxeWarrior,
	AxeMaster,
	AxeGrandmaster,
	MaceWarrior,
	MaceMaster,
	MaceGrandmaster,
	Novice,
	IceApprentice,
	IceMaster,
	IceGrandmaster,
	FireApprentice,
	FireMaster,
	FireGrandmaster,
	EnergyApprentice,
	EnergyMaster,
	EnergyGrandmaster,
	PoisonApprentice,
	PoisonMaster,
	PoisonGrandmaster,
	IceSword,
	IceSword2,
	FireAxe,
	FireAxe2,
	EnergyMace,
	EnergyMace2,
};



enum class Direction
{
	Up,
	Down,
	Right,
	Left,
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



struct TowerData
{
	TowerData(std::size_t range = 1, ProjectileType projectileType = ProjectileType::None, AttackEffect attackEffect = AttackEffect::None);

	std::map<Direction, Animation2>					animations;
	std::size_t										range;
	ProjectileType									projectileType;
	AttackEffect									attackEffect;

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
std::map<TowerType, TowerData> initializeTowerData();
std::map<EnemyType, EnemyData> initializeEnemyData();
std::map<Particle::Type, ParticleData> initializeParticleData();