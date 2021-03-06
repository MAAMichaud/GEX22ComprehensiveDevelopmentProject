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

#include "BloomEffect.h"
#include "CommandQueue.h"
#include "DataTables.h"
#include "LaneController.h"
#include "JsonFrameParser.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "State.h"

#include <array>
#include <vector>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>



namespace sf {
	class RenderWindow;
}
class SoundPlayer;
class Tower;
class Projectile;
class Bank;
class UpgradeController;
class LifeCounter;
class NextWaveIcon;
class TowerController;



class World
{
public:
	enum class State
	{
		BuildWarrior,
		BuildWizard,
		BuildIce,
		BuildFire,
		BuildEnergy,
		Idle,
		UpgradeTower,
	};

public:
										World(const World&) = delete;
	explicit							World(sf::RenderTarget& target, FontHolder_t& fonts, SoundPlayer& sounds, LevelType levelType, sf::RenderWindow& _window);

	void								update(sf::Time dt);
	void								updateSounds();
	void								draw();
	CommandQueue&						getCommandQueue();

	void								startWave();
	void								boardClicked();
	void								selectTower(State newState);
	void								cancel();
	void								addGold(std::size_t amount);
	void								loseLife();
	bool								gameWon() const;
	bool								gameLost() const;
	void								soundUp();
	void								soundDown();

private:
	void								loadTextures();
	void								buildScene();
	sf::FloatRect						getViewBounds() const;
	sf::FloatRect						getBattlefieldBounds() const;

	void								handleMouseOverlay();
	void								handleTowers();
	void								placeSpriteAtTile(SpriteNode& sprite, const sf::Vector2i tile);
	void								placeSpriteAtTile(sf::Sprite& sprite, const sf::Vector2i tile);

	void                                placeTower();
	Tower*                              getCursorTower(sf::Vector2i tile);
	void								processWaveIcon();

private:
	enum Layer
	{
		Background = 0,
		LowerAir,
		UpperAir,
		LayerCount
	};

private:
	sf::RenderTarget&					target;
	sf::RenderTexture					sceneTexture;
	sf::View							worldView;
	TextureHolder_t						textures;
	FontHolder_t&						fonts;
	SoundPlayer&						sounds;

	SceneNode							sceneGraph;
	std::array<SceneNode*, LayerCount>	sceneLayers;
	CommandQueue						commands;

	sf::FloatRect						worldBounds;
	sf::Vector2f						spawnPosition;

	BloomEffect							bloomEffect;

	LevelType							levelType;
	sf::RenderWindow&					window;
	SpriteNode*							tileOverlay;
	LaneController*						laneController;
	std::size_t							waveIndex;
	State								state;
	std::map<State, Frame>				iconFrames;
	sf::Sprite							towerIcon;
	SceneNode*							centerNode;
	Projectile*							projectileTest;
	Bank*								bank;
	sf::Sprite							threeBythree;
	sf::Sprite							fiveByfive;
	sf::Sprite							sevenByseven;
	sf::Sprite*							rangeSprite;
	UpgradeController*					upgradeController;
	Tower*								upgradingTower;
	LifeCounter*						lifeCounter;
	NextWaveIcon*						nextWaveIcon;
	TowerController*					towerController;

};
