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
#include "LaneController.h"
#include "Tower.h"
#include "Utility.h"

#include <algorithm>



LaneController::LaneController(const TextureHolder_t& textures, std::vector<LaneData> data)
	: enemyCount(0)
	, spawnRate(1.0f)
	, timeRemaining(sf::Time::Zero)
	, lanes()
{
	for (auto& laneData : data)
	{
		auto laneNode{ std::make_unique<Lane>(textures, laneData, *this)};
		lanes.push_back(laneNode.get());
		this->attachChild(std::move(laneNode));
	}
}



void LaneController::spawnEnemy()
{
	lanes.at(randomInt(lanes.size()))->spawnEnemy();
	enemyCount -= 1;
}



bool LaneController::wavePending() const
{
	return enemyCount <= 0;
}



void LaneController::loadWave(WaveData waveData)
{
	if (wavePending())
	{
		for (auto& lane : lanes)
		{
			lane->loadEnemy(waveData.enemyData);
		}

		enemyCount = waveData.enemyCount;
		spawnRate = waveData.spawnRate;
		timeRemaining = sf::Time::Zero;
	}
}



std::vector<Enemy*> LaneController::getEnemiesAt(const int tileX, const int tileY) const
{
	auto enemies{ std::vector<Enemy*>() };

	for (auto& lane : lanes)
	{
		auto laneEnemies{ lane->getEnemiesAt(tileX, tileY) };
		enemies.insert(enemies.cend(), laneEnemies.cbegin(), laneEnemies.cend());
	}

	return enemies;
}



std::vector<Enemy*> LaneController::getEnemiesAt(const std::pair<int, int> tile, const std::size_t range) const
{
	auto enemies{ std::vector<Enemy*>() };

	for (auto& lane : lanes)
	{
		auto laneEnemies{ lane->getEnemiesAt(tile, range) };
		enemies.insert(enemies.cend(), laneEnemies.cbegin(), laneEnemies.cend());
	}

	return enemies;
}



Enemy* LaneController::getFurthestEnemy(const std::pair<int, int> tile, const std::size_t range) const
{
	auto enemies{ getEnemiesAt(tile, range) };

	auto e{ std::max_element(enemies.begin(), enemies.end(), [](Enemy* rhs, Enemy* lhs) { return lhs->getProgress() > rhs->getProgress(); }) };
	if (e != enemies.end())
	{
		return *e;
	}
	else
	{
		return nullptr;
	}
}



void LaneController::areaAttack(Enemy* enemy, Tower* tower, float range)
{
	auto enemies{ std::vector<Enemy*>() };

	for (auto& lane : lanes)
	{
		auto laneEnemies{ lane->getArea(enemy->getWorldPosition(), range) };
		enemies.insert(enemies.cend(), laneEnemies.cbegin(), laneEnemies.cend());
	}

	for (auto enemy : enemies)
	{
		enemy->damage(tower->getAttackDamage(), tower);
	}
}



void LaneController::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (enemyCount > 0)
	{
		while (dt > timeRemaining)
		{
			dt -= timeRemaining;
			timeRemaining += sf::seconds(spawnRate);
			timeRemaining += sf::seconds(spawnRate * ((float) randomInt(10) / 10));

			spawnEnemy();
		}

		timeRemaining -= dt;
	}
}
