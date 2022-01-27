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



World::World(sf::RenderTarget& _target, FontHolder_t& _fonts, SoundPlayer& _sounds)
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

	updateSounds();
}



void World::updateSounds()
{
	//sounds.setListenerPosition(hero->getWorldPosition());
	sounds.removeStoppedSounds();
}



void World::draw()
{
	if (PostEffect::isSupported())
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
	textures.load(TextureID::ForestBoard, "../Media/Textures/ForestBoard.png");
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

	sf::Texture& backgroundTexture{ textures.get(TextureID::ForestBoard) };

	sf::IntRect textureRect(worldBounds);

	auto backgroundSprite{ std::make_unique<SpriteNode>(
		backgroundTexture, textureRect) };

	backgroundSprite->setPosition(worldBounds.left, worldBounds.top);
	sceneLayers[Background]->attachChild(std::move(backgroundSprite));
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