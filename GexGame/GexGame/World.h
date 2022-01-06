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

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "State.h"
#include "Aircraft.h"
#include "Actor.h"
#include "CommandQueue.h"
#include "BloomEffect.h"

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <array>
#include <vector>



namespace sf {
	class RenderWindow;
}
class SoundPlayer;



class World
{
public:
										World(const World&) = delete;
	explicit							World(sf::RenderTarget& target, FontHolder_t& fonts, SoundPlayer& sounds);

	void								update(sf::Time dt);
	void								updateSounds();
	void								draw();
	CommandQueue&						getCommandQueue();

	bool								hasAlivePlayer() const;
	bool								hasPlayerReachedTheEnd() const;

private:
	void								loadTextures();
	void								buildScene();
	sf::FloatRect						getViewBounds() const;
	sf::FloatRect						getBattlefieldBounds() const;

	void								spawnEnemies();
	void								addEnemy(Aircraft::Type type, float x, float y);
	void								addEnemies();


	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();

	void								guideMissiles();
	void								handleCollisions();
	void								destroyEntitiesOutOfView();

private:
	enum Layer
	{
		Background = 0,
		LowerAir,
		UpperAir,
		LayerCount
	};

	struct SpawnPoint
	{
		SpawnPoint(Aircraft::Type type, float x, float y);

		Aircraft::Type	type;
		float			x;
		float			y;
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
	float								scrollSpeed;
	Actor*								hero;
	std::vector<SpawnPoint>				enemySpawnPoints;
	std::vector<Aircraft*>				activeEnemies;

	BloomEffect							bloomEffect;
};
