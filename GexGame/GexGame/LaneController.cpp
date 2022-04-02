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
#include "FloatingTextNode.h"
#include "LaneController.h"
#include "Tower.h"
#include "Utility.h"
#include "World.h"

#include <algorithm>

#include "iostream"



LaneController::LaneController(const TextureHolder_t& textures, const FontHolder_t& _fonts, std::vector<LaneData> data, World& _world)
	: enemyCount(0)
	, spawnRate(1.0f)
	, timeRemaining(sf::Time::Zero)
	, lanes()
	, world(_world)
	, fonts(_fonts)
	, pendingGold()
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



bool LaneController::waveEnded() const
{
	auto count{ 0 };

	for (auto lane : lanes)
	{
		count += lane->children.size();
	}

	return wavePending() && count < 1;
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



std::vector<Enemy*> LaneController::getEnemiesAt(const sf::Vector2i tile) const
{
	auto enemies{ std::vector<Enemy*>() };

	for (auto& lane : lanes)
	{
		auto laneEnemies{ lane->getEnemiesAt(tile) };
		enemies.insert(enemies.cend(), laneEnemies.cbegin(), laneEnemies.cend());
	}

	return enemies;
}



std::vector<Enemy*> LaneController::getEnemiesAt(const int tileX, const int tileY) const
{
	return getEnemiesAt(sf::Vector2i(tileX, tileY));
}



std::vector<Enemy*> LaneController::getEnemiesAt(const sf::Vector2i tile, const std::size_t range) const
{
	auto enemies{ std::vector<Enemy*>() };

	for (auto& lane : lanes)
	{
		auto laneEnemies{ lane->getEnemiesAt(tile, range) };
		enemies.insert(enemies.cend(), laneEnemies.cbegin(), laneEnemies.cend());
	}

	return enemies;
}



std::vector<Enemy*> LaneController::getEnemiesAt(const int tileX, const int tileY, const std::size_t range) const
{
	return getEnemiesAt(sf::Vector2i(tileX, tileY), range);
}



Enemy* LaneController::getFurthestEnemy(const sf::Vector2i tile, const std::size_t range) const
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



void LaneController::addGold(std::size_t amount, sf::Vector2f position)
{
	world.addGold(amount);

	pendingGold.push_back(std::pair<int, sf::Vector2f>(amount, position));
}



void LaneController::loseLife()
{
	world.loseLife();
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

	if (pendingGold.size() > 0)
	{
		auto gold{ pendingGold.back() };
		pendingGold.pop_back();

		auto floatNode{ std::make_unique<FloatingTextNode>(fonts, std::to_string(gold.first) + "Gold", sf::Color(255, 255, 100, 255))};
		const sf::Vector2f OFFSET_POSITION{gold.second.x + 36.f, gold.second.y + 26.f};
		floatNode->setPosition(OFFSET_POSITION);
		attachChild(std::move(floatNode));
	}
}