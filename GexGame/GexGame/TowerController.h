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

#include "SceneNode.h"
#include "World.h"



class Tower;


class TowerController : public SceneNode
{

public:
										TowerController(const TextureHolder_t& textures, const LevelType levelType, World& world);

	bool                                isTileAvailable(const sf::Vector2i tile) const;
	void                                placeTower(const TowerType, sf::Vector2i tile);
	Tower*                              getCursorTower(const sf::Vector2i tile) const;

private:
	void								placeTowerAtTile(Tower* tower, const sf::Vector2i tile);

private:
	std::vector<Tower*>					towers;
	std::vector<sf::Vector2i>			availableTiles;
	World&								world;
	const TextureHolder_t&				textures;

};

