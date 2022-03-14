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
	DireWolf,
	ForestScorpion,
	GiantScorpion,
	GreyWolf,
	Ogre,
	OrcBoss,
	OrcLumberjack,
	OrcScout,
	OrcSoldier,
	OrcWarrior,
	TimberWolf,
	AncientZombie,
	DireGhostWolf,
	DireZombieDog,
	GhostDog,
	GhostWolf,
	LichKing,
	LichLord,
	Lich,
	Skeleton,
	ZombieDog,
	Zombie,
	AncientDrowned,
	DeepSeaScorpion,
	DrownedBones,
	DrownedLich,
	Drowned,
	FishmanElite,
	Fishman,
	GhostPirateCaptain,
	GhostPirate,
	OrcPirateCaptain,
	OrcPirate,
	SeaDog,
	SeaScorpion,
	ZombiePirate,
	AncientMedusa,
	CharredBones,
	Charred,
	FireGiant,
	FireLich,
	FireMedusa,
	FireScorpion,
	HellHound,
	HobgoblinHeavyInfantry,
	HobgoblinScout,
	HobgoblinWarrior,
	MagmaKing,
	MagmaScorpion,
	Medusa,
	MountainGiant,
	RockScorpion,
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
	None,
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
	EnemyData(float speed = 0.5f,
		double healthPoints = 1.0,
		std::size_t gold = 1,
		std::size_t experiencePoints = 1);

	TextureID										texture;
	std::map<Direction, Animation2>					animations;
	float											speed;
	double											healthPoints;
	std::size_t										gold;
	std::size_t										experiencePoints;

};



struct TowerData
{
	TowerData(std::size_t range = 1,
		float swingSpeed = 1.0f,
		float cooldown = 1.5f,
		ProjectileType projectileType = ProjectileType::None, 
		double damage = 1,
		AttackEffect attackEffect = AttackEffect::None, 
		std::size_t experienceToNextLevel = 10);

	std::map<Direction, Animation2>					animations;
	float											swingSpeed;
	float											cooldown;
	std::size_t										range;
	ProjectileType									projectileType;
	double											damage;
	AttackEffect									attackEffect;
	std::size_t										experienceToNextLevel;

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
	sf::Color										color;
	sf::Time										lifetime;

};



std::map<LevelType, LevelData>						initializeLevelData();
std::map<TowerType, TowerData>						initializeTowerData();
std::map<EnemyType, EnemyData>						initializeEnemyData();
std::map<TowerType, TowerType>						initializeLevelUpData();
std::map<Particle::Type, ParticleData>				initializeParticleData();