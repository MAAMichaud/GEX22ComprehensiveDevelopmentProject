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
#include "LaneController.h"
#include "Utility.h"



LaneController::LaneController(const TextureHolder_t& textures, std::vector<LaneData> data)
	: enemyCount(0)
	, spawnRate(1.0f)
	, timeRemaining(sf::Time::Zero)
	, lanes()
{
	for (auto& laneData : data)
	{
		auto laneNode{ std::make_unique<Lane>(textures, laneData)};
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
