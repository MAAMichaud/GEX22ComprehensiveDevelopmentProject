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
#include "DataTables.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"



#include <SFML/Graphics/Sprite.hpp>

class Tower;
class Bank;



class UpgradeController : public SceneNode
{
public:
										UpgradeController(const TextureHolder_t& textures, Bank* bank);

	TowerType							processClick(const sf::Vector2i) const;
	TowerType							processClick(const int x, const int y) const;
	void								show(const TowerType newType);
	void								hide();

private:
	TowerType							processNovice(const sf::Vector2i) const;
	TowerType							processClub(const sf::Vector2i) const;
	void								initializeData();
	virtual void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	std::map<TowerType, sf::IntRect>	textureRects;
	sf::Sprite							sprite;
	TowerType							currentType;
	std::map<TowerType, TowerType>		upgradeTypes;
	std::map<TowerType, std::size_t>	upgradePrices;
	Bank*								bank;

};
