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

#include "Lane.h"
#include "DataTables.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"

#include <vector>

class Enemy;
class Tower;



class LaneController : public SceneNode
{
public:
	explicit				LaneController(const TextureHolder_t& textures, std::vector<LaneData> data);

	bool					wavePending() const;
	void					loadWave(WaveData waveData);
	std::vector<Enemy*>		getEnemiesAt(const int tileX, const int tileY) const;
	std::vector<Enemy*>		getEnemiesAt(const std::pair<int, int> tile, const std::size_t range) const;
	Enemy*					getFurthestEnemy(const std::pair<int, int> tile, const std::size_t range) const;
	void					areaAttack(Enemy* enemy, Tower* tower, float range);

private:
	void					spawnEnemy();
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	std::size_t									enemyCount;
	float										spawnRate;
	sf::Time									timeRemaining;
	std::vector<Lane*>							lanes;

};
