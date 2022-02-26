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



void UpgradeController::show(TowerType newType)
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



TowerType UpgradeController::processClick(int x, int y) const
{
	if (bank->getBalance() < upgradePrices.at(currentType))
	{
		return TowerType::None;
	}

	if (currentType == TowerType::Novice)
	{
		return processNovice(x, y);
	}
	else if (currentType == TowerType::ClubWarrior)
	{
		return processClub(x, y);
	}

	std::cout << "\n--Upgrade Controller--" << std::endl;

	static const float UPGRADE_BUTTON_LEFT{ -40 };
	static const float UPGRADE_BUTTON_TOP{ 45 };
	static const float UPGRADE_BUTTON_RIGHT{ 40 };
	static const float UPGRADE_BUTTON_BOTTOM{ 65 };

	const auto [cX,  cY] { getWorldPosition() };

	std::cout << cX << ", " << cY << ", " << x << ", " << y << std::endl;

	if (x < cX + UPGRADE_BUTTON_RIGHT
		&& x > cX + UPGRADE_BUTTON_LEFT
		&& y < cY + UPGRADE_BUTTON_BOTTOM
		&& y > cY + UPGRADE_BUTTON_TOP)
	{
		std::cout << "UPGRADE button pressed" << std::endl;
		bank->withdraw(upgradePrices.at(currentType));
		return upgradeTypes.at(currentType);
	}

	return TowerType::None;
}



TowerType UpgradeController::processNovice(int x, int y) const
{
	static const float ICE_BUTTON_LEFT{ -105 };
	static const float ICE_BUTTON_TOP{ 45 };
	static const float ICE_BUTTON_RIGHT{ -60 };
	static const float ICE_BUTTON_BOTTOM{ 70 };

	static const float FIRE_BUTTON_LEFT{ -45 };
	static const float FIRE_BUTTON_TOP{ 45 };
	static const float FIRE_BUTTON_RIGHT{ 0 };
	static const float FIRE_BUTTON_BOTTOM{ 70 };

	static const float ENERGY_BUTTON_LEFT{ 15 };
	static const float ENERGY_BUTTON_TOP{ 45 };
	static const float ENERGY_BUTTON_RIGHT{ 60 };
	static const float ENERGY_BUTTON_BOTTOM{ 70 };

	static const float POISON_BUTTON_LEFT{ 75 };
	static const float POISON_BUTTON_TOP{ 45 };
	static const float POISON_BUTTON_RIGHT{ 120 };
	static const float POISON_BUTTON_BOTTOM{ 70 };

	const auto [cX,  cY] { getWorldPosition() };


	if (x < cX + ICE_BUTTON_RIGHT
		&& x > cX + ICE_BUTTON_LEFT
		&& y < cY + ICE_BUTTON_BOTTOM
		&& y > cY + ICE_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::IceApprentice;
	}
	else if (x < cX + FIRE_BUTTON_RIGHT
		&& x > cX + FIRE_BUTTON_LEFT
		&& y < cY + FIRE_BUTTON_BOTTOM
		&& y > cY + FIRE_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::FireApprentice;
	}
	else if (x < cX + ENERGY_BUTTON_RIGHT
		&& x > cX + ENERGY_BUTTON_LEFT
		&& y < cY + ENERGY_BUTTON_BOTTOM
		&& y > cY + ENERGY_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::EnergyApprentice;
	}
	else if (x < cX + POISON_BUTTON_RIGHT
		&& x > cX + POISON_BUTTON_LEFT
		&& y < cY + POISON_BUTTON_BOTTOM
		&& y > cY + POISON_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::PoisonApprentice;
	}

	return TowerType::None;
}



TowerType UpgradeController::processClub(int x, int y) const
{
	static const float SWORD_BUTTON_LEFT{ -80 };
	static const float SWORD_BUTTON_TOP{ 45 };
	static const float SWORD_BUTTON_RIGHT{ -27 };
	static const float SWORD_BUTTON_BOTTOM{ 70 };

	static const float AXE_BUTTON_LEFT{ -20 };
	static const float AXE_BUTTON_TOP{ 45 };
	static const float AXE_BUTTON_RIGHT{ 33 };
	static const float AXE_BUTTON_BOTTOM{ 70 };

	static const float MACE_BUTTON_LEFT{ 40 };
	static const float MACE_BUTTON_TOP{ 45 };
	static const float MACE_BUTTON_RIGHT{ 93 };
	static const float MACE_BUTTON_BOTTOM{ 70 };

	//textureRects[TowerType::ClubWarrior] = sf::IntRect(0, 144 * 1, 195, 143);
	// 97, 71

	const auto [cX,  cY] { getWorldPosition() };


	if (x < cX + SWORD_BUTTON_RIGHT
		&& x > cX + SWORD_BUTTON_LEFT
		&& y < cY + SWORD_BUTTON_BOTTOM
		&& y > cY + SWORD_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::SwordWarrior;
	}
	else if (x < cX + AXE_BUTTON_RIGHT
		&& x > cX + AXE_BUTTON_LEFT
		&& y < cY + AXE_BUTTON_BOTTOM
		&& y > cY + AXE_BUTTON_TOP)
	{
		bank->withdraw(upgradePrices.at(currentType));
		return TowerType::AxeWarrior;
	}
	else if (x < cX + MACE_BUTTON_RIGHT
		&& x > cX + MACE_BUTTON_LEFT
		&& y < cY + MACE_BUTTON_BOTTOM
		&& y > cY + MACE_BUTTON_TOP)
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
