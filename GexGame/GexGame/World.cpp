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
#include "Command.h"
#include "Entity.h"
#include "particleNode.h"
#include "SoundNode.h"
#include "SoundPlayer.h"
#include "SpriteNode.h"
#include "utility.h"
#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>


#include "JsonFrameParser.h"
#include "Animation2.h"
#include "AnimatedNode.h"


namespace
{
	const std::map<LevelType, LevelData> LEVEL_DATA{ initializeLevelData() };
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
{
	sceneTexture.create(target.getSize().x, target.getSize().y);

	loadTextures();
	buildScene();

	worldView.setCenter(spawnPosition);
}



void World::update(sf::Time dt)
{
	while (!commands.isEmpty())
	{
		sceneGraph.onCommand(commands.pop(), dt);
	}

	destroyEntitiesOutOfView();

	handleCollisions();
	sceneGraph.removeWrecks();


	sceneGraph.update(dt, commands);

	handleMouse();
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
		sceneTexture.display();
		bloomEffect.apply(sceneTexture, target);
	}
	else
	{
		target.setView(worldView);
		target.draw(sceneGraph);
	}
}



CommandQueue& World::getCommandQueue()
{
	return commands;
}



bool World::hasAlivePlayer() const
{
	return false;
}



bool World::hasPlayerReachedTheEnd() const
{
	return false;
}



void World::loadTextures()
{
	textures.load(LEVEL_DATA.at(levelType).backgroundTexture, LEVEL_DATA.at(levelType).backgroundTexturePath);
	textures.load(TextureID::OnebyOne, "../Media/Textures/1by1.png");
	textures.load(TextureID::Lich, "../Media/Textures/LichAtlas.png");
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

	makeLich();
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



void World::handleCollisions()
{
}



void World::destroyEntitiesOutOfView()
{
	auto battlefieldBounds{ getBattlefieldBounds() };

	Command command;
	//command.category = Category::SpaceJunk;

	command.action = derivedAction<Entity>(
		[this, battlefieldBounds](Entity& e, sf::Time dt)
	{
		if (!battlefieldBounds.intersects(e.getBoundingRect()))
		{
			e.remove();
		}
	});

	commands.push(command);
}



void World::handleMouse()
{	
	const auto [pixelX,  pixelY] { sf::Mouse::getPosition(window) };

	const auto [tileX, tileY] { pixelXYToTileXY(pixelX, pixelY) };

	if (tileX >= 0 && tileX < 16 && tileY >= 0 && tileY < 19)
	{
		tileOverlay->setRGBA(sf::Color(255, 255, 255, 130));


		placeSpriteAtTile(*tileOverlay, tileX, tileY);
	}
	else
	{
		tileOverlay->setRGBA(sf::Color(255, 255, 255, 0));
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



sf::Vector2i World::pixelXYToTileXY(int x, int y)
{
    return sf::Vector2i(calculateXTile(x, y), calculateYTile(x, y));
}



int World::calculateXTile(int x, int y)
{
	static const double xTriangleTangent{ 2.0 / 3 };

	static const int tileHeight{ 48 };
	static const int xTriangleTotalHeight{ 888 };
	//static const int xTriangleExcess{ 504 };
	static const int xTriangleExcess{ 504 - 158 };
	const double xTriangleHeight{ xTriangleTangent * (x + xTriangleExcess) };

	return (y - (xTriangleTotalHeight - xTriangleHeight)) / tileHeight;
}



int World::calculateYTile(int x, int y)
{
	static const double yTriangleTangent{ 1.5 };

	static const int tileWidth{ 72 };
	static const int yTriangleOffset{ 72 };
	static const int yTriangleExcess{ 408 + 106 };
	const double yTriangleWidth{ yTriangleTangent * (y + yTriangleExcess) };

	return (yTriangleWidth + yTriangleOffset - x) / tileWidth;
}



void World::makeLich()
{
	auto laneNode{ std::make_unique<Lane>(textures, LEVEL_DATA.at(levelType).lanes.at(0)) };
	sceneLayers[LowerAir]->attachChild(std::move(laneNode));
	/*
	auto lichNode{ std::make_unique<AnimatedNode>(textures, AnimatedNode::Type::Lich)};

	lichNode->setPosition(worldBounds.left + 970, worldBounds.top + 84);
	sceneLayers[LowerAir]->attachChild(std::move(lichNode));


	lichNode = std::make_unique<AnimatedNode>(textures, AnimatedNode::Type::Lich);

	lichNode->setPosition(worldBounds.left + 1042, worldBounds.top + 84);
	sceneLayers[LowerAir]->attachChild(std::move(lichNode));


	lichNode = std::make_unique<AnimatedNode>(textures, AnimatedNode::Type::Lich);

	lichNode->setPosition(worldBounds.left + 970, worldBounds.top + 184);
	sceneLayers[LowerAir]->attachChild(std::move(lichNode));


	lichNode = std::make_unique<AnimatedNode>(textures, AnimatedNode::Type::Lich);

	lichNode->setPosition(worldBounds.left + 1042, worldBounds.top + 184);
	sceneLayers[LowerAir]->attachChild(std::move(lichNode));
	*/

}
