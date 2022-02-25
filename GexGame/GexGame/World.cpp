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
#include "Command.h"
#include "Enemy.h"
#include "LaneController.h"
#include "particleNode.h"
#include "Projectile.h"
#include "SoundNode.h"
#include "SoundPlayer.h"
#include "SpriteNode.h"
#include "Tower.h"
#include "utility.h"
#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include <algorithm>



#include <iostream>



namespace
{
	const std::map<LevelType, LevelData> LEVEL_DATA{ initializeLevelData() };
	const std::map<TowerType, TowerData> TOWER_DATA{ initializeTowerData() };
}

World::World(sf::RenderTarget& _target, FontHolder_t& _fonts, SoundPlayer& _sounds, LevelType _levelType, sf::RenderWindow& _window)
	: target(_target)
	, sceneTexture()
	, worldView(_target.getDefaultView())
	, textures()
	, fonts(_fonts)
	, sounds(_sounds)
	, sceneGraph()
	, sceneLayers()
	, commands()
	, worldBounds(0.f, 0.f, worldView.getSize().x, worldView.getSize().y)
	, spawnPosition(worldView.getSize().x / 2.f, worldBounds.height - (worldView.getSize().y / 2.f))
	, bloomEffect()
	, levelType(_levelType)
	, window(_window)
	, tileOverlay()
	, laneController()
	, waveIndex(0)
	, state(State::Idle)
	, iconFrames()
	, towerIcon()
	, towers()
{
	sceneTexture.create(target.getSize().x, target.getSize().y);

	loadTextures();
	buildScene();

	worldView.setCenter(spawnPosition);


	towerIcon.setTexture(textures.get(TextureID::Towers));
	towerIcon.setTextureRect(sf::IntRect());

	iconFrames.emplace(World::State::BuildWizard, TOWER_DATA.at(TowerType::Novice).animations.at(Direction::Down).frames.at(0));
	iconFrames.emplace(World::State::BuildWarrior, TOWER_DATA.at(TowerType::ClubWarrior).animations.at(Direction::Down).frames.at(0));
	iconFrames.emplace(World::State::BuildIce, TOWER_DATA.at(TowerType::IceSword).animations.at(Direction::Down).frames.at(0));
	iconFrames.emplace(World::State::BuildFire, TOWER_DATA.at(TowerType::FireAxe).animations.at(Direction::Down).frames.at(0));
	iconFrames.emplace(World::State::BuildEnergy, TOWER_DATA.at(TowerType::EnergyMace).animations.at(Direction::Down).frames.at(0));
}



void World::update(sf::Time dt)
{
	while (!commands.isEmpty())
	{
		sceneGraph.onCommand(commands.pop(), dt);
	}

	sceneGraph.removeWrecks();

	sceneGraph.update(dt, commands);

	handleTowers();

	handleMouseOverlay();
	updateSounds();
}



void World::updateSounds()
{
	//sounds.setListenerPosition(hero->getWorldPosition());
	sounds.removeStoppedSounds();
}



void World::draw()
{
	if (true && PostEffect::isSupported())
	{
		sceneTexture.clear();
		sceneTexture.setView(worldView);
		sceneTexture.draw(sceneGraph);
		sceneTexture.draw(towerIcon);
		sceneTexture.display();
		bloomEffect.apply(sceneTexture, target);
	}
	else
	{
		target.setView(worldView);
		target.draw(sceneGraph);
		target.draw(towerIcon);
	}
}



CommandQueue& World::getCommandQueue()
{
	return commands;
}



void World::startWave()
{
	if (laneController->wavePending() && waveIndex < LEVEL_DATA.at(levelType).waves.size())
	{
		laneController->loadWave(LEVEL_DATA.at(levelType).waves.at(waveIndex));

		waveIndex += 1;
	}
}



void World::boardClicked()
{
	const auto [pixelX,  pixelY] { sf::Mouse::getPosition(window) };

	const auto [tileX, tileY] { pixelXYToTileXY(pixelX, pixelY) };

	if (state == State::Idle)
	{
		auto enemy{ laneController->getFurthestEnemy(std::pair<int, int>{ tileX, tileY }, 1) };

		if (enemy)
		{
			enemy->destroy();
		}
	}
	else
	{
		if (tileX >= 0 && tileX < 16 && tileY >= 0 && tileY < 19)
		{
			placeTower();
		}
	}

	std::cout << std::endl;

	auto projectileNode{ std::make_unique<Projectile>(textures, ProjectileType::Poison) };
	const auto [cX,  cY] { centerNode->getPosition() };
	projectileNode->setPosition(pixelX - cX, pixelY - cY);
	centerNode->attachChild(std::move(projectileNode));
}



void World::selectTower(State newState)
{
	const auto balance{ bank->getBalance() };
	if ((newState == State::BuildWizard || newState == State::BuildWarrior) && balance >= 20)
	{
		state = newState;
	}
	else if (balance >= 180)
	{
		state = newState;
	}
	else
	{
		return;
	}

	const auto& frame{ iconFrames.at(newState) };

	towerIcon.setTextureRect(sf::IntRect(std::get<0>(frame.intRect), std::get<1>(frame.intRect), std::get<2>(frame.intRect), std::get<3>(frame.intRect)));
	towerIcon.setRotation(frame.isRotated ? -90.f : 0.f);
	towerIcon.setPosition(frame.offset.first, frame.offset.second);
}



void World::cancel()
{
	towerIcon.setTextureRect(sf::IntRect());
	state = State::Idle;
}



void World::addGold(std::size_t amount)
{
	bank->deposit(amount);
}



void World::loadTextures()
{
	textures.load(LEVEL_DATA.at(levelType).backgroundTexture, LEVEL_DATA.at(levelType).backgroundTexturePath);
	textures.load(TextureID::OnebyOne, "../Media/Textures/1by1.png");
	textures.load(TextureID::Lich, "../Media/Textures/LichAtlas.png");
	textures.load(TextureID::ForestLevel, "../Media/Textures/ForestLevel.png");
	textures.load(TextureID::CemeteryLevel, "../Media/Textures/CemeteryLevel.png");
	textures.load(TextureID::BeachLevel, "../Media/Textures/BeachLevel.png");
	textures.load(TextureID::MountainLevel, "../Media/Textures/MountainLevel.png");
	textures.load(TextureID::Towers, "../Media/Textures/TowerAtlas.png");
	textures.load(TextureID::Spells, "../Media/Textures/Spells.png");
}



void World::buildScene()
{
	for (size_t i{ 0 }; i < LayerCount; ++i)
	{
		auto category{ (i == LowerAir) ? Category::SceneAirLayer : Category::None };

		SceneNode::Ptr layer(new SceneNode(category));
		sceneLayers[i] = layer.get();
		sceneGraph.attachChild(std::move(layer));
	}


	sf::Texture& backgroundTexture{ textures.get(LEVEL_DATA.at(levelType).backgroundTexture) };

	auto backgroundSprite{ std::make_unique<SpriteNode>(backgroundTexture) };

	backgroundSprite->setPosition(worldBounds.left, worldBounds.top);
	sceneLayers[Background]->attachChild(std::move(backgroundSprite));


	sf::Texture& overlayTexture{ textures.get(TextureID::OnebyOne) };

	auto overlaySprite{ std::make_unique<SpriteNode>(overlayTexture) };
	tileOverlay = overlaySprite.get();
	overlaySprite->setOrigin(sf::Vector2f(0.f, 48.f));

	overlaySprite->setPosition(worldBounds.left, worldBounds.top);
	sceneLayers[LowerAir]->attachChild(std::move(overlaySprite));

	auto laneControllerNode{ std::make_unique<LaneController>(textures, LEVEL_DATA.at(levelType).lanes, *this) };
	laneController = laneControllerNode.get();
	sceneLayers[LowerAir]->attachChild(std::move(laneControllerNode));

	auto cNode{ std::make_unique<SceneNode>() };
	cNode->setPosition(800, 450);
	centerNode = cNode.get();
	sceneLayers[LowerAir]->attachChild(std::move(cNode));

	auto bankNode{ std::make_unique<Bank>(fonts) };
	bankNode->setPosition(100, 570);
	bank = bankNode.get();
	sceneLayers[LowerAir]->attachChild(std::move(bankNode));
}



sf::FloatRect World::getViewBounds() const
{
	sf::FloatRect viewBounds(worldView.getCenter() - worldView.getSize() / 2.f, worldView.getSize());
	return viewBounds;
}



sf::FloatRect World::getBattlefieldBounds() const
{
	auto bounds{ getViewBounds() };
	bounds.top -= 100.f;
	bounds.height += 100.f;

	return bounds;
}



bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
	unsigned int category1{ colliders.first->getCategory() };
	unsigned int category2{ colliders.second->getCategory() };

	if (type1 & category1 && type2 & category2)
	{
		return true;
	}
	else if (type1 & category2 && type2 & category1)
	{
		std::swap(colliders.first, colliders.second);
		return true;
	}
	else
	{
		return false;
	}
}



void World::handleMouseOverlay()
{	
	const auto [pixelX,  pixelY] { sf::Mouse::getPosition(window) };

	const auto [tileX, tileY] { pixelXYToTileXY(pixelX, pixelY) };

	tileOverlay->setRGBA(sf::Color(255, 255, 255, 0));
	towerIcon.setColor(sf::Color(255, 255, 255, 0));

	if (tileX >= 0 && tileX < 16 && tileY >= 0 && tileY < 19)
	{
		if (state == World::State::Idle)
		{
			tileOverlay->setRGBA(sf::Color(255, 255, 255, 130));

			placeSpriteAtTile(*tileOverlay, tileX, tileY);
		}
		else
		{
			towerIcon.setColor(sf::Color(255, 255, 255, 200));

			//towerIcon.setPosition(pixelX, pixelY);
			placeSpriteAtTile(towerIcon, tileX, tileY);
		}
	}
}



void World::handleTowers()
{
	for (auto& tower : towers)
	{
		if (tower->isAttackPending())
		{
			auto enemy{ laneController->getFurthestEnemy(tower->getTile(), tower->getRange()) };

			if (enemy)
			{
				tower->attack(enemy);
			}
		}
	}
}



void World::placeSpriteAtTile(SpriteNode& sprite, float x, float y)
{
    static const float BASE_X{ 880.f };
    static const float BASE_Y{ 96.f };
    static const float INCREMENT_X{ 36.f };
    static const float INCREMENT_Y{ 24.f };

    float newX{ BASE_X + (INCREMENT_X * x) - (INCREMENT_X * y) };
    float newY{ BASE_Y + INCREMENT_Y * x + INCREMENT_Y * y };

    sprite.setPosition(sf::Vector2f(newX, newY));
}



void World::placeSpriteAtTile(Tower* sprite, float x, float y)
{
    static const float BASE_X{ 880.f };
    static const float BASE_Y{ 96.f };
    static const float INCREMENT_X{ 36.f };
    static const float INCREMENT_Y{ 24.f };

    float newX{ BASE_X + (INCREMENT_X * x) - (INCREMENT_X * y) };
    float newY{ BASE_Y + INCREMENT_Y * x + INCREMENT_Y * y };

    sprite->setPosition(sf::Vector2f(newX, newY - 96));
}



void World::placeSpriteAtTile(sf::Sprite& sprite, float x, float y)
{
    static const float BASE_X{ 880.f };
    static const float BASE_Y{ 96.f };
    static const float INCREMENT_X{ 36.f };
    static const float INCREMENT_Y{ 24.f };

    float newX{ BASE_X + (INCREMENT_X * x) - (INCREMENT_X * y) };
    float newY{ BASE_Y + INCREMENT_Y * x + INCREMENT_Y * y };


	const auto& frame{ iconFrames.at(state) };

	/*
	towerIcon.setTextureRect(frame.intRect);
	towerIcon.setRotation(frame.isRotated ? -90.f : 0.f);
	towerIcon.setPosition(frame.offset.first, frame.offset.second);
	*/
			//const auto [thisTileX, thisTileY] { pixelXYToTileXY(pixelX + 36, pixelY + 72) };
    sprite.setPosition(sf::Vector2f(newX + frame.offset.first, newY - 96 + frame.offset.second));
}



void World::placeTower()
{
	const auto [pixelX,  pixelY] { sf::Mouse::getPosition(window) };

	const auto [tileX, tileY] { pixelXYToTileXY(pixelX, pixelY) };

	std::cout << "Placed tower at " << tileX << ", " << tileY << std::endl;

	TowerType towerType;

	switch (state)
	{
	case World::State::BuildWizard:
		towerType = TowerType::Novice;
		bank->withdraw(20);
		break;

	case World::State::BuildWarrior:
		towerType = TowerType::ClubWarrior;
		bank->withdraw(20);
		break;

	case World::State::BuildIce:
		towerType = TowerType::IceSword;
		bank->withdraw(180);
		break;

	case World::State::BuildFire:
		towerType = TowerType::FireAxe;
		bank->withdraw(180);
		break;

	case World::State::BuildEnergy:
		towerType = TowerType::EnergyMace;
		bank->withdraw(180);
		break;

	default:
		towerType = TowerType::Novice;
		bank->withdraw(20);
		break;

	}

	auto towerNode{ std::make_unique<Tower>(textures, TOWER_DATA.at(towerType), std::pair<int, int>{tileX, tileY}) };
	//towerNode->setPosition(pixelX - 18.f, pixelY - 72.f);
	placeSpriteAtTile(towerNode.get(), tileX, tileY);
	towers.push_back(towerNode.get());
	sceneLayers[LowerAir]->attachChild(std::move(towerNode));

	state = World::State::Idle;
}
