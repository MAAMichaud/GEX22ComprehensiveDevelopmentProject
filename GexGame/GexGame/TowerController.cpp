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
#include "Tower.h"
#include "TowerController.h"
#include <algorithm>
#include <map>



namespace
{
	const std::map<LevelType, std::vector<sf::Vector2i>> TOWER_TILES{ initializeTowerTileData() };
	const std::map<TowerType, TowerData> TOWER_DATA{ initializeTowerData() };
}



TowerController::TowerController(const TextureHolder_t& _textures, const LevelType levelType, World& _world)
	: towers()
	, availableTiles(TOWER_TILES.at(levelType))
	, world(_world)
	, textures(_textures)
{
}



bool TowerController::isTileAvailable(const sf::Vector2i tile) const
{
	return std::find(availableTiles.cbegin(), availableTiles.cend(), tile) != availableTiles.cend();
}



void TowerController::placeTower(const TowerType towerType, sf::Vector2i tile)
{
	auto towerNode{ std::make_unique<Tower>(textures, towerType, TOWER_DATA.at(towerType), tile) };
	placeTowerAtTile(towerNode.get(), tile);
	towers.push_back(towerNode.get());
	this->attachChild(std::move(towerNode));

	availableTiles.erase(std::remove(availableTiles.begin(), availableTiles.end(), tile), availableTiles.end());
}



Tower* TowerController::getCursorTower(const sf::Vector2i tile) const
{
	Tower* cursorTower{ nullptr };

	for (auto tower : towers)
	{
		auto [tX, tY] { tower->getTile() };
		if (tile.x == tX && tile.y == tY)
		{
			cursorTower = tower;
		}
	}

	return cursorTower;
}



std::vector<Tower*> TowerController::getAttackingTowers() const
{
	std::vector<Tower*> attackingTowers;

	std::copy_if(towers.begin(), towers.end(),
		std::back_inserter(attackingTowers),
		[](Tower* t) { return t->isAttackPending(); 
	});

	return attackingTowers;
}



void TowerController::placeTowerAtTile(Tower* tower, const sf::Vector2i tile)
{
    static const float BASE_X{ 880.f };
    static const float BASE_Y{ 96.f };
    static const float INCREMENT_X{ 36.f };
    static const float INCREMENT_Y{ 24.f };

    float newX{ BASE_X + (INCREMENT_X * tile.x) - (INCREMENT_X * tile.y) };
    float newY{ BASE_Y + INCREMENT_Y * tile.x + INCREMENT_Y * tile.y };

    tower->setPosition(sf::Vector2f(newX, newY - 96));
}
