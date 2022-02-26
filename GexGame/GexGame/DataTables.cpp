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
#include "DataTables.h"
#include "JsonFrameParser.h"
#include <fstream>



EnemyData::EnemyData(float _speed, 
		double _healthPoints,
		std::size_t _gold,
		std::size_t _experiencePoints)
	: texture()
	, animations()
	, speed(_speed)
	, healthPoints(_healthPoints)
	, gold(_gold)
	, experiencePoints(_experiencePoints)
{
}



TowerData::TowerData(std::size_t _range, 
	float _swingSpeed, 
	float _cooldown, 
	ProjectileType _projectileType, 
	double _damage, 
	AttackEffect _attackEffect, 
	std::size_t _experienceToNextLevel)
	: animations()
	, range(_range)
	, swingSpeed(_swingSpeed)
	, cooldown(_cooldown)
	, projectileType(_projectileType)
	, damage(_damage)
	, attackEffect(_attackEffect)
	, experienceToNextLevel(_experienceToNextLevel)
{
}



void to_json(json& j, const Frame& f) {
	j = json{ {"intRect", f.intRect }, {"offset", f.offset}, {"rotated", f.isRotated} };
}

void from_json(const json& j, Frame& f) {
	j.at("intRect").get_to(f.intRect);
	j.at("offset").get_to(f.offset);
	j.at("rotated").get_to(f.isRotated);
}


void to_json(json& j, const Animation2& a) {
	j = json{ {"frames", a.frames }, {"repeat", a.repeat} };
}

void from_json(const json& j, Animation2& a) {
	j.at("frames").get_to(a.frames);
	j.at("repeat").get_to(a.repeat);
}


void to_json(json& j, const EnemyData& t) {
	j = json{ {"animations", t.animations}, 
		{"texture", t.texture}, 
		{"speed", t.speed}, 
		{"healthPoints", t.healthPoints}, 
		{"gold", t.gold}, 
		{"experiencePoints", t.experiencePoints}};
}

void from_json(const json& j, EnemyData& t) {
	j.at("animations").get_to(t.animations);
	j.at("texture").get_to(t.texture);
	j.at("speed").get_to(t.speed);
	j.at("healthPoints").get_to(t.healthPoints);
	j.at("gold").get_to(t.gold);
	j.at("experiencePoints").get_to(t.experiencePoints);
}


void to_json(json& j, const TowerData& t) {
	j = json{ {"animations", t.animations}, 
		{"range", t.range}, 
		{"swingSpeed", t.swingSpeed}, 
		{"cooldown", t.cooldown}, 
		{"projectileType", t.projectileType}, 
		{"damage", t.damage}, 
		{"attackEffect", t.attackEffect}, 
		{"experienceToNextLevel", t.experienceToNextLevel}};
}

void from_json(const json& j, TowerData& t) {
	j.at("animations").get_to(t.animations);
	j.at("range").get_to(t.range);
	j.at("swingSpeed").get_to(t.swingSpeed);
	j.at("cooldown").get_to(t.cooldown);
	j.at("projectileType").get_to(t.projectileType);
	j.at("damage").get_to(t.damage);
	j.at("attackEffect").get_to(t.attackEffect);
	j.at("experienceToNextLevel").get_to(t.experienceToNextLevel);
}



std::map<LevelType, LevelData> initializeLevelData()
{
	std::map<LevelType, LevelData> data;
	std::map<EnemyType, EnemyData> enemyData = initializeEnemyData();

	data[LevelType::Forest].backgroundTexture = TextureID::ForestBoard;
	data[LevelType::Forest].backgroundTexturePath = "../Media/Textures/ForestBoard.png";
	data[LevelType::Forest].lanes.push_back(LaneData());
	data[LevelType::Forest].lanes.at(0).position = sf::Vector2f(1042.f, 84.f);

	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 18; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 12; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Forest].waves.push_back(WaveData());
	data[LevelType::Forest].waves.at(0).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Forest].waves.at(0).enemyCount = 5;
	data[LevelType::Forest].waves.at(0).spawnRate = 0.5f;

	data[LevelType::Forest].waves.push_back(WaveData());
	data[LevelType::Forest].waves.at(1).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Forest].waves.at(1).enemyCount = 10;
	data[LevelType::Forest].waves.at(1).spawnRate = 1.5f;

	data[LevelType::Forest].waves.push_back(WaveData());
	data[LevelType::Forest].waves.at(2).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Forest].waves.at(2).enemyCount = 3;
	data[LevelType::Forest].waves.at(2).spawnRate = 0.2f;

	data[LevelType::Forest].waves.push_back(WaveData());
	data[LevelType::Forest].waves.at(3).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Forest].waves.at(3).enemyCount = 7;
	data[LevelType::Forest].waves.at(3).spawnRate = 0.6f;

	data[LevelType::Forest].waves.push_back(WaveData());
	data[LevelType::Forest].waves.at(4).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Forest].waves.at(4).enemyCount = 8;
	data[LevelType::Forest].waves.at(4).spawnRate = 0.4f;


	data[LevelType::Cemetery].backgroundTexture = TextureID::CemeteryBoard;
	data[LevelType::Cemetery].backgroundTexturePath = "../Media/Textures/CemeteryBoard.png";

	data[LevelType::Cemetery].lanes.push_back(LaneData());
	data[LevelType::Cemetery].lanes.at(0).position = sf::Vector2f(1042.f, 84.f);

	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 14; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 20; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Cemetery].lanes.at(0).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Cemetery].lanes.push_back(LaneData());
	data[LevelType::Cemetery].lanes.at(1).position = sf::Vector2f(1042.f - 36.f, 84.f - 24.f);

	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 22; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 18; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 12; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Cemetery].lanes.at(1).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Cemetery].waves.push_back(WaveData());
	data[LevelType::Cemetery].waves.at(0).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Cemetery].waves.at(0).enemyCount = 60;
	data[LevelType::Cemetery].waves.at(0).spawnRate = 0.5f;

	data[LevelType::Cemetery].waves.push_back(WaveData());
	data[LevelType::Cemetery].waves.at(1).enemyData = enemyData.at(EnemyType::Zombie);
	data[LevelType::Cemetery].waves.at(1).enemyCount = 10;
	data[LevelType::Cemetery].waves.at(1).spawnRate = 0.3f;

	data[LevelType::Cemetery].waves.push_back(WaveData());
	data[LevelType::Cemetery].waves.at(2).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Cemetery].waves.at(2).enemyCount = 9;
	data[LevelType::Cemetery].waves.at(2).spawnRate = 0.2f;

	data[LevelType::Cemetery].waves.push_back(WaveData());
	data[LevelType::Cemetery].waves.at(3).enemyData = enemyData.at(EnemyType::AncientZombie);
	data[LevelType::Cemetery].waves.at(3).enemyCount = 7;
	data[LevelType::Cemetery].waves.at(3).spawnRate = 0.6f;

	data[LevelType::Cemetery].waves.push_back(WaveData());
	data[LevelType::Cemetery].waves.at(4).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Cemetery].waves.at(4).enemyCount = 8;
	data[LevelType::Cemetery].waves.at(4).spawnRate = 0.4f;

	data[LevelType::Beach].backgroundTexture = TextureID::BeachBoard;
	data[LevelType::Beach].backgroundTexturePath = "../Media/Textures/BeachBoard.png";

	data[LevelType::Beach].lanes.push_back(LaneData());
	data[LevelType::Beach].lanes.at(0).position = sf::Vector2f(1042.f - 36.f, 84.f - 24.f);

	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 14; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Beach].lanes.at(0).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Beach].lanes.push_back(LaneData());
	data[LevelType::Beach].lanes.at(1).position = sf::Vector2f(1042.f + 36.f * 8, 84.f + 24.f * 8);

	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Beach].lanes.at(1).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Beach].waves.push_back(WaveData());
	data[LevelType::Beach].waves.at(0).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Beach].waves.at(0).enemyCount = 60;
	data[LevelType::Beach].waves.at(0).spawnRate = 0.5f;

	data[LevelType::Beach].waves.push_back(WaveData());
	data[LevelType::Beach].waves.at(1).enemyData = enemyData.at(EnemyType::Zombie);
	data[LevelType::Beach].waves.at(1).enemyCount = 10;
	data[LevelType::Beach].waves.at(1).spawnRate = 0.3f;

	data[LevelType::Beach].waves.push_back(WaveData());
	data[LevelType::Beach].waves.at(2).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Beach].waves.at(2).enemyCount = 9;
	data[LevelType::Beach].waves.at(2).spawnRate = 0.2f;

	data[LevelType::Beach].waves.push_back(WaveData());
	data[LevelType::Beach].waves.at(3).enemyData = enemyData.at(EnemyType::AncientZombie);
	data[LevelType::Beach].waves.at(3).enemyCount = 7;
	data[LevelType::Beach].waves.at(3).spawnRate = 0.6f;

	data[LevelType::Beach].waves.push_back(WaveData());
	data[LevelType::Beach].waves.at(4).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Beach].waves.at(4).enemyCount = 8;
	data[LevelType::Beach].waves.at(4).spawnRate = 0.4f;


	data[LevelType::Mountain].backgroundTexture = TextureID::MountainBoard;
	data[LevelType::Mountain].backgroundTexturePath = "../Media/Textures/MountainBoard.png";

	data[LevelType::Mountain].lanes.push_back(LaneData());
	data[LevelType::Mountain].lanes.at(0).position = sf::Vector2f(1042.f - 36.f * 2, 84.f - 24.f * 2);

	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 20; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Mountain].lanes.at(0).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Mountain].lanes.push_back(LaneData());
	data[LevelType::Mountain].lanes.at(1).position = sf::Vector2f(1042.f + 36.f * 3, 84.f + 24.f * 3);

	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Mountain].lanes.at(1).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Mountain].lanes.push_back(LaneData());
	data[LevelType::Mountain].lanes.at(2).position = sf::Vector2f(1042.f + 36.f * 9, 84.f + 24.f * 9);

	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 20; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownRight);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Mountain].lanes.at(2).route.push_back(Direction::DownLeft);
	}

	data[LevelType::Mountain].waves.push_back(WaveData());
	data[LevelType::Mountain].waves.at(0).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Mountain].waves.at(0).enemyCount = 60;
	data[LevelType::Mountain].waves.at(0).spawnRate = 0.5f;

	data[LevelType::Mountain].waves.push_back(WaveData());
	data[LevelType::Mountain].waves.at(1).enemyData = enemyData.at(EnemyType::Zombie);
	data[LevelType::Mountain].waves.at(1).enemyCount = 10;
	data[LevelType::Mountain].waves.at(1).spawnRate = 0.3f;

	data[LevelType::Mountain].waves.push_back(WaveData());
	data[LevelType::Mountain].waves.at(2).enemyData = enemyData.at(EnemyType::Lich);
	data[LevelType::Mountain].waves.at(2).enemyCount = 9;
	data[LevelType::Mountain].waves.at(2).spawnRate = 0.2f;

	data[LevelType::Mountain].waves.push_back(WaveData());
	data[LevelType::Mountain].waves.at(3).enemyData = enemyData.at(EnemyType::AncientZombie);
	data[LevelType::Mountain].waves.at(3).enemyCount = 7;
	data[LevelType::Mountain].waves.at(3).spawnRate = 0.6f;

	data[LevelType::Mountain].waves.push_back(WaveData());
	data[LevelType::Mountain].waves.at(4).enemyData = enemyData.at(EnemyType::Skeleton);
	data[LevelType::Mountain].waves.at(4).enemyCount = 8;
	data[LevelType::Mountain].waves.at(4).spawnRate = 0.4f;

	return data;
}



std::map<EnemyType, EnemyData> initializeEnemyData()
{
	std::map<EnemyType, EnemyData> data;

	std::ifstream ifs("../Media/Textures/EnemyData.json");


	if (ifs.fail())
	{
		auto frames{ JsonFrameParser("../Media/Textures/ForestLeveLFlipped.json") };

		data[EnemyType::DireWolf].texture = TextureID::ForestLevel;
		data[EnemyType::DireWolf].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DireWolfWalkUpRight"));
		data[EnemyType::DireWolf].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DireWolfWalkDownRight"));
		data[EnemyType::DireWolf].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DireWolfWalkDownLeft"));
		data[EnemyType::DireWolf].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DireWolfWalkUpLeft"));
		data[EnemyType::DireWolf].speed = 0.3f;
		data[EnemyType::DireWolf].healthPoints = 120;
		data[EnemyType::DireWolf].gold = 12;
		data[EnemyType::DireWolf].experiencePoints = 12;

		data[EnemyType::ForestScorpion].texture = TextureID::ForestLevel;
		data[EnemyType::ForestScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ForestScorpionWalkUpRight"));
		data[EnemyType::ForestScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ForestScorpionWalkDownRight"));
		data[EnemyType::ForestScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ForestScorpionWalkDownLeft"));
		data[EnemyType::ForestScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ForestScorpionWalkUpLeft"));
		data[EnemyType::ForestScorpion].speed = 0.7f;
		data[EnemyType::ForestScorpion].healthPoints = 80;
		data[EnemyType::ForestScorpion].gold = 8;
		data[EnemyType::ForestScorpion].experiencePoints = 8;

		data[EnemyType::GiantScorpion].texture = TextureID::ForestLevel;
		data[EnemyType::GiantScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GiantScorpionWalkUpRight"));
		data[EnemyType::GiantScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GiantScorpionWalkDownRight"));
		data[EnemyType::GiantScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GiantScorpionWalkDownLeft"));
		data[EnemyType::GiantScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GiantScorpionWalkUpLeft"));
		data[EnemyType::GiantScorpion].speed = 0.7f;
		data[EnemyType::GiantScorpion].healthPoints = 140;
		data[EnemyType::GiantScorpion].gold = 14;
		data[EnemyType::GiantScorpion].experiencePoints = 14;

		data[EnemyType::GreyWolf].texture = TextureID::ForestLevel;
		data[EnemyType::GreyWolf].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GreyWolfWalkUpRight"));
		data[EnemyType::GreyWolf].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GreyWolfWalkDownRight"));
		data[EnemyType::GreyWolf].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GreyWolfWalkDownLeft"));
		data[EnemyType::GreyWolf].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GreyWolfWalkUpLeft"));
		data[EnemyType::GreyWolf].speed = 0.4f;
		data[EnemyType::GreyWolf].healthPoints = 60;
		data[EnemyType::GreyWolf].gold = 6;
		data[EnemyType::GreyWolf].experiencePoints = 6;

		data[EnemyType::Ogre].texture = TextureID::ForestLevel;
		data[EnemyType::Ogre].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OgreWalkUpRight"));
		data[EnemyType::Ogre].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OgreWalkDownRight"));
		data[EnemyType::Ogre].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OgreWalkDownLeft"));
		data[EnemyType::Ogre].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OgreWalkUpLeft"));
		data[EnemyType::Ogre].speed = 0.8f;
		data[EnemyType::Ogre].healthPoints = 500;
		data[EnemyType::Ogre].gold = 50;
		data[EnemyType::Ogre].experiencePoints = 50;

		data[EnemyType::OrcBoss].texture = TextureID::ForestLevel;
		data[EnemyType::OrcBoss].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcBossWalkUpRight"));
		data[EnemyType::OrcBoss].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcBossWalkDownRight"));
		data[EnemyType::OrcBoss].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcBossWalkDownLeft"));
		data[EnemyType::OrcBoss].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcBossWalkUpLeft"));
		data[EnemyType::OrcBoss].speed = 0.8f;
		data[EnemyType::OrcBoss].healthPoints = 2000;
		data[EnemyType::OrcBoss].gold = 200;
		data[EnemyType::OrcBoss].experiencePoints = 200;

		data[EnemyType::OrcLumberjack].texture = TextureID::ForestLevel;
		data[EnemyType::OrcLumberjack].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcLumberjackWalkUpRight"));
		data[EnemyType::OrcLumberjack].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcLumberjackWalkDownRight"));
		data[EnemyType::OrcLumberjack].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcLumberjackWalkDownLeft"));
		data[EnemyType::OrcLumberjack].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcLumberjackWalkUpLeft"));
		data[EnemyType::OrcLumberjack].speed = 0.5f;
		data[EnemyType::OrcLumberjack].healthPoints = 40;
		data[EnemyType::OrcLumberjack].gold = 4;
		data[EnemyType::OrcLumberjack].experiencePoints = 4;

		data[EnemyType::OrcScout].texture = TextureID::ForestLevel;
		data[EnemyType::OrcScout].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcScoutWalkUpRight"));
		data[EnemyType::OrcScout].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcScoutWalkDownRight"));
		data[EnemyType::OrcScout].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcScoutWalkDownLeft"));
		data[EnemyType::OrcScout].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcScoutWalkUpLeft"));
		data[EnemyType::OrcScout].speed = 0.4f;
		data[EnemyType::OrcScout].healthPoints = 80;
		data[EnemyType::OrcScout].gold = 8;
		data[EnemyType::OrcScout].experiencePoints = 8;

		data[EnemyType::OrcSoldier].texture = TextureID::ForestLevel;
		data[EnemyType::OrcSoldier].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcSoldierWalkUpRight"));
		data[EnemyType::OrcSoldier].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcSoldierWalkDownRight"));
		data[EnemyType::OrcSoldier].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcSoldierWalkDownLeft"));
		data[EnemyType::OrcSoldier].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcSoldierWalkUpLeft"));
		data[EnemyType::OrcSoldier].speed = 0.5f;
		data[EnemyType::OrcSoldier].healthPoints = 200;
		data[EnemyType::OrcSoldier].gold = 20;
		data[EnemyType::OrcSoldier].experiencePoints = 20;

		data[EnemyType::OrcWarrior].texture = TextureID::ForestLevel;
		data[EnemyType::OrcWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcWarriorWalkUpRight"));
		data[EnemyType::OrcWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcWarriorWalkDownRight"));
		data[EnemyType::OrcWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcWarriorWalkDownLeft"));
		data[EnemyType::OrcWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcWarriorWalkUpLeft"));
		data[EnemyType::OrcWarrior].speed = 0.6f;
		data[EnemyType::OrcWarrior].healthPoints = 400;
		data[EnemyType::OrcWarrior].gold = 40;
		data[EnemyType::OrcWarrior].experiencePoints = 40;

		data[EnemyType::TimberWolf].texture = TextureID::ForestLevel;
		data[EnemyType::TimberWolf].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("TimberWolfWalkUpRight"));
		data[EnemyType::TimberWolf].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("TimberWolfWalkDownRight"));
		data[EnemyType::TimberWolf].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("TimberWolfWalkDownLeft"));
		data[EnemyType::TimberWolf].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("TimberWolfWalkUpLeft"));
		data[EnemyType::TimberWolf].speed = 0.4f;
		data[EnemyType::TimberWolf].healthPoints = 30;
		data[EnemyType::TimberWolf].gold = 3;
		data[EnemyType::TimberWolf].experiencePoints = 3;

		frames = JsonFrameParser("../Media/Textures/CemeteryLeveLFlipped.json");

		data[EnemyType::AncientZombie].texture = TextureID::CemeteryLevel;
		data[EnemyType::AncientZombie].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AncientZombieWalkUpRight"));
		data[EnemyType::AncientZombie].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AncientZombieWalkDownRight"));
		data[EnemyType::AncientZombie].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AncientZombieWalkDownLeft"));
		data[EnemyType::AncientZombie].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AncientZombieWalkUpLeft"));
		data[EnemyType::AncientZombie].speed = 0.9f;
		data[EnemyType::AncientZombie].healthPoints = 300;
		data[EnemyType::AncientZombie].gold = 30;
		data[EnemyType::AncientZombie].experiencePoints = 30;

		data[EnemyType::DireGhostWolf].texture = TextureID::CemeteryLevel;
		data[EnemyType::DireGhostWolf].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DireGhostWolfWalkUpRight"));
		data[EnemyType::DireGhostWolf].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DireGhostWolfWalkDownRight"));
		data[EnemyType::DireGhostWolf].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DireGhostWolfWalkDownLeft"));
		data[EnemyType::DireGhostWolf].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DireGhostWolfWalkUpLeft"));
		data[EnemyType::DireGhostWolf].speed = 0.3f;
		data[EnemyType::DireGhostWolf].healthPoints = 300;
		data[EnemyType::DireGhostWolf].gold = 30;
		data[EnemyType::DireGhostWolf].experiencePoints = 30;

		data[EnemyType::DireZombieDog].texture = TextureID::CemeteryLevel;
		data[EnemyType::DireZombieDog].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DireZombieDogWalkUpRight"));
		data[EnemyType::DireZombieDog].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DireZombieDogWalkDownRight"));
		data[EnemyType::DireZombieDog].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DireZombieDogWalkDownLeft"));
		data[EnemyType::DireZombieDog].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DireZombieDogWalkUpLeft"));
		data[EnemyType::DireZombieDog].speed = 0.4f;
		data[EnemyType::DireZombieDog].healthPoints = 180;
		data[EnemyType::DireZombieDog].gold = 18;
		data[EnemyType::DireZombieDog].experiencePoints = 18;

		data[EnemyType::GhostDog].texture = TextureID::CemeteryLevel;
		data[EnemyType::GhostDog].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GhostDogWalkUpRight"));
		data[EnemyType::GhostDog].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GhostDogWalkDownRight"));
		data[EnemyType::GhostDog].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GhostDogWalkDownLeft"));
		data[EnemyType::GhostDog].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GhostDogWalkUpLeft"));
		data[EnemyType::GhostDog].speed = 0.4f;
		data[EnemyType::GhostDog].healthPoints = 60;
		data[EnemyType::GhostDog].gold = 6;
		data[EnemyType::GhostDog].experiencePoints = 6;

		data[EnemyType::GhostWolf].texture = TextureID::CemeteryLevel;
		data[EnemyType::GhostWolf].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GhostWolfWalkUpRight"));
		data[EnemyType::GhostWolf].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GhostWolfWalkDownRight"));
		data[EnemyType::GhostWolf].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GhostWolfWalkDownLeft"));
		data[EnemyType::GhostWolf].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GhostWolfWalkUpLeft"));
		data[EnemyType::GhostWolf].speed = 0.3f;
		data[EnemyType::GhostWolf].healthPoints = 140;
		data[EnemyType::GhostWolf].gold = 14;
		data[EnemyType::GhostWolf].experiencePoints = 14;

		data[EnemyType::LichKing].texture = TextureID::CemeteryLevel;
		data[EnemyType::LichKing].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("LichKingWalkUpRight"));
		data[EnemyType::LichKing].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("LichKingWalkDownRight"));
		data[EnemyType::LichKing].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("LichKingWalkDownLeft"));
		data[EnemyType::LichKing].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("LichKingWalkUpLeft"));
		data[EnemyType::LichKing].speed = 0.6f;
		data[EnemyType::LichKing].healthPoints = 3000;
		data[EnemyType::LichKing].gold = 300;
		data[EnemyType::LichKing].experiencePoints = 300;

		data[EnemyType::LichLord].texture = TextureID::CemeteryLevel;
		data[EnemyType::LichLord].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("LichLordWalkUpRight"));
		data[EnemyType::LichLord].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("LichLordWalkDownRight"));
		data[EnemyType::LichLord].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("LichLordWalkDownLeft"));
		data[EnemyType::LichLord].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("LichLordWalkUpLeft"));
		data[EnemyType::LichLord].speed = 0.7f;
		data[EnemyType::LichLord].healthPoints = 300;
		data[EnemyType::LichLord].gold = 30;
		data[EnemyType::LichLord].experiencePoints = 30;

		data[EnemyType::Lich].texture = TextureID::CemeteryLevel;
		data[EnemyType::Lich].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("LichWalkUpRight"));
		data[EnemyType::Lich].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("LichWalkDownRight"));
		data[EnemyType::Lich].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("LichWalkDownLeft"));
		data[EnemyType::Lich].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("LichWalkUpLeft"));
		data[EnemyType::Lich].speed = 0.7f;
		data[EnemyType::Lich].healthPoints = 100;
		data[EnemyType::Lich].gold = 10;
		data[EnemyType::Lich].experiencePoints = 10;

		data[EnemyType::Skeleton].texture = TextureID::CemeteryLevel;
		data[EnemyType::Skeleton].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SkeletonWalkUpRight"));
		data[EnemyType::Skeleton].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SkeletonWalkDownRight"));
		data[EnemyType::Skeleton].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SkeletonWalkDownLeft"));
		data[EnemyType::Skeleton].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SkeletonWalkUpLeft"));
		data[EnemyType::Skeleton].speed = 0.5f;
		data[EnemyType::Skeleton].healthPoints = 80;
		data[EnemyType::Skeleton].gold = 8;
		data[EnemyType::Skeleton].experiencePoints = 8;

		data[EnemyType::ZombieDog].texture = TextureID::CemeteryLevel;
		data[EnemyType::ZombieDog].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ZombieDogWalkUpRight"));
		data[EnemyType::ZombieDog].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ZombieDogWalkDownRight"));
		data[EnemyType::ZombieDog].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ZombieDogWalkDownLeft"));
		data[EnemyType::ZombieDog].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ZombieDogWalkUpLeft"));
		data[EnemyType::ZombieDog].speed = 0.6f;
		data[EnemyType::ZombieDog].healthPoints = 25;
		data[EnemyType::ZombieDog].gold = 3;
		data[EnemyType::ZombieDog].experiencePoints = 3;

		data[EnemyType::Zombie].texture = TextureID::CemeteryLevel;
		data[EnemyType::Zombie].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ZombieWalkUpRight"));
		data[EnemyType::Zombie].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ZombieWalkDownRight"));
		data[EnemyType::Zombie].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ZombieWalkDownLeft"));
		data[EnemyType::Zombie].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ZombieWalkUpLeft"));
		data[EnemyType::Zombie].speed = 0.8f;
		data[EnemyType::Zombie].healthPoints = 40;
		data[EnemyType::Zombie].gold = 4;
		data[EnemyType::Zombie].experiencePoints = 4;

		frames = JsonFrameParser("../Media/Textures/BeachLeveLFlipped.json");

		data[EnemyType::AncientDrowned].texture = TextureID::BeachLevel;
		data[EnemyType::AncientDrowned].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AncientDrownedWalkUpRight"));
		data[EnemyType::AncientDrowned].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AncientDrownedWalkDownRight"));
		data[EnemyType::AncientDrowned].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AncientDrownedWalkDownLeft"));
		data[EnemyType::AncientDrowned].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AncientDrownedWalkUpLeft"));
		data[EnemyType::AncientDrowned].speed = 0.9f;
		data[EnemyType::AncientDrowned].healthPoints = 400;
		data[EnemyType::AncientDrowned].gold = 40;
		data[EnemyType::AncientDrowned].experiencePoints = 40;

		data[EnemyType::DeepSeaScorpion].texture = TextureID::BeachLevel;
		data[EnemyType::DeepSeaScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DeepSeaScorpionWalkUpRight"));
		data[EnemyType::DeepSeaScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DeepSeaScorpionWalkDownRight"));
		data[EnemyType::DeepSeaScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DeepSeaScorpionWalkDownLeft"));
		data[EnemyType::DeepSeaScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DeepSeaScorpionWalkUpLeft"));
		data[EnemyType::DeepSeaScorpion].speed = 0.7f;
		data[EnemyType::DeepSeaScorpion].healthPoints = 300;
		data[EnemyType::DeepSeaScorpion].gold = 30;
		data[EnemyType::DeepSeaScorpion].experiencePoints = 30;

		data[EnemyType::DrownedBones].texture = TextureID::BeachLevel;
		data[EnemyType::DrownedBones].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DrownedBonesWalkUpRight"));
		data[EnemyType::DrownedBones].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DrownedBonesWalkDownRight"));
		data[EnemyType::DrownedBones].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DrownedBonesWalkDownLeft"));
		data[EnemyType::DrownedBones].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DrownedBonesWalkUpLeft"));
		data[EnemyType::DrownedBones].speed = 0.6f;
		data[EnemyType::DrownedBones].healthPoints = 250;
		data[EnemyType::DrownedBones].gold = 25;
		data[EnemyType::DrownedBones].experiencePoints = 25;

		data[EnemyType::DrownedLich].texture = TextureID::BeachLevel;
		data[EnemyType::DrownedLich].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DrownedLichWalkUpRight"));
		data[EnemyType::DrownedLich].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DrownedLichWalkDownRight"));
		data[EnemyType::DrownedLich].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DrownedLichWalkDownLeft"));
		data[EnemyType::DrownedLich].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DrownedLichWalkUpLeft"));
		data[EnemyType::DrownedLich].speed = 0.8f;
		data[EnemyType::DrownedLich].healthPoints = 1000;
		data[EnemyType::DrownedLich].gold = 100;
		data[EnemyType::DrownedLich].experiencePoints = 100;

		data[EnemyType::Drowned].texture = TextureID::BeachLevel;
		data[EnemyType::Drowned].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("DrownedWalkUpRight"));
		data[EnemyType::Drowned].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("DrownedWalkDownRight"));
		data[EnemyType::Drowned].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("DrownedWalkDownLeft"));
		data[EnemyType::Drowned].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("DrownedWalkUpLeft"));
		data[EnemyType::Drowned].speed = 0.9f;
		data[EnemyType::Drowned].healthPoints = 200;
		data[EnemyType::Drowned].gold = 20;
		data[EnemyType::Drowned].experiencePoints = 20;

		data[EnemyType::FishmanElite].texture = TextureID::BeachLevel;
		data[EnemyType::FishmanElite].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FishmanEliteWalkUpRight"));
		data[EnemyType::FishmanElite].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FishmanEliteWalkDownRight"));
		data[EnemyType::FishmanElite].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FishmanEliteWalkDownLeft"));
		data[EnemyType::FishmanElite].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FishmanEliteWalkUpLeft"));
		data[EnemyType::FishmanElite].speed = 0.4f;
		data[EnemyType::FishmanElite].healthPoints = 140;
		data[EnemyType::FishmanElite].gold = 14;
		data[EnemyType::FishmanElite].experiencePoints = 14;

		data[EnemyType::Fishman].texture = TextureID::BeachLevel;
		data[EnemyType::Fishman].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FishmanWalkUpRight"));
		data[EnemyType::Fishman].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FishmanWalkDownRight"));
		data[EnemyType::Fishman].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FishmanWalkDownLeft"));
		data[EnemyType::Fishman].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FishmanWalkUpLeft"));
		data[EnemyType::Fishman].speed = 0.5f;
		data[EnemyType::Fishman].healthPoints = 40;
		data[EnemyType::Fishman].gold = 4;
		data[EnemyType::Fishman].experiencePoints = 4;

		data[EnemyType::GhostPirateCaptain].texture = TextureID::BeachLevel;
		data[EnemyType::GhostPirateCaptain].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GhostPirateCaptainWalkUpRight"));
		data[EnemyType::GhostPirateCaptain].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GhostPirateCaptainWalkDownRight"));
		data[EnemyType::GhostPirateCaptain].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GhostPirateCaptainWalkDownLeft"));
		data[EnemyType::GhostPirateCaptain].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GhostPirateCaptainWalkUpLeft"));
		data[EnemyType::GhostPirateCaptain].speed = 0.7f;
		data[EnemyType::GhostPirateCaptain].healthPoints = 4000;
		data[EnemyType::GhostPirateCaptain].gold = 400;
		data[EnemyType::GhostPirateCaptain].experiencePoints = 400;

		data[EnemyType::GhostPirate].texture = TextureID::BeachLevel;
		data[EnemyType::GhostPirate].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("GhostPirateWalkUpRight"));
		data[EnemyType::GhostPirate].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("GhostPirateWalkDownRight"));
		data[EnemyType::GhostPirate].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("GhostPirateWalkDownLeft"));
		data[EnemyType::GhostPirate].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("GhostPirateWalkUpLeft"));
		data[EnemyType::GhostPirate].speed = 0.6f;
		data[EnemyType::GhostPirate].healthPoints = 350;
		data[EnemyType::GhostPirate].gold = 35;
		data[EnemyType::GhostPirate].experiencePoints = 35;

		data[EnemyType::OrcPirateCaptain].texture = TextureID::BeachLevel;
		data[EnemyType::OrcPirateCaptain].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcPirateCaptainWalkUpRight"));
		data[EnemyType::OrcPirateCaptain].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcPirateCaptainWalkDownRight"));
		data[EnemyType::OrcPirateCaptain].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcPirateCaptainWalkDownLeft"));
		data[EnemyType::OrcPirateCaptain].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcPirateCaptainWalkUpLeft"));
		data[EnemyType::OrcPirateCaptain].speed = 0.5f;
		data[EnemyType::OrcPirateCaptain].healthPoints = 2000;
		data[EnemyType::OrcPirateCaptain].gold = 200;
		data[EnemyType::OrcPirateCaptain].experiencePoints = 200;

		data[EnemyType::OrcPirate].texture = TextureID::BeachLevel;
		data[EnemyType::OrcPirate].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("OrcPirateWalkUpRight"));
		data[EnemyType::OrcPirate].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("OrcPirateWalkDownRight"));
		data[EnemyType::OrcPirate].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("OrcPirateWalkDownLeft"));
		data[EnemyType::OrcPirate].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("OrcPirateWalkUpLeft"));
		data[EnemyType::OrcPirate].speed = 0.4f;
		data[EnemyType::OrcPirate].healthPoints = 100;
		data[EnemyType::OrcPirate].gold = 10;
		data[EnemyType::OrcPirate].experiencePoints = 10;

		data[EnemyType::SeaDog].texture = TextureID::BeachLevel;
		data[EnemyType::SeaDog].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SeaDogWalkUpRight"));
		data[EnemyType::SeaDog].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SeaDogWalkDownRight"));
		data[EnemyType::SeaDog].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SeaDogWalkDownLeft"));
		data[EnemyType::SeaDog].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SeaDogWalkUpLeft"));
		data[EnemyType::SeaDog].speed = 0.4f;
		data[EnemyType::SeaDog].healthPoints = 60;
		data[EnemyType::SeaDog].gold = 6;
		data[EnemyType::SeaDog].experiencePoints = 6;

		data[EnemyType::SeaScorpion].texture = TextureID::BeachLevel;
		data[EnemyType::SeaScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SeaScorpionWalkUpRight"));
		data[EnemyType::SeaScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SeaScorpionWalkDownRight"));
		data[EnemyType::SeaScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SeaScorpionWalkDownLeft"));
		data[EnemyType::SeaScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SeaScorpionWalkUpLeft"));
		data[EnemyType::SeaScorpion].speed = 0.6f;
		data[EnemyType::SeaScorpion].healthPoints = 60;
		data[EnemyType::SeaScorpion].gold = 6;
		data[EnemyType::SeaScorpion].experiencePoints = 6;

		data[EnemyType::ZombiePirate].texture = TextureID::BeachLevel;
		data[EnemyType::ZombiePirate].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ZombiePirateWalkUpRight"));
		data[EnemyType::ZombiePirate].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ZombiePirateWalkDownRight"));
		data[EnemyType::ZombiePirate].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ZombiePirateWalkDownLeft"));
		data[EnemyType::ZombiePirate].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ZombiePirateWalkUpLeft"));
		data[EnemyType::ZombiePirate].speed = 0.8f;
		data[EnemyType::ZombiePirate].healthPoints = 240;
		data[EnemyType::ZombiePirate].gold = 24;
		data[EnemyType::ZombiePirate].experiencePoints = 24;

		frames = JsonFrameParser("../Media/Textures/MountainLeveLFlipped.json");

		data[EnemyType::AncientMedusa].texture = TextureID::MountainLevel;
		data[EnemyType::AncientMedusa].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AncientMedusaWalkUpRight"));
		data[EnemyType::AncientMedusa].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AncientMedusaWalkDownRight"));
		data[EnemyType::AncientMedusa].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AncientMedusaWalkDownLeft"));
		data[EnemyType::AncientMedusa].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AncientMedusaWalkUpLeft"));
		data[EnemyType::AncientMedusa].speed = 0.4f;
		data[EnemyType::AncientMedusa].healthPoints = 200;
		data[EnemyType::AncientMedusa].gold = 20;
		data[EnemyType::AncientMedusa].experiencePoints = 20;

		data[EnemyType::CharredBones].texture = TextureID::MountainLevel;
		data[EnemyType::CharredBones].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("CharredBonesWalkUpRight"));
		data[EnemyType::CharredBones].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("CharredBonesWalkDownRight"));
		data[EnemyType::CharredBones].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("CharredBonesWalkDownLeft"));
		data[EnemyType::CharredBones].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("CharredBonesWalkUpLeft"));
		data[EnemyType::CharredBones].speed = 0.5f;
		data[EnemyType::CharredBones].healthPoints = 400;
		data[EnemyType::CharredBones].gold = 40;
		data[EnemyType::CharredBones].experiencePoints = 40;

		data[EnemyType::Charred].texture = TextureID::MountainLevel;
		data[EnemyType::Charred].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("CharredWalkUpRight"));
		data[EnemyType::Charred].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("CharredWalkDownRight"));
		data[EnemyType::Charred].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("CharredWalkDownLeft"));
		data[EnemyType::Charred].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("CharredWalkUpLeft"));
		data[EnemyType::Charred].speed = 0.8f;
		data[EnemyType::Charred].healthPoints = 400;
		data[EnemyType::Charred].gold = 40;
		data[EnemyType::Charred].experiencePoints = 40;

		data[EnemyType::FireGiant].texture = TextureID::MountainLevel;
		data[EnemyType::FireGiant].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireGiantWalkUpRight"));
		data[EnemyType::FireGiant].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireGiantWalkDownRight"));
		data[EnemyType::FireGiant].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireGiantWalkDownLeft"));
		data[EnemyType::FireGiant].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireGiantWalkUpLeft"));
		data[EnemyType::FireGiant].speed = 0.8f;
		data[EnemyType::FireGiant].healthPoints = 1000;
		data[EnemyType::FireGiant].gold = 100;
		data[EnemyType::FireGiant].experiencePoints = 100;

		data[EnemyType::FireLich].texture = TextureID::MountainLevel;
		data[EnemyType::FireLich].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireLichWalkUpRight"));
		data[EnemyType::FireLich].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireLichWalkDownRight"));
		data[EnemyType::FireLich].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireLichWalkDownLeft"));
		data[EnemyType::FireLich].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireLichWalkUpLeft"));
		data[EnemyType::FireLich].speed = 0.7f;
		data[EnemyType::FireLich].healthPoints = 400;
		data[EnemyType::FireLich].gold = 40;
		data[EnemyType::FireLich].experiencePoints = 40;

		data[EnemyType::FireMedusa].texture = TextureID::MountainLevel;
		data[EnemyType::FireMedusa].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireMedusaWalkUpRight"));
		data[EnemyType::FireMedusa].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireMedusaWalkDownRight"));
		data[EnemyType::FireMedusa].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireMedusaWalkDownLeft"));
		data[EnemyType::FireMedusa].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireMedusaWalkUpLeft"));
		data[EnemyType::FireMedusa].speed = 0.4f;
		data[EnemyType::FireMedusa].healthPoints = 250;
		data[EnemyType::FireMedusa].gold = 25;
		data[EnemyType::FireMedusa].experiencePoints = 25;

		data[EnemyType::FireScorpion].texture = TextureID::MountainLevel;
		data[EnemyType::FireScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireScorpionWalkUpRight"));
		data[EnemyType::FireScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireScorpionWalkDownRight"));
		data[EnemyType::FireScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireScorpionWalkDownLeft"));
		data[EnemyType::FireScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireScorpionWalkUpLeft"));
		data[EnemyType::FireScorpion].speed = 0.5f;
		data[EnemyType::FireScorpion].healthPoints = 220;
		data[EnemyType::FireScorpion].gold = 22;
		data[EnemyType::FireScorpion].experiencePoints = 22;

		data[EnemyType::HellHound].texture = TextureID::MountainLevel;
		data[EnemyType::HellHound].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("HellHoundWalkUpRight"));
		data[EnemyType::HellHound].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("HellHoundWalkDownRight"));
		data[EnemyType::HellHound].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("HellHoundWalkDownLeft"));
		data[EnemyType::HellHound].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("HellHoundWalkUpLeft"));
		data[EnemyType::HellHound].speed = 0.5f;
		data[EnemyType::HellHound].healthPoints = 150;
		data[EnemyType::HellHound].gold = 15;
		data[EnemyType::HellHound].experiencePoints = 15;

		data[EnemyType::HobgoblinHeavyInfantry].texture = TextureID::MountainLevel;
		data[EnemyType::HobgoblinHeavyInfantry].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("HobgoblinHeavyInfantryWalkUpRight"));
		data[EnemyType::HobgoblinHeavyInfantry].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("HobgoblinHeavyInfantryWalkDownRight"));
		data[EnemyType::HobgoblinHeavyInfantry].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("HobgoblinHeavyInfantryWalkDownLeft"));
		data[EnemyType::HobgoblinHeavyInfantry].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("HobgoblinHeavyInfantryWalkUpLeft"));
		data[EnemyType::HobgoblinHeavyInfantry].speed = 0.7f;
		data[EnemyType::HobgoblinHeavyInfantry].healthPoints = 300;
		data[EnemyType::HobgoblinHeavyInfantry].gold = 30;
		data[EnemyType::HobgoblinHeavyInfantry].experiencePoints = 30;

		data[EnemyType::HobgoblinScout].texture = TextureID::MountainLevel;
		data[EnemyType::HobgoblinScout].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("HobgoblinScoutWalkUpRight"));
		data[EnemyType::HobgoblinScout].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("HobgoblinScoutWalkDownRight"));
		data[EnemyType::HobgoblinScout].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("HobgoblinScoutWalkDownLeft"));
		data[EnemyType::HobgoblinScout].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("HobgoblinScoutWalkUpLeft"));
		data[EnemyType::HobgoblinScout].speed = 0.5f;
		data[EnemyType::HobgoblinScout].healthPoints = 45;
		data[EnemyType::HobgoblinScout].gold = 5;
		data[EnemyType::HobgoblinScout].experiencePoints = 5;

		data[EnemyType::HobgoblinWarrior].texture = TextureID::MountainLevel;
		data[EnemyType::HobgoblinWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("HobgoblinWarriorWalkUpRight"));
		data[EnemyType::HobgoblinWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("HobgoblinWarriorWalkDownRight"));
		data[EnemyType::HobgoblinWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("HobgoblinWarriorWalkDownLeft"));
		data[EnemyType::HobgoblinWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("HobgoblinWarriorWalkUpLeft"));
		data[EnemyType::HobgoblinWarrior].speed = 0.6f;
		data[EnemyType::HobgoblinWarrior].healthPoints = 100;
		data[EnemyType::HobgoblinWarrior].gold = 10;
		data[EnemyType::HobgoblinWarrior].experiencePoints = 10;

		data[EnemyType::MagmaKing].texture = TextureID::MountainLevel;
		data[EnemyType::MagmaKing].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MagmaKingWalkUpRight"));
		data[EnemyType::MagmaKing].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MagmaKingWalkDownRight"));
		data[EnemyType::MagmaKing].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MagmaKingWalkDownLeft"));
		data[EnemyType::MagmaKing].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MagmaKingWalkUpLeft"));
		data[EnemyType::MagmaKing].speed = 1.0;
		data[EnemyType::MagmaKing].healthPoints = 6000;
		data[EnemyType::MagmaKing].gold = 600;
		data[EnemyType::MagmaKing].experiencePoints = 600;

		data[EnemyType::MagmaScorpion].texture = TextureID::MountainLevel;
		data[EnemyType::MagmaScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MagmaScorpionWalkUpRight"));
		data[EnemyType::MagmaScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MagmaScorpionWalkDownRight"));
		data[EnemyType::MagmaScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MagmaScorpionWalkDownLeft"));
		data[EnemyType::MagmaScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MagmaScorpionWalkUpLeft"));
		data[EnemyType::MagmaScorpion].speed = 0.8f;
		data[EnemyType::MagmaScorpion].healthPoints = 600;
		data[EnemyType::MagmaScorpion].gold = 60;
		data[EnemyType::MagmaScorpion].experiencePoints = 60;

		data[EnemyType::Medusa].texture = TextureID::MountainLevel;
		data[EnemyType::Medusa].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MedusaWalkUpRight"));
		data[EnemyType::Medusa].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MedusaWalkDownRight"));
		data[EnemyType::Medusa].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MedusaWalkDownLeft"));
		data[EnemyType::Medusa].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MedusaWalkUpLeft"));
		data[EnemyType::Medusa].speed = 0.4f;
		data[EnemyType::Medusa].healthPoints = 60;
		data[EnemyType::Medusa].gold = 6;
		data[EnemyType::Medusa].experiencePoints = 6;

		data[EnemyType::MountainGiant].texture = TextureID::MountainLevel;
		data[EnemyType::MountainGiant].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MountainGiantWalkUpRight"));
		data[EnemyType::MountainGiant].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MountainGiantWalkDownRight"));
		data[EnemyType::MountainGiant].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MountainGiantWalkDownLeft"));
		data[EnemyType::MountainGiant].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MountainGiantWalkUpLeft"));
		data[EnemyType::MountainGiant].speed = 0.7f;
		data[EnemyType::MountainGiant].healthPoints = 300;
		data[EnemyType::MountainGiant].gold = 30;
		data[EnemyType::MountainGiant].experiencePoints = 30;

		data[EnemyType::RockScorpion].texture = TextureID::MountainLevel;
		data[EnemyType::RockScorpion].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("RockScorpionWalkUpRight"));
		data[EnemyType::RockScorpion].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("RockScorpionWalkDownRight"));
		data[EnemyType::RockScorpion].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("RockScorpionWalkDownLeft"));
		data[EnemyType::RockScorpion].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("RockScorpionWalkUpLeft"));
		data[EnemyType::RockScorpion].speed = 0.6f;
		data[EnemyType::RockScorpion].healthPoints = 35;
		data[EnemyType::RockScorpion].gold = 4;
		data[EnemyType::RockScorpion].experiencePoints = 4;

		json j(data);
		std::ofstream o("../Media/Textures/EnemyData.json");
		o << std::setw(2) << j << std::endl;
	}
	else
	{
		json json_;
		json_ = json::parse(ifs);
		data = json_.get<std::map<EnemyType, EnemyData>>();

	}

	return data;
}



std::map<TowerType, TowerData> initializeTowerData()
{
	std::map<TowerType, TowerData> data;

	std::ifstream ifs("../Media/Textures/TowerData.json");


	if (ifs.fail())
	{
		auto frames{ JsonFrameParser("../Media/Textures/TowerAtlasFlipped.json") };

		data[TowerType::ClubWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpUp"));
		data[TowerType::ClubWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpRight"));
		data[TowerType::ClubWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("ClubWarriorAttackRight"));
		data[TowerType::ClubWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownRight"));
		data[TowerType::ClubWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownDown"));
		data[TowerType::ClubWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownLeft"));
		data[TowerType::ClubWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("ClubWarriorAttackLeft"));
		data[TowerType::ClubWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpLeft"));
		data[TowerType::ClubWarrior].range = 1;
		data[TowerType::ClubWarrior].swingSpeed = 1.0f;
		data[TowerType::ClubWarrior].cooldown = 1.0f;
		data[TowerType::ClubWarrior].projectileType = ProjectileType::None;
		data[TowerType::ClubWarrior].attackEffect = AttackEffect::None;
		data[TowerType::ClubWarrior].damage = 15;
		data[TowerType::ClubWarrior].experienceToNextLevel = 10;

		data[TowerType::SwordWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpUp"));
		data[TowerType::SwordWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpRight"));
		data[TowerType::SwordWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordWarriorAttackRight"));
		data[TowerType::SwordWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownRight"));
		data[TowerType::SwordWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownDown"));
		data[TowerType::SwordWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownLeft"));
		data[TowerType::SwordWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordWarriorAttackLeft"));
		data[TowerType::SwordWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpLeft"));
		data[TowerType::SwordWarrior].range = 1;
		data[TowerType::SwordWarrior].swingSpeed = 1.0f;
		data[TowerType::SwordWarrior].cooldown = 0.3f;
		data[TowerType::SwordWarrior].projectileType = ProjectileType::None;
		data[TowerType::SwordWarrior].attackEffect = AttackEffect::None;
		data[TowerType::SwordWarrior].damage = 30;
		data[TowerType::SwordWarrior].experienceToNextLevel = 20;

		data[TowerType::SwordMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordMasterAttackUpUp"));
		data[TowerType::SwordMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordMasterAttackUpRight"));
		data[TowerType::SwordMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordMasterAttackRight"));
		data[TowerType::SwordMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordMasterAttackDownRight"));
		data[TowerType::SwordMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordMasterAttackDownDown"));
		data[TowerType::SwordMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordMasterAttackDownLeft"));
		data[TowerType::SwordMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordMasterAttackLeft"));
		data[TowerType::SwordMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordMasterAttackUpLeft"));
		data[TowerType::SwordMaster].range = 1;
		data[TowerType::SwordMaster].swingSpeed = 1.0f;
		data[TowerType::SwordMaster].cooldown = 0.3f;
		data[TowerType::SwordMaster].projectileType = ProjectileType::None;
		data[TowerType::SwordMaster].attackEffect = AttackEffect::None;
		data[TowerType::SwordMaster].damage = 60;
		data[TowerType::SwordMaster].experienceToNextLevel = 40;

		data[TowerType::SwordGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpUp"));
		data[TowerType::SwordGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownDown"));
		data[TowerType::SwordGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownLeft"));
		data[TowerType::SwordGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackLeftLeft"));
		data[TowerType::SwordGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpLeft"));
		data[TowerType::SwordGrandmaster].range = 1;
		data[TowerType::SwordGrandmaster].swingSpeed = 1.0f;
		data[TowerType::SwordGrandmaster].cooldown = 0.3f;
		data[TowerType::SwordGrandmaster].projectileType = ProjectileType::None;
		data[TowerType::SwordGrandmaster].attackEffect = AttackEffect::None;
		data[TowerType::SwordGrandmaster].damage = 100;
		data[TowerType::SwordGrandmaster].experienceToNextLevel = 0;

		data[TowerType::AxeWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpUp"));
		data[TowerType::AxeWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpRight"));
		data[TowerType::AxeWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeWarriorAttackRight"));
		data[TowerType::AxeWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownRight"));
		data[TowerType::AxeWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownDown"));
		data[TowerType::AxeWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownLeft"));
		data[TowerType::AxeWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeWarriorAttackLeft"));
		data[TowerType::AxeWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpLeft"));
		data[TowerType::AxeWarrior].range = 1;
		data[TowerType::AxeWarrior].swingSpeed = 1.0f;
		data[TowerType::AxeWarrior].cooldown = 1.0f;
		data[TowerType::AxeWarrior].projectileType = ProjectileType::None;
		data[TowerType::AxeWarrior].attackEffect = AttackEffect::Area;
		data[TowerType::AxeWarrior].damage = 30;
		data[TowerType::AxeWarrior].experienceToNextLevel = 20;

		data[TowerType::AxeMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeMasterAttackUpUp"));
		data[TowerType::AxeMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeMasterAttackUpRight"));
		data[TowerType::AxeMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeMasterAttackRight"));
		data[TowerType::AxeMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeMasterAttackDownRight"));
		data[TowerType::AxeMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeMasterAttackDownDown"));
		data[TowerType::AxeMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeMasterAttackDownLeft"));
		data[TowerType::AxeMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeMasterAttackLeft"));
		data[TowerType::AxeMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeMasterAttackUpLeft"));
		data[TowerType::AxeMaster].attackEffect = AttackEffect::Area;
		data[TowerType::AxeMaster].range = 1;
		data[TowerType::AxeMaster].swingSpeed = 1.0f;
		data[TowerType::AxeMaster].cooldown = 1.0f;
		data[TowerType::AxeMaster].projectileType = ProjectileType::None;
		data[TowerType::AxeMaster].attackEffect = AttackEffect::Area;
		data[TowerType::AxeMaster].damage = 60;
		data[TowerType::AxeMaster].experienceToNextLevel = 40;

		data[TowerType::AxeGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpUp"));
		data[TowerType::AxeGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownDown"));
		data[TowerType::AxeGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownLeft"));
		data[TowerType::AxeGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackLeft"));
		data[TowerType::AxeGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpLeft"));
		data[TowerType::AxeGrandmaster].attackEffect = AttackEffect::Area;
		data[TowerType::AxeGrandmaster].range = 1;
		data[TowerType::AxeGrandmaster].swingSpeed = 1.0f;
		data[TowerType::AxeGrandmaster].cooldown = 1.0f;
		data[TowerType::AxeGrandmaster].projectileType = ProjectileType::None;
		data[TowerType::AxeGrandmaster].attackEffect = AttackEffect::BigArea;
		data[TowerType::AxeGrandmaster].damage = 100;
		data[TowerType::AxeGrandmaster].experienceToNextLevel = 0;

		data[TowerType::MaceWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpUp"));
		data[TowerType::MaceWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpRight"));
		data[TowerType::MaceWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceWarriorAttackRight"));
		data[TowerType::MaceWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownRight"));
		data[TowerType::MaceWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownDown"));
		data[TowerType::MaceWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownLeft"));
		data[TowerType::MaceWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceWarriorAttackLeft"));
		data[TowerType::MaceWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpLeft"));
		data[TowerType::MaceWarrior].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceWarrior].range = 1;
		data[TowerType::MaceWarrior].swingSpeed = 1.0f;
		data[TowerType::MaceWarrior].cooldown = 1.0f;
		data[TowerType::MaceWarrior].projectileType = ProjectileType::None;
		data[TowerType::MaceWarrior].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceWarrior].damage = 45;
		data[TowerType::MaceWarrior].experienceToNextLevel = 20;

		data[TowerType::MaceMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceMasterAttackUpUp"));
		data[TowerType::MaceMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceMasterAttackUpRight"));
		data[TowerType::MaceMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceMasterAttackRight"));
		data[TowerType::MaceMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceMasterAttackDownRight"));
		data[TowerType::MaceMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceMasterAttackDownDown"));
		data[TowerType::MaceMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceMasterAttackDownLeft"));
		data[TowerType::MaceMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceMasterAttackLeft"));
		data[TowerType::MaceMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceMasterAttackUpLeft"));
		data[TowerType::MaceMaster].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceMaster].range = 1;
		data[TowerType::MaceMaster].swingSpeed = 1.0f;
		data[TowerType::MaceMaster].cooldown = 1.0f;
		data[TowerType::MaceMaster].projectileType = ProjectileType::None;
		data[TowerType::MaceMaster].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceMaster].damage = 90;
		data[TowerType::MaceMaster].experienceToNextLevel = 40;

		data[TowerType::MaceGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpUp"));
		data[TowerType::MaceGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownDown"));
		data[TowerType::MaceGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownLeft"));
		data[TowerType::MaceGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackLeft"));
		data[TowerType::MaceGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpLeft"));
		data[TowerType::MaceGrandmaster].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceGrandmaster].range = 1;
		data[TowerType::MaceGrandmaster].swingSpeed = 1.0f;
		data[TowerType::MaceGrandmaster].cooldown = 1.0f;
		data[TowerType::MaceGrandmaster].projectileType = ProjectileType::None;
		data[TowerType::MaceGrandmaster].attackEffect = AttackEffect::Stun;
		data[TowerType::MaceGrandmaster].damage = 180;
		data[TowerType::MaceGrandmaster].experienceToNextLevel = 0;

		data[TowerType::Novice].animations[Direction::Up].addFrameSet(frames.getFramesFor("NoviceAttackUpUp"));
		data[TowerType::Novice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("NoviceAttackUpRight"));
		data[TowerType::Novice].animations[Direction::Right].addFrameSet(frames.getFramesFor("NoviceAttackRight"));
		data[TowerType::Novice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("NoviceAttackDownRight"));
		data[TowerType::Novice].animations[Direction::Down].addFrameSet(frames.getFramesFor("NoviceAttackDownDown"));
		data[TowerType::Novice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("NoviceAttackDownLeft"));
		data[TowerType::Novice].animations[Direction::Left].addFrameSet(frames.getFramesFor("NoviceAttackLeft"));
		data[TowerType::Novice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("NoviceAttackUpLeft"));
		data[TowerType::Novice].range = 2;
		data[TowerType::Novice].swingSpeed = 1.0f;
		data[TowerType::Novice].cooldown = 2.0f;
		data[TowerType::Novice].projectileType = ProjectileType::MagicArrow;
		data[TowerType::Novice].attackEffect = AttackEffect::None;
		data[TowerType::Novice].damage = 10;
		data[TowerType::Novice].experienceToNextLevel = 10;

		data[TowerType::IceApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpUp"));
		data[TowerType::IceApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpRight"));
		data[TowerType::IceApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceApprenticeAttackRight"));
		data[TowerType::IceApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownRight"));
		data[TowerType::IceApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownDown"));
		data[TowerType::IceApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownLeft"));
		data[TowerType::IceApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceApprenticeAttackLeft"));
		data[TowerType::IceApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpLeft"));
		data[TowerType::IceApprentice].range = 2;
		data[TowerType::IceApprentice].swingSpeed = 1.0f;
		data[TowerType::IceApprentice].cooldown = 2.0f;
		data[TowerType::IceApprentice].projectileType = ProjectileType::IceBall;
		data[TowerType::IceApprentice].attackEffect = AttackEffect::Freeze;
		data[TowerType::IceApprentice].damage = 20;
		data[TowerType::IceApprentice].experienceToNextLevel = 20;

		data[TowerType::IceMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceMasterAttackUpUp"));
		data[TowerType::IceMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceMasterAttackUpRight"));
		data[TowerType::IceMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceMasterAttackRight"));
		data[TowerType::IceMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceMasterAttackDownRight"));
		data[TowerType::IceMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceMasterAttackDownDown"));
		data[TowerType::IceMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceMasterAttackDownLeft"));
		data[TowerType::IceMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceMasterAttackLeft"));
		data[TowerType::IceMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceMasterAttackUpLeft"));
		data[TowerType::IceMaster].range = 2;
		data[TowerType::IceMaster].swingSpeed = 1.0f;
		data[TowerType::IceMaster].cooldown = 2.0f;
		data[TowerType::IceMaster].projectileType = ProjectileType::IceBall;
		data[TowerType::IceMaster].attackEffect = AttackEffect::Freeze;
		data[TowerType::IceMaster].damage = 40;
		data[TowerType::IceMaster].experienceToNextLevel = 40;

		data[TowerType::IceGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpUp"));
		data[TowerType::IceGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpRight"));
		data[TowerType::IceGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceGrandmasterAttackRight"));
		data[TowerType::IceGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownRight"));
		data[TowerType::IceGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownDown"));
		data[TowerType::IceGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownLeft"));
		data[TowerType::IceGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceGrandmasterAttackLeft"));
		data[TowerType::IceGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpLeft"));
		data[TowerType::IceGrandmaster].range = 2;
		data[TowerType::IceGrandmaster].swingSpeed = 1.0f;
		data[TowerType::IceGrandmaster].cooldown = 2.0f;
		data[TowerType::IceGrandmaster].projectileType = ProjectileType::IceBall;
		data[TowerType::IceGrandmaster].attackEffect = AttackEffect::DeepFreeze;
		data[TowerType::IceGrandmaster].damage = 80;
		data[TowerType::IceGrandmaster].experienceToNextLevel = 0;

		data[TowerType::FireApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpUp"));
		data[TowerType::FireApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpRight"));
		data[TowerType::FireApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireApprenticeAttackRight"));
		data[TowerType::FireApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownRight"));
		data[TowerType::FireApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownDown"));
		data[TowerType::FireApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownLeft"));
		data[TowerType::FireApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireApprenticeAttackLeft"));
		data[TowerType::FireApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpLeft"));
		data[TowerType::FireApprentice].range = 2;
		data[TowerType::FireApprentice].swingSpeed = 1.0f;
		data[TowerType::FireApprentice].cooldown = 2.0f;
		data[TowerType::FireApprentice].projectileType = ProjectileType::Fireball;
		data[TowerType::FireApprentice].attackEffect = AttackEffect::Area;
		data[TowerType::FireApprentice].damage = 20;
		data[TowerType::FireApprentice].experienceToNextLevel = 20;

		data[TowerType::FireMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireMasterAttackUpUp"));
		data[TowerType::FireMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireMasterAttackUpRight"));
		data[TowerType::FireMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireMasterAttackRight"));
		data[TowerType::FireMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireMasterAttackDownRight"));
		data[TowerType::FireMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireMasterAttackDownDown"));
		data[TowerType::FireMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireMasterAttackDownLeft"));
		data[TowerType::FireMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireMasterAttackLeft"));
		data[TowerType::FireMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireMasterAttackUpLeft"));
		data[TowerType::FireMaster].range = 2;
		data[TowerType::FireMaster].swingSpeed = 1.0f;
		data[TowerType::FireMaster].cooldown = 2.0f;
		data[TowerType::FireMaster].projectileType = ProjectileType::Fireball;
		data[TowerType::FireMaster].attackEffect = AttackEffect::Area;
		data[TowerType::FireMaster].damage = 40;
		data[TowerType::FireMaster].experienceToNextLevel = 40;

		data[TowerType::FireGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpUp"));
		data[TowerType::FireGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpRight"));
		data[TowerType::FireGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireGrandmasterAttackRight"));
		data[TowerType::FireGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownRight"));
		data[TowerType::FireGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownDown"));
		data[TowerType::FireGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownLeft"));
		data[TowerType::FireGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireGrandmasterAttackLeft"));
		data[TowerType::FireGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpLeft"));
		data[TowerType::FireGrandmaster].range = 2;
		data[TowerType::FireGrandmaster].swingSpeed = 1.0f;
		data[TowerType::FireGrandmaster].cooldown = 2.0f;
		data[TowerType::FireGrandmaster].projectileType = ProjectileType::Fireball;
		data[TowerType::FireGrandmaster].attackEffect = AttackEffect::BigArea;
		data[TowerType::FireGrandmaster].damage = 80;
		data[TowerType::FireGrandmaster].experienceToNextLevel = 0;

		data[TowerType::EnergyApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpUp"));
		data[TowerType::EnergyApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpRight"));
		data[TowerType::EnergyApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackRight"));
		data[TowerType::EnergyApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownRight"));
		data[TowerType::EnergyApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownDown"));
		data[TowerType::EnergyApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownLeft"));
		data[TowerType::EnergyApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackLeft"));
		data[TowerType::EnergyApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpLeft"));
		data[TowerType::EnergyApprentice].range = 3;
		data[TowerType::EnergyApprentice].swingSpeed = 1.0f;
		data[TowerType::EnergyApprentice].cooldown = 2.0f;
		data[TowerType::EnergyApprentice].projectileType = ProjectileType::Lightning;
		data[TowerType::EnergyApprentice].attackEffect = AttackEffect::None;
		data[TowerType::EnergyApprentice].damage = 20;
		data[TowerType::EnergyApprentice].experienceToNextLevel = 20;

		data[TowerType::EnergyMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpUp"));
		data[TowerType::EnergyMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpRight"));
		data[TowerType::EnergyMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMasterAttackRight"));
		data[TowerType::EnergyMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownRight"));
		data[TowerType::EnergyMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownDown"));
		data[TowerType::EnergyMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownLeft"));
		data[TowerType::EnergyMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMasterAttackLeft"));
		data[TowerType::EnergyMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpLeft"));
		data[TowerType::EnergyMaster].range = 3;
		data[TowerType::EnergyMaster].swingSpeed = 1.0f;
		data[TowerType::EnergyMaster].cooldown = 2.0f;
		data[TowerType::EnergyMaster].projectileType = ProjectileType::Lightning;
		data[TowerType::EnergyMaster].attackEffect = AttackEffect::None;
		data[TowerType::EnergyMaster].damage = 40;
		data[TowerType::EnergyMaster].experienceToNextLevel = 40;

		data[TowerType::EnergyGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpUp"));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownDown"));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownLeft"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackLeft"));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpLeft"));
		data[TowerType::EnergyGrandmaster].range = 3;
		data[TowerType::EnergyGrandmaster].swingSpeed = 1.0f;
		data[TowerType::EnergyGrandmaster].cooldown = 2.0f;
		data[TowerType::EnergyGrandmaster].projectileType = ProjectileType::Lightning;
		data[TowerType::EnergyGrandmaster].attackEffect = AttackEffect::Stun;
		data[TowerType::EnergyGrandmaster].damage = 80;
		data[TowerType::EnergyGrandmaster].experienceToNextLevel = 0;

		data[TowerType::PoisonApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpUp"));
		data[TowerType::PoisonApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpRight"));
		data[TowerType::PoisonApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackRight"));
		data[TowerType::PoisonApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownRight"));
		data[TowerType::PoisonApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownDown"));
		data[TowerType::PoisonApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownLeft"));
		data[TowerType::PoisonApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackLeft"));
		data[TowerType::PoisonApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpLeft"));
		data[TowerType::PoisonApprentice].range = 2;
		data[TowerType::PoisonApprentice].swingSpeed = 1.0f;
		data[TowerType::PoisonApprentice].cooldown = 2.0f;
		data[TowerType::PoisonApprentice].projectileType = ProjectileType::Poison;
		data[TowerType::PoisonApprentice].attackEffect = AttackEffect::Poison;
		data[TowerType::PoisonApprentice].damage = 20;
		data[TowerType::PoisonApprentice].experienceToNextLevel = 20;

		data[TowerType::PoisonMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpUp"));
		data[TowerType::PoisonMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpRight"));
		data[TowerType::PoisonMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonMasterAttackRight"));
		data[TowerType::PoisonMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownRight"));
		data[TowerType::PoisonMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownDown"));
		data[TowerType::PoisonMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownLeft"));
		data[TowerType::PoisonMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonMasterAttackLeft"));
		data[TowerType::PoisonMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpLeft"));
		data[TowerType::PoisonMaster].range = 2;
		data[TowerType::PoisonMaster].swingSpeed = 1.0f;
		data[TowerType::PoisonMaster].cooldown = 2.0f;
		data[TowerType::PoisonMaster].projectileType = ProjectileType::Poison;
		data[TowerType::PoisonMaster].attackEffect = AttackEffect::GreatPoison;
		data[TowerType::PoisonMaster].damage = 40;
		data[TowerType::PoisonMaster].experienceToNextLevel = 40;

		data[TowerType::PoisonGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpUp"));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownDown"));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownLeft"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackLeft"));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpLeft"));
		data[TowerType::PoisonGrandmaster].range = 2;
		data[TowerType::PoisonGrandmaster].swingSpeed = 1.0f;
		data[TowerType::PoisonGrandmaster].cooldown = 2.0f;
		data[TowerType::PoisonGrandmaster].projectileType = ProjectileType::Poison;
		data[TowerType::PoisonGrandmaster].attackEffect = AttackEffect::GreaterPoison;
		data[TowerType::PoisonGrandmaster].damage = 80;
		data[TowerType::PoisonGrandmaster].experienceToNextLevel = 0;

		data[TowerType::IceSword].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceSwordAttackUpUp"));
		data[TowerType::IceSword].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceSwordAttackUpRight"));
		data[TowerType::IceSword].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceSwordAttackRight"));
		data[TowerType::IceSword].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceSwordAttackDownRight"));
		data[TowerType::IceSword].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceSwordAttackDownDown"));
		data[TowerType::IceSword].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceSwordAttackDownLeft"));
		data[TowerType::IceSword].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceSwordAttackLeft"));
		data[TowerType::IceSword].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceSwordAttackUpLeft"));
		data[TowerType::IceSword].range = 1;
		data[TowerType::IceSword].swingSpeed = 1.0f;
		data[TowerType::IceSword].cooldown = 0.3f;
		data[TowerType::IceSword].projectileType = ProjectileType::IceBall;
		data[TowerType::IceSword].attackEffect = AttackEffect::Freeze;
		data[TowerType::IceSword].damage = 80;
		data[TowerType::IceSword].experienceToNextLevel = 60;

		data[TowerType::IceSword2].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceSword2AttackUpUp"));
		data[TowerType::IceSword2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceSword2AttackUpRight"));
		data[TowerType::IceSword2].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceSword2AttackRight"));
		data[TowerType::IceSword2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceSword2AttackDownRight"));
		data[TowerType::IceSword2].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceSword2AttackDownDown"));
		data[TowerType::IceSword2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceSword2AttackDownLeft"));
		data[TowerType::IceSword2].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceSword2AttackLeft"));
		data[TowerType::IceSword2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceSword2AttackUpLeft"));
		data[TowerType::IceSword2].range = 1;
		data[TowerType::IceSword2].swingSpeed = 1.0f;
		data[TowerType::IceSword2].cooldown = 0.3f;
		data[TowerType::IceSword2].projectileType = ProjectileType::IceBall;
		data[TowerType::IceSword2].attackEffect = AttackEffect::Freeze;
		data[TowerType::IceSword2].damage = 140;
		data[TowerType::IceSword2].experienceToNextLevel = 0;

		data[TowerType::FireAxe].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireAxeAttackUpUp"));
		data[TowerType::FireAxe].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireAxeAttackUpRight"));
		data[TowerType::FireAxe].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireAxeAttackRight"));
		data[TowerType::FireAxe].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireAxeAttackDownRight"));
		data[TowerType::FireAxe].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireAxeAttackDownDown"));
		data[TowerType::FireAxe].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireAxeAttackDownLeft"));
		data[TowerType::FireAxe].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireAxeAttackLeft"));
		data[TowerType::FireAxe].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireAxeAttackUpLeft"));
		data[TowerType::FireAxe].range = 1;
		data[TowerType::FireAxe].swingSpeed = 1.0f;
		data[TowerType::FireAxe].cooldown = 1.0f;
		data[TowerType::FireAxe].projectileType = ProjectileType::Fireball;
		data[TowerType::FireAxe].attackEffect = AttackEffect::BigArea;
		data[TowerType::FireAxe].damage = 80;
		data[TowerType::FireAxe].experienceToNextLevel = 60;

		data[TowerType::FireAxe2].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireAxe2AttackUpUp"));
		data[TowerType::FireAxe2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireAxe2AttackUpRight"));
		data[TowerType::FireAxe2].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireAxe2AttackRight"));
		data[TowerType::FireAxe2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireAxe2AttackDownRight"));
		data[TowerType::FireAxe2].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireAxe2AttackDownDown"));
		data[TowerType::FireAxe2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireAxe2AttackDownLeft"));
		data[TowerType::FireAxe2].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireAxe2AttackLeft"));
		data[TowerType::FireAxe2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireAxe2AttackUpLeft"));
		data[TowerType::FireAxe2].range = 1;
		data[TowerType::FireAxe2].swingSpeed = 1.0f;
		data[TowerType::FireAxe2].cooldown = 1.0f;
		data[TowerType::FireAxe2].projectileType = ProjectileType::Fireball;
		data[TowerType::FireAxe2].attackEffect = AttackEffect::BigArea;
		data[TowerType::FireAxe2].damage = 140;
		data[TowerType::FireAxe2].experienceToNextLevel = 0;

		data[TowerType::EnergyMace].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpUp"));
		data[TowerType::EnergyMace].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpRight"));
		data[TowerType::EnergyMace].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMaceAttackRight"));
		data[TowerType::EnergyMace].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownRight"));
		data[TowerType::EnergyMace].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownDown"));
		data[TowerType::EnergyMace].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownLeft"));
		data[TowerType::EnergyMace].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMaceAttackLeft"));
		data[TowerType::EnergyMace].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpLeft"));
		data[TowerType::EnergyMace].range = 2;
		data[TowerType::EnergyMace].swingSpeed = 1.0f;
		data[TowerType::EnergyMace].cooldown = 1.0f;
		data[TowerType::EnergyMace].projectileType = ProjectileType::Lightning;
		data[TowerType::EnergyMace].attackEffect = AttackEffect::Stun;
		data[TowerType::EnergyMace].damage = 100;
		data[TowerType::EnergyMace].experienceToNextLevel = 60;

		data[TowerType::EnergyMace2].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpUp"));
		data[TowerType::EnergyMace2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpRight"));
		data[TowerType::EnergyMace2].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMace2AttackRight"));
		data[TowerType::EnergyMace2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownRight"));
		data[TowerType::EnergyMace2].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownDown"));
		data[TowerType::EnergyMace2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownLeft"));
		data[TowerType::EnergyMace2].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMace2AttackLeft"));
		data[TowerType::EnergyMace2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpLeft"));
		data[TowerType::EnergyMace2].range = 2;
		data[TowerType::EnergyMace2].swingSpeed = 1.0f;
		data[TowerType::EnergyMace2].cooldown = 1.0f;
		data[TowerType::EnergyMace2].projectileType = ProjectileType::Lightning;
		data[TowerType::EnergyMace2].attackEffect = AttackEffect::Stun;
		data[TowerType::EnergyMace2].damage = 160;
		data[TowerType::EnergyMace2].experienceToNextLevel = 0;

		json j(data);
		std::ofstream o("../Media/Textures/TowerData.json");
		o << std::setw(2) << j << std::endl;
	}
	else
	{
		json json_;
		json_ = json::parse(ifs);
		data = json_.get<std::map<TowerType, TowerData>>();

	}

	return data;
}



std::map<TowerType, TowerType> initializeLevelUpData()
{
	std::map<TowerType, TowerType> data;

	data[TowerType::ClubWarrior] = TowerType::AxeWarrior;
	data[TowerType::AxeWarrior] = TowerType::AxeMaster;
	data[TowerType::AxeMaster] = TowerType::AxeGrandmaster;
	data[TowerType::AxeGrandmaster] = TowerType::None;
	data[TowerType::Novice] = TowerType::PoisonApprentice;
	data[TowerType::PoisonApprentice] = TowerType::PoisonMaster;
	data[TowerType::PoisonMaster] = TowerType::PoisonGrandmaster;
	data[TowerType::PoisonGrandmaster] = TowerType::None;
	data[TowerType::IceSword] = TowerType::IceSword2;
	data[TowerType::IceSword2] = TowerType::None;
	data[TowerType::FireAxe] = TowerType::FireAxe2;
	data[TowerType::FireAxe2] = TowerType::None;
	data[TowerType::EnergyMace] = TowerType::EnergyMace2;
	data[TowerType::EnergyMace2] = TowerType::None;

	return data;
}



std::map<Particle::Type, ParticleData> initializeParticleData()
{
	std::map<Particle::Type, ParticleData> data;

	data[Particle::Type::Propellant].color = sf::Color(255, 255, 50);
	data[Particle::Type::Propellant].lifetime = sf::seconds(0.6f);

	data[Particle::Type::Smoke].color = sf::Color(50, 50, 50);
	data[Particle::Type::Smoke].lifetime = sf::seconds(4.f);

	return data;
}