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
	data[LevelType::Cemetery].waves.at(0).enemyCount = 6;
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

	JsonFrameParser frames{ JsonFrameParser("../Media/Textures/TowerAtlasFlipped.json") };

	data[EnemyType::Skeleton].texture = TextureID::Towers;
	data[EnemyType::Skeleton].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpRight"));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownRight"));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownLeft"));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpLeft"));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Skeleton].speed = sf::seconds(0.4f);

	std::string test = "ClubWarriorAttackLeft";
	std::string test2 = "ClubWarriorAttackRight";
	data[EnemyType::Skeleton].texture = TextureID::Towers;
	data[EnemyType::Skeleton].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpUp"));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("ClubWarriorAttackDownRight"));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor(test));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Skeleton].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("ClubWarriorAttackUpLeft"));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Skeleton].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Skeleton].speed = sf::seconds(0.4f);

	data[EnemyType::Zombie].texture = TextureID::Towers;
	data[EnemyType::Zombie].animations[Direction::UpRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackUpUp"));
	data[EnemyType::Zombie].animations[Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::UpRight].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::DownRight].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackRight"));
	data[EnemyType::Zombie].animations[Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::DownRight].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::DownLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackDownDown"));
	data[EnemyType::Zombie].animations[Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::DownLeft].setRepeating(true);
	data[EnemyType::Zombie].animations[Direction::UpLeft].addFrameSet(frames.getFramesFor("AxeGrandmasterAttackLeft"));
	data[EnemyType::Zombie].animations[Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[EnemyType::Zombie].animations[Direction::UpLeft].setRepeating(true);
	data[EnemyType::Zombie].speed = sf::seconds(0.4f);

	frames = JsonFrameParser("../Media/Textures/CemeteryLeveLFlipped.json");

	/*
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
	*/

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



std::map<Particle::Type, ParticleData> initializeParticleData()
{
	std::map<Particle::Type, ParticleData> data;

	data[Particle::Type::Propellant].color = sf::Color(255, 255, 50);
	data[Particle::Type::Propellant].lifetime = sf::seconds(0.6f);

	data[Particle::Type::Smoke].color = sf::Color(50, 50, 50);
	data[Particle::Type::Smoke].lifetime = sf::seconds(4.f);

	return data;
}