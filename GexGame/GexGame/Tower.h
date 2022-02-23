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

#include "Animation2.h"
#include "DataTables.h"
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>



class Tower: public SceneNode
{
public:
									Tower(const TextureHolder_t& textures, TowerData towerData, std::pair<int, int> tile);
	bool							isAttackPending() const;
	std::pair<int, int>				getTile() const;
	std::size_t						getRange() const;

private:
	void							turn(Direction direction);
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	sf::Sprite						sprite;
	std::map<Direction, Animation2>	animations;
	Direction						direction;
	sf::Time						timeRemaining;
	sf::Time						cooldownDuration;
	sf::Time						cooldownRemaining;
	std::size_t						experiencePoints;
	std::size_t						range;
	sf::Sprite						rangeSprite;
	std::pair<int, int>				tile;

};
