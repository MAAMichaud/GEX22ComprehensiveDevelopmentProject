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



TowerData::TowerData(std::size_t _range, ProjectileType _projectileType)
	: animations()
	, range(_range)
	, projectileType(_projectileType)
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


void to_json(json& j, const TowerData& t) {
	j = json{ {"animations", t.animations}, {"range", t.range}, {"projectileType", t.projectileType} };
}

void from_json(const json& j, TowerData& t) {
	j.at("animations").get_to(t.animations);
	j.at("range").get_to(t.range);
	j.at("projectileType").get_to(t.projectileType);
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
	for (int i{ 0 }; i < 5; ++i)
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

	data[LevelType::Mountain].backgroundTexture = TextureID::MountainBoard;
	data[LevelType::Mountain].backgroundTexturePath = "../Media/Textures/MountainBoard.png";

	return data;
}



std::map<EnemyType, EnemyData> initializeEnemyData()
{
	std::map<EnemyType, EnemyData> data;

	auto frames{ JsonFrameParser("../Media/Textures/CemeteryLeveLFlipped.json") };

	data[EnemyType::Skeleton].texture = TextureID::CemeteryLevel;
	data[EnemyType::Skeleton].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SkeletonWalkUpRight"));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SkeletonWalkDownRight"));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SkeletonWalkDownLeft"));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SkeletonWalkUpLeft"));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Skeleton].speed = sf::seconds(0.4f);

	data[EnemyType::Zombie].texture = TextureID::CemeteryLevel;
	data[EnemyType::Zombie].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ZombieWalkUpRight"));
	data[EnemyType::Zombie].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ZombieWalkDownRight"));
	data[EnemyType::Zombie].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ZombieWalkDownLeft"));
	data[EnemyType::Zombie].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ZombieWalkUpLeft"));
	data[EnemyType::Zombie].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Zombie].speed = sf::seconds(0.5f);

	data[EnemyType::AncientZombie].texture = TextureID::CemeteryLevel;
	data[EnemyType::AncientZombie].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AncientZombieWalkUpRight"));
	data[EnemyType::AncientZombie].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::AncientZombie].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::AncientZombie].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AncientZombieWalkDownRight"));
	data[EnemyType::AncientZombie].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::AncientZombie].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::AncientZombie].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AncientZombieWalkDownLeft"));
	data[EnemyType::AncientZombie].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::AncientZombie].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::AncientZombie].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AncientZombieWalkUpLeft"));
	data[EnemyType::AncientZombie].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::AncientZombie].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::AncientZombie].speed = sf::seconds(0.6f);

	data[EnemyType::Lich].texture = TextureID::CemeteryLevel;
	data[EnemyType::Lich].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("LichWalkUpRight"));
	data[EnemyType::Lich].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Lich].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Lich].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("LichWalkDownRight"));
	data[EnemyType::Lich].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Lich].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Lich].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("LichWalkDownLeft"));
	data[EnemyType::Lich].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Lich].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Lich].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("LichWalkUpLeft"));
	data[EnemyType::Lich].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Lich].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Lich].speed = sf::seconds(0.4f);

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
		data[TowerType::ClubWarrior].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::Up].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpRight"));
		data[TowerType::ClubWarrior].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("ClubWarriorAttackRight"));
		data[TowerType::ClubWarrior].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::Right].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownRight"));
		data[TowerType::ClubWarrior].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownDown"));
		data[TowerType::ClubWarrior].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::Down].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownLeft"));
		data[TowerType::ClubWarrior].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("ClubWarriorAttackLeft"));
		data[TowerType::ClubWarrior].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::Left].setRepeating(true);
		data[TowerType::ClubWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpLeft"));
		data[TowerType::ClubWarrior].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::ClubWarrior].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::SwordWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpUp"));
		data[TowerType::SwordWarrior].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::Up].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpRight"));
		data[TowerType::SwordWarrior].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordWarriorAttackRight"));
		data[TowerType::SwordWarrior].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::Right].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownRight"));
		data[TowerType::SwordWarrior].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownDown"));
		data[TowerType::SwordWarrior].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::Down].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordWarriorAttackDownLeft"));
		data[TowerType::SwordWarrior].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordWarriorAttackLeft"));
		data[TowerType::SwordWarrior].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::Left].setRepeating(true);
		data[TowerType::SwordWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordWarriorAttackUpLeft"));
		data[TowerType::SwordWarrior].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordWarrior].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::SwordMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordMasterAttackUpUp"));
		data[TowerType::SwordMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordMasterAttackUpRight"));
		data[TowerType::SwordMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordMasterAttackRight"));
		data[TowerType::SwordMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordMasterAttackDownRight"));
		data[TowerType::SwordMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordMasterAttackDownDown"));
		data[TowerType::SwordMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordMasterAttackDownLeft"));
		data[TowerType::SwordMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordMasterAttackLeft"));
		data[TowerType::SwordMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::SwordMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordMasterAttackUpLeft"));
		data[TowerType::SwordMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordMaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::SwordGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpUp"));
		data[TowerType::SwordGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownRight"));
		data[TowerType::SwordGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownDown"));
		data[TowerType::SwordGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackDownLeft"));
		data[TowerType::SwordGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackLeftLeft"));
		data[TowerType::SwordGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::SwordGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("SwordGrandmasterAttackUpLeft"));
		data[TowerType::SwordGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::SwordGrandmaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::AxeWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpUp"));
		data[TowerType::AxeWarrior].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::Up].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpRight"));
		data[TowerType::AxeWarrior].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeWarriorAttackRight"));
		data[TowerType::AxeWarrior].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::Right].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownRight"));
		data[TowerType::AxeWarrior].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownDown"));
		data[TowerType::AxeWarrior].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::Down].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeWarriorAttackDownLeft"));
		data[TowerType::AxeWarrior].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeWarriorAttackLeft"));
		data[TowerType::AxeWarrior].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::Left].setRepeating(true);
		data[TowerType::AxeWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeWarriorAttackUpLeft"));
		data[TowerType::AxeWarrior].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeWarrior].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::AxeMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeMasterAttackUpUp"));
		data[TowerType::AxeMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeMasterAttackUpRight"));
		data[TowerType::AxeMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeMasterAttackRight"));
		data[TowerType::AxeMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeMasterAttackDownRight"));
		data[TowerType::AxeMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeMasterAttackDownDown"));
		data[TowerType::AxeMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeMasterAttackDownLeft"));
		data[TowerType::AxeMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeMasterAttackLeft"));
		data[TowerType::AxeMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::AxeMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeMasterAttackUpLeft"));
		data[TowerType::AxeMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeMaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::AxeGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpUp"));
		data[TowerType::AxeGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownRight"));
		data[TowerType::AxeGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownDown"));
		data[TowerType::AxeGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownLeft"));
		data[TowerType::AxeGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackLeft"));
		data[TowerType::AxeGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::AxeGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpLeft"));
		data[TowerType::AxeGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::AxeGrandmaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::MaceWarrior].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpUp"));
		data[TowerType::MaceWarrior].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::Up].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpRight"));
		data[TowerType::MaceWarrior].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceWarriorAttackRight"));
		data[TowerType::MaceWarrior].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::Right].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownRight"));
		data[TowerType::MaceWarrior].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownDown"));
		data[TowerType::MaceWarrior].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::Down].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceWarriorAttackDownLeft"));
		data[TowerType::MaceWarrior].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceWarriorAttackLeft"));
		data[TowerType::MaceWarrior].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::Left].setRepeating(true);
		data[TowerType::MaceWarrior].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceWarriorAttackUpLeft"));
		data[TowerType::MaceWarrior].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceWarrior].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::MaceMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceMasterAttackUpUp"));
		data[TowerType::MaceMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceMasterAttackUpRight"));
		data[TowerType::MaceMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceMasterAttackRight"));
		data[TowerType::MaceMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceMasterAttackDownRight"));
		data[TowerType::MaceMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceMasterAttackDownDown"));
		data[TowerType::MaceMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceMasterAttackDownLeft"));
		data[TowerType::MaceMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceMasterAttackLeft"));
		data[TowerType::MaceMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::MaceMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceMasterAttackUpLeft"));
		data[TowerType::MaceMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceMaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::MaceGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpUp"));
		data[TowerType::MaceGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownRight"));
		data[TowerType::MaceGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownDown"));
		data[TowerType::MaceGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackDownLeft"));
		data[TowerType::MaceGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackLeft"));
		data[TowerType::MaceGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::MaceGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("MaceGrandmasterAttackUpLeft"));
		data[TowerType::MaceGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::MaceGrandmaster].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::Novice].animations[Direction::Up].addFrameSet(frames.getFramesFor("NoviceAttackUpUp"));
		data[TowerType::Novice].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::Up].setRepeating(true);
		data[TowerType::Novice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("NoviceAttackUpRight"));
		data[TowerType::Novice].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::Novice].animations[Direction::Right].addFrameSet(frames.getFramesFor("NoviceAttackRight"));
		data[TowerType::Novice].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::Right].setRepeating(true);
		data[TowerType::Novice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("NoviceAttackDownRight"));
		data[TowerType::Novice].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::Novice].animations[Direction::Down].addFrameSet(frames.getFramesFor("NoviceAttackDownDown"));
		data[TowerType::Novice].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::Down].setRepeating(true);
		data[TowerType::Novice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("NoviceAttackDownLeft"));
		data[TowerType::Novice].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::Novice].animations[Direction::Left].addFrameSet(frames.getFramesFor("NoviceAttackLeft"));
		data[TowerType::Novice].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::Left].setRepeating(true);
		data[TowerType::Novice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("NoviceAttackUpLeft"));
		data[TowerType::Novice].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::Novice].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::Novice].range = 2;
		data[TowerType::Novice].projectileType = ProjectileType::MagicArrow;

		data[TowerType::IceApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpUp"));
		data[TowerType::IceApprentice].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::Up].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpRight"));
		data[TowerType::IceApprentice].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceApprenticeAttackRight"));
		data[TowerType::IceApprentice].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::Right].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownRight"));
		data[TowerType::IceApprentice].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownDown"));
		data[TowerType::IceApprentice].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::Down].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceApprenticeAttackDownLeft"));
		data[TowerType::IceApprentice].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceApprenticeAttackLeft"));
		data[TowerType::IceApprentice].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::Left].setRepeating(true);
		data[TowerType::IceApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceApprenticeAttackUpLeft"));
		data[TowerType::IceApprentice].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceApprentice].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::IceApprentice].range = 2;
		data[TowerType::IceApprentice].projectileType = ProjectileType::IceBall;

		data[TowerType::IceMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceMasterAttackUpUp"));
		data[TowerType::IceMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceMasterAttackUpRight"));
		data[TowerType::IceMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceMasterAttackRight"));
		data[TowerType::IceMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceMasterAttackDownRight"));
		data[TowerType::IceMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceMasterAttackDownDown"));
		data[TowerType::IceMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceMasterAttackDownLeft"));
		data[TowerType::IceMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceMasterAttackLeft"));
		data[TowerType::IceMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::IceMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceMasterAttackUpLeft"));
		data[TowerType::IceMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceMaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::IceMaster].range = 2;
		data[TowerType::IceMaster].projectileType = ProjectileType::IceBall;

		data[TowerType::IceGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpUp"));
		data[TowerType::IceGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpRight"));
		data[TowerType::IceGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceGrandmasterAttackRight"));
		data[TowerType::IceGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownRight"));
		data[TowerType::IceGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownDown"));
		data[TowerType::IceGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceGrandmasterAttackDownLeft"));
		data[TowerType::IceGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceGrandmasterAttackLeft"));
		data[TowerType::IceGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::IceGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceGrandmasterAttackUpLeft"));
		data[TowerType::IceGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceGrandmaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::IceGrandmaster].range = 2;
		data[TowerType::IceGrandmaster].projectileType = ProjectileType::IceBall;

		data[TowerType::FireApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpUp"));
		data[TowerType::FireApprentice].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::Up].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpRight"));
		data[TowerType::FireApprentice].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireApprenticeAttackRight"));
		data[TowerType::FireApprentice].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::Right].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownRight"));
		data[TowerType::FireApprentice].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownDown"));
		data[TowerType::FireApprentice].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::Down].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireApprenticeAttackDownLeft"));
		data[TowerType::FireApprentice].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireApprenticeAttackLeft"));
		data[TowerType::FireApprentice].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::Left].setRepeating(true);
		data[TowerType::FireApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireApprenticeAttackUpLeft"));
		data[TowerType::FireApprentice].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireApprentice].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::FireApprentice].range = 2;
		data[TowerType::FireApprentice].projectileType = ProjectileType::Fireball;

		data[TowerType::FireMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireMasterAttackUpUp"));
		data[TowerType::FireMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireMasterAttackUpRight"));
		data[TowerType::FireMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireMasterAttackRight"));
		data[TowerType::FireMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireMasterAttackDownRight"));
		data[TowerType::FireMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireMasterAttackDownDown"));
		data[TowerType::FireMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireMasterAttackDownLeft"));
		data[TowerType::FireMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireMasterAttackLeft"));
		data[TowerType::FireMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::FireMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireMasterAttackUpLeft"));
		data[TowerType::FireMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireMaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::FireMaster].range = 2;
		data[TowerType::FireMaster].projectileType = ProjectileType::Fireball;

		data[TowerType::FireGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpUp"));
		data[TowerType::FireGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpRight"));
		data[TowerType::FireGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireGrandmasterAttackRight"));
		data[TowerType::FireGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownRight"));
		data[TowerType::FireGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownDown"));
		data[TowerType::FireGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireGrandmasterAttackDownLeft"));
		data[TowerType::FireGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireGrandmasterAttackLeft"));
		data[TowerType::FireGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::FireGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireGrandmasterAttackUpLeft"));
		data[TowerType::FireGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireGrandmaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::FireGrandmaster].range = 2;
		data[TowerType::FireGrandmaster].projectileType = ProjectileType::Fireball;

		data[TowerType::EnergyApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpUp"));
		data[TowerType::EnergyApprentice].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::Up].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpRight"));
		data[TowerType::EnergyApprentice].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackRight"));
		data[TowerType::EnergyApprentice].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::Right].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownRight"));
		data[TowerType::EnergyApprentice].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownDown"));
		data[TowerType::EnergyApprentice].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::Down].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackDownLeft"));
		data[TowerType::EnergyApprentice].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackLeft"));
		data[TowerType::EnergyApprentice].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::Left].setRepeating(true);
		data[TowerType::EnergyApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyApprenticeAttackUpLeft"));
		data[TowerType::EnergyApprentice].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyApprentice].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::EnergyApprentice].range = 3;
		data[TowerType::EnergyApprentice].projectileType = ProjectileType::Lightning;

		data[TowerType::EnergyMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpUp"));
		data[TowerType::EnergyMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpRight"));
		data[TowerType::EnergyMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMasterAttackRight"));
		data[TowerType::EnergyMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownRight"));
		data[TowerType::EnergyMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownDown"));
		data[TowerType::EnergyMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMasterAttackDownLeft"));
		data[TowerType::EnergyMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMasterAttackLeft"));
		data[TowerType::EnergyMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::EnergyMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMasterAttackUpLeft"));
		data[TowerType::EnergyMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::EnergyMaster].range = 3;
		data[TowerType::EnergyMaster].projectileType = ProjectileType::Lightning;

		data[TowerType::EnergyGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpUp"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownRight"));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownDown"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackDownLeft"));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackLeft"));
		data[TowerType::EnergyGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::EnergyGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyGrandmasterAttackUpLeft"));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyGrandmaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::EnergyGrandmaster].range = 3;
		data[TowerType::EnergyGrandmaster].projectileType = ProjectileType::Lightning;

		data[TowerType::PoisonApprentice].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpUp"));
		data[TowerType::PoisonApprentice].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::Up].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpRight"));
		data[TowerType::PoisonApprentice].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackRight"));
		data[TowerType::PoisonApprentice].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::Right].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownRight"));
		data[TowerType::PoisonApprentice].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownDown"));
		data[TowerType::PoisonApprentice].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::Down].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackDownLeft"));
		data[TowerType::PoisonApprentice].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackLeft"));
		data[TowerType::PoisonApprentice].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::Left].setRepeating(true);
		data[TowerType::PoisonApprentice].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonApprenticeAttackUpLeft"));
		data[TowerType::PoisonApprentice].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonApprentice].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::PoisonApprentice].range = 2;
		data[TowerType::PoisonApprentice].projectileType = ProjectileType::Poison;

		data[TowerType::PoisonMaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpUp"));
		data[TowerType::PoisonMaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpRight"));
		data[TowerType::PoisonMaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonMasterAttackRight"));
		data[TowerType::PoisonMaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownRight"));
		data[TowerType::PoisonMaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownDown"));
		data[TowerType::PoisonMaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonMasterAttackDownLeft"));
		data[TowerType::PoisonMaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonMasterAttackLeft"));
		data[TowerType::PoisonMaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::PoisonMaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonMasterAttackUpLeft"));
		data[TowerType::PoisonMaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonMaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::PoisonMaster].range = 2;
		data[TowerType::PoisonMaster].projectileType = ProjectileType::Poison;

		data[TowerType::PoisonGrandmaster].animations[Direction::Up].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpUp"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::Up].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::Right].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::Right].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownRight"));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::Down].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownDown"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::Down].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackDownLeft"));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::Left].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackLeft"));
		data[TowerType::PoisonGrandmaster].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::Left].setRepeating(true);
		data[TowerType::PoisonGrandmaster].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("PoisonGrandmasterAttackUpLeft"));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::PoisonGrandmaster].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::PoisonGrandmaster].range = 2;
		data[TowerType::PoisonGrandmaster].projectileType = ProjectileType::Poison;

		data[TowerType::IceSword].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceSwordAttackUpUp"));
		data[TowerType::IceSword].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::Up].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceSwordAttackUpRight"));
		data[TowerType::IceSword].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceSwordAttackRight"));
		data[TowerType::IceSword].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::Right].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceSwordAttackDownRight"));
		data[TowerType::IceSword].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceSwordAttackDownDown"));
		data[TowerType::IceSword].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::Down].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceSwordAttackDownLeft"));
		data[TowerType::IceSword].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceSwordAttackLeft"));
		data[TowerType::IceSword].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::Left].setRepeating(true);
		data[TowerType::IceSword].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceSwordAttackUpLeft"));
		data[TowerType::IceSword].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::IceSword].range = 2;
		data[TowerType::IceSword].projectileType = ProjectileType::IceBall;

		data[TowerType::IceSword2].animations[Direction::Up].addFrameSet(frames.getFramesFor("IceSword2AttackUpUp"));
		data[TowerType::IceSword2].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::Up].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("IceSword2AttackUpRight"));
		data[TowerType::IceSword2].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::Right].addFrameSet(frames.getFramesFor("IceSword2AttackRight"));
		data[TowerType::IceSword2].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::Right].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("IceSword2AttackDownRight"));
		data[TowerType::IceSword2].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::Down].addFrameSet(frames.getFramesFor("IceSword2AttackDownDown"));
		data[TowerType::IceSword2].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::Down].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("IceSword2AttackDownLeft"));
		data[TowerType::IceSword2].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::Left].addFrameSet(frames.getFramesFor("IceSword2AttackLeft"));
		data[TowerType::IceSword2].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::Left].setRepeating(true);
		data[TowerType::IceSword2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("IceSword2AttackUpLeft"));
		data[TowerType::IceSword2].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::IceSword2].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::FireAxe].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireAxeAttackUpUp"));
		data[TowerType::FireAxe].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::Up].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireAxeAttackUpRight"));
		data[TowerType::FireAxe].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireAxeAttackRight"));
		data[TowerType::FireAxe].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::Right].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireAxeAttackDownRight"));
		data[TowerType::FireAxe].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireAxeAttackDownDown"));
		data[TowerType::FireAxe].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::Down].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireAxeAttackDownLeft"));
		data[TowerType::FireAxe].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireAxeAttackLeft"));
		data[TowerType::FireAxe].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::Left].setRepeating(true);
		data[TowerType::FireAxe].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireAxeAttackUpLeft"));
		data[TowerType::FireAxe].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::FireAxe].range = 2;
		data[TowerType::FireAxe].projectileType = ProjectileType::Fireball;

		data[TowerType::FireAxe2].animations[Direction::Up].addFrameSet(frames.getFramesFor("FireAxe2AttackUpUp"));
		data[TowerType::FireAxe2].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::Up].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("FireAxe2AttackUpRight"));
		data[TowerType::FireAxe2].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::Right].addFrameSet(frames.getFramesFor("FireAxe2AttackRight"));
		data[TowerType::FireAxe2].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::Right].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("FireAxe2AttackDownRight"));
		data[TowerType::FireAxe2].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::Down].addFrameSet(frames.getFramesFor("FireAxe2AttackDownDown"));
		data[TowerType::FireAxe2].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::Down].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("FireAxe2AttackDownLeft"));
		data[TowerType::FireAxe2].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::Left].addFrameSet(frames.getFramesFor("FireAxe2AttackLeft"));
		data[TowerType::FireAxe2].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::Left].setRepeating(true);
		data[TowerType::FireAxe2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("FireAxe2AttackUpLeft"));
		data[TowerType::FireAxe2].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::FireAxe2].animations[Direction::UpLeft].setRepeating(true);

		data[TowerType::EnergyMace].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpUp"));
		data[TowerType::EnergyMace].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::Up].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpRight"));
		data[TowerType::EnergyMace].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMaceAttackRight"));
		data[TowerType::EnergyMace].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::Right].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownRight"));
		data[TowerType::EnergyMace].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownDown"));
		data[TowerType::EnergyMace].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::Down].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMaceAttackDownLeft"));
		data[TowerType::EnergyMace].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMaceAttackLeft"));
		data[TowerType::EnergyMace].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::Left].setRepeating(true);
		data[TowerType::EnergyMace].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMaceAttackUpLeft"));
		data[TowerType::EnergyMace].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace].animations[Direction::UpLeft].setRepeating(true);
		data[TowerType::EnergyMace].range = 3;
		data[TowerType::EnergyMace].projectileType = ProjectileType::Lightning;

		data[TowerType::EnergyMace2].animations[Direction::Up].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpUp"));
		data[TowerType::EnergyMace2].animations[Direction::Up].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::Up].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpRight"));
		data[TowerType::EnergyMace2].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::UpRight].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::Right].addFrameSet(frames.getFramesFor("EnergyMace2AttackRight"));
		data[TowerType::EnergyMace2].animations[Direction::Right].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::Right].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownRight"));
		data[TowerType::EnergyMace2].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::DownRight].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::Down].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownDown"));
		data[TowerType::EnergyMace2].animations[Direction::Down].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::Down].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("EnergyMace2AttackDownLeft"));
		data[TowerType::EnergyMace2].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::DownLeft].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::Left].addFrameSet(frames.getFramesFor("EnergyMace2AttackLeft"));
		data[TowerType::EnergyMace2].animations[Direction::Left].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::Left].setRepeating(true);
		data[TowerType::EnergyMace2].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("EnergyMace2AttackUpLeft"));
		data[TowerType::EnergyMace2].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
		data[TowerType::EnergyMace2].animations[Direction::UpLeft].setRepeating(true);

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



std::map<Particle::Type, ParticleData> initializeParticleData()
{
	std::map<Particle::Type, ParticleData> data;

	data[Particle::Type::Propellant].color = sf::Color(255, 255, 50);
	data[Particle::Type::Propellant].lifetime = sf::seconds(0.6f);

	data[Particle::Type::Smoke].color = sf::Color(50, 50, 50);
	data[Particle::Type::Smoke].lifetime = sf::seconds(4.f);

	return data;
}