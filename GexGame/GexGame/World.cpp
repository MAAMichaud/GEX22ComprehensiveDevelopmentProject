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
#include "World.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include "utility.h"
#include "Entity.h"
#include "Command.h"
#include "SpriteNode.h"
#include "particleNode.h"
#include "SoundPlayer.h"
#include "SoundNode.h"



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
	, worldBounds(0.f, 0.f, worldView.getSize().x, 4000.f)
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
}



void World::buildScene()
{
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
