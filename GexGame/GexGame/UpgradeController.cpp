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
#include "Bank.h"
#include "UpgradeController.h"
#include "utility.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>



UpgradeController::UpgradeController(const TextureHolder_t& textures, Bank* _bank)
	: sprite(textures.get(TextureID::Upgrades))
	, textureRects()
	, currentType(TowerType::Novice)
	, upgradeTypes()
	, upgradePrices()
	, bank(_bank)
{
	initializeData();

	sprite.setTextureRect(textureRects.at(TowerType::EnergyMace));

	centerOrigin(sprite);

	hide();
}



void UpgradeController::show(const TowerType newType)
{
	currentType = newType;
	sprite.setTextureRect(textureRects.at(newType));
	centerOrigin(sprite);
	sprite.setColor(sf::Color(255, 255, 255, 255));
}



void UpgradeController::hide()
{
	sprite.setColor(sf::Color(0, 0, 0, 0));
}



TowerType UpgradeController::processClick(const sf::Vector2i coordinates) const
{
	if (bank->getBalance() < upgradePrices.at(currentType))
	{
		return TowerType::None;
	}

	if (currentType == TowerType::Novice)
	{
		return processNovice(coordinates);
	}
	else if (currentType == TowerType::ClubWarrior)
	{
		return processClub(coordinates);
	}

	static const sf::IntRect UPGRADE_BUTTON_RECT{ -40, 45, 80, 20 };

	const auto [cX,  cY] { getWorldPosition() };
	const auto [x,  y] { coordinates };

	if (isMouseOverRect(coordinates, getWorldPosition(), UPGRADE_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return upgradeTypes.at(currentType);
	}

	return TowerType::None;
}



TowerType UpgradeController::processClick(const int x,const int y) const
{
	return processClick( sf::Vector2i(x, y));
}



TowerType UpgradeController::processNovice(const sf::Vector2i coordinates) const
{
	static const sf::IntRect ICE_BUTTON_RECT{ -105, 45, 45, 25 };
	static const sf::IntRect FIRE_BUTTON_RECT{ -45, 45, 45, 25 };
	static const sf::IntRect ENERGY_BUTTON_RECT{ 15, 45, 45, 25 };
	static const sf::IntRect POISON_BUTTON_RECT{ 75, 45, 45, 25 };

	const auto [cX,  cY] { getWorldPosition() };
	const auto [x,  y] { coordinates };

	if (isMouseOverRect(coordinates, getWorldPosition(), ICE_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::IceApprentice;
	}
	else if (isMouseOverRect(coordinates, getWorldPosition(), FIRE_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::FireApprentice;
	}
	else if (isMouseOverRect(coordinates, getWorldPosition(), ENERGY_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::EnergyApprentice;
	}
	else if (isMouseOverRect(coordinates, getWorldPosition(), POISON_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::PoisonApprentice;
	}

	return TowerType::None;
}



TowerType UpgradeController::processClub(const sf::Vector2i coordinates) const
{
	static const sf::IntRect SWORD_BUTTON_RECT{ -80, 45, 53, 25 };
	static const sf::IntRect AXE_BUTTON_RECT{ -20, 45, 53, 25 };
	static const sf::IntRect MACE_BUTTON_RECT{ 40, 45, 53, 25 };

	const auto [cX,  cY] { getWorldPosition() };
	const auto [x,  y] { coordinates };

	if (isMouseOverRect(coordinates, getWorldPosition(), SWORD_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::SwordWarrior;
	}
	else if (isMouseOverRect(coordinates, getWorldPosition(), AXE_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::AxeWarrior;
	}
	else if (isMouseOverRect(coordinates, getWorldPosition(), MACE_BUTTON_RECT))
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::MaceWarrior;
	}

	return TowerType::None;
}




void UpgradeController::initializeData()
{
	textureRects[TowerType::Novice] = sf::IntRect(0, 0, 257, 143);
	textureRects[TowerType::ClubWarrior] = sf::IntRect(0, 144 * 1, 195, 143);
	textureRects[TowerType::IceApprentice] = sf::IntRect(128 * 0, 144 * 2, 128, 143);
	textureRects[TowerType::IceMaster] = sf::IntRect(128 * 1, 144 * 2, 128, 143);
	textureRects[TowerType::FireApprentice] = sf::IntRect(128 * 0, 144 * 3, 128, 143);
	textureRects[TowerType::FireMaster] = sf::IntRect(128 * 1, 144 * 3, 128, 143);
	textureRects[TowerType::EnergyApprentice] = sf::IntRect(128 * 0, 144 * 4, 128, 143);
	textureRects[TowerType::EnergyMaster] = sf::IntRect(128 * 1, 144 * 4, 128, 143);
	textureRects[TowerType::PoisonApprentice] = sf::IntRect(128 * 0, 144 * 5, 128, 143);
	textureRects[TowerType::PoisonMaster] = sf::IntRect(128 * 1, 144 * 5, 128, 143);
	textureRects[TowerType::SwordWarrior] = sf::IntRect(128 * 0, 144 * 6, 128, 143);
	textureRects[TowerType::SwordMaster] = sf::IntRect(128 * 1, 144 * 6, 128, 143);
	textureRects[TowerType::AxeWarrior] = sf::IntRect(128 * 0, 144 * 7, 128, 143);
	textureRects[TowerType::AxeMaster] = sf::IntRect(128 * 1, 144 * 7, 128, 143);
	textureRects[TowerType::MaceWarrior] = sf::IntRect(128 * 0, 144 * 8, 128, 143);
	textureRects[TowerType::MaceMaster] = sf::IntRect(128 * 1, 144 * 8, 128, 143);
	textureRects[TowerType::IceSword] = sf::IntRect(128 * 0, 144 * 9, 128, 143);
	textureRects[TowerType::FireAxe] = sf::IntRect(128 * 1, 144 * 9, 128, 143);
	textureRects[TowerType::EnergyMace] = sf::IntRect(128 * 0, 144 * 10, 128, 143);

	upgradeTypes[TowerType::IceApprentice] = TowerType::IceMaster;
	upgradeTypes[TowerType::IceMaster] = TowerType::IceGrandmaster;
	upgradeTypes[TowerType::FireApprentice] = TowerType::FireMaster;
	upgradeTypes[TowerType::FireMaster] = TowerType::FireGrandmaster;
	upgradeTypes[TowerType::EnergyApprentice] = TowerType::EnergyMaster;
	upgradeTypes[TowerType::EnergyMaster] = TowerType::EnergyGrandmaster;
	upgradeTypes[TowerType::PoisonApprentice] = TowerType::PoisonMaster;
	upgradeTypes[TowerType::PoisonMaster] = TowerType::PoisonGrandmaster;
	upgradeTypes[TowerType::SwordWarrior] = TowerType::SwordMaster;
	upgradeTypes[TowerType::SwordMaster] = TowerType::SwordGrandmaster;
	upgradeTypes[TowerType::AxeWarrior] = TowerType::AxeMaster;
	upgradeTypes[TowerType::AxeMaster] = TowerType::AxeGrandmaster;
	upgradeTypes[TowerType::MaceWarrior] = TowerType::MaceMaster;
	upgradeTypes[TowerType::MaceMaster] = TowerType::MaceGrandmaster;
	upgradeTypes[TowerType::IceSword] = TowerType::IceSword2;
	upgradeTypes[TowerType::FireAxe] = TowerType::FireAxe2;
	upgradeTypes[TowerType::EnergyMace] = TowerType::EnergyMace2;

	upgradePrices[TowerType::Novice] = 20;
	upgradePrices[TowerType::ClubWarrior] = 20;
	upgradePrices[TowerType::IceApprentice] = 50;
	upgradePrices[TowerType::IceMaster] = 100;
	upgradePrices[TowerType::FireApprentice] = 50;
	upgradePrices[TowerType::FireMaster] = 100;
	upgradePrices[TowerType::EnergyApprentice] = 50;
	upgradePrices[TowerType::EnergyMaster] = 100;
	upgradePrices[TowerType::PoisonApprentice] = 50;
	upgradePrices[TowerType::PoisonMaster] = 100;
	upgradePrices[TowerType::SwordWarrior] = 50;
	upgradePrices[TowerType::SwordMaster] = 100;
	upgradePrices[TowerType::AxeWarrior] = 50;
	upgradePrices[TowerType::AxeMaster] = 100;
	upgradePrices[TowerType::MaceWarrior] = 50;
	upgradePrices[TowerType::MaceMaster] = 100;
	upgradePrices[TowerType::IceSword] = 150;
	upgradePrices[TowerType::FireAxe] = 150;
	upgradePrices[TowerType::EnergyMace] = 150;
}



void UpgradeController::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
