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



class LaneController : public SceneNode
{
public:
	explicit			LaneController(const TextureHolder_t& textures, std::vector<LaneData> data);

	bool				wavePending() const;
	void				loadWave(WaveData waveData);

private:
	void				spawnEnemy();
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	std::size_t									enemyCount;
	float										spawnRate;
	sf::Time									timeRemaining;
	std::vector<Lane*>							lanes;

};
