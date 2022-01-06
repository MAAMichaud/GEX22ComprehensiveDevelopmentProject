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
#include "pickup.h"
#include "projectile.h"
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
	, scrollSpeed(-50.f)
	, hero(nullptr)
	, enemySpawnPoints()
	, activeEnemies()
	, bloomEffect()
{
	sceneTexture.create(target.getSize().x, target.getSize().y);

	loadTextures();
	buildScene();

	worldView.setCenter(spawnPosition);
}



void World::update(sf::Time dt)
{
	worldView.move(0.f, scrollSpeed * dt.asSeconds());

	hero->setVelocity(0.f, 0.f);

	while (!commands.isEmpty())
	{
		sceneGraph.onCommand(commands.pop(), dt);
	}

	adaptPlayerVelocity();

	spawnEnemies();
	destroyEntitiesOutOfView();

	handleCollisions();
	sceneGraph.removeWrecks();

	guideMissiles();

	sceneGraph.update(dt, commands);
	adaptPlayerPosition();

	updateSounds();
}



void World::updateSounds()
{
	sounds.setListenerPosition(hero->getWorldPosition());
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
	return !hero->isDestroyed();
}



bool World::hasPlayerReachedTheEnd() const
{
	return !worldBounds.contains(hero->getPosition());
}



void World::loadTextures()
{
	textures.load(TextureID::Entities, "../Media/Textures/Entities.png");
	textures.load(TextureID::Jungle, "../Media/Textures/Jungle.png");
	textures.load(TextureID::Desert, "../Media/Textures/Desert.png");
	textures.load(TextureID::Explosion, "../Media/Textures/Explosion.png");
	textures.load(TextureID::Particle, "../Media/Textures/Particle.png");
	textures.load(TextureID::FinishLine, "../Media/Textures/FinishLine.png");

	textures.load(TextureID::Zombie1, "../Media/Textures/Zombies/Zombie1.png");
	textures.load(TextureID::Zombie2, "../Media/Textures/Zombies/Zombie2.png");
	textures.load(TextureID::Zombie3, "../Media/Textures/Zombies/Zombie3.png");
	textures.load(TextureID::Zombie4, "../Media/Textures/Zombies/Zombie4.png");
	textures.load(TextureID::Zombie5, "../Media/Textures/Zombies/Zombie5.png");
	textures.load(TextureID::Hero2, "../Media/Textures/Zombies/Hero2.png");
	textures.load(TextureID::Road, "../Media/Textures/Zombies/Road.png");
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

	sf::Texture& backgroundTexture{ textures.get(TextureID::Jungle) };
	backgroundTexture.setRepeated(true);

	sf::IntRect textureRect(worldBounds);

	auto backgroundSprite{ std::make_unique<SpriteNode>(
		backgroundTexture, textureRect) };

	backgroundSprite->setPosition(worldBounds.left, worldBounds.top);
	sceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add the finish line to the scene
	sf::Texture& finishTexture = textures.get(TextureID::FinishLine);
	std::unique_ptr<SpriteNode> finishSprite(new SpriteNode(finishTexture));
	finishSprite->setPosition(0.f, -76.f);
	sceneLayers[Background]->attachChild(std::move(finishSprite));

	auto leader{ std::make_unique<Actor>(Actor::Type::Hero2, textures, fonts) };
	hero = leader.get();
	hero->setPosition(spawnPosition);
	hero->setVelocity(150.f, scrollSpeed);
	sceneLayers[UpperAir]->attachChild(std::move(leader));

	auto smokeNode{ std::make_unique<ParticleNode>(Particle::Type::Smoke, textures) };
	sceneLayers[LowerAir]->attachChild(std::move(smokeNode));

	auto propellantNode{ std::make_unique<ParticleNode>(Particle::Type::Propellant, textures) };
	sceneLayers[LowerAir]->attachChild(std::move(propellantNode));

	auto soundNode{ std::make_unique<SoundNode>(sounds) };
	sceneGraph.attachChild(std::move(soundNode));

	addEnemies();
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



void World::spawnEnemies()
{
	while (!enemySpawnPoints.empty()
		&& enemySpawnPoints.back().y
	> getBattlefieldBounds().top)
	{
		auto spawn{ enemySpawnPoints.back() };

		auto enemy{ std::make_unique<Aircraft>(spawn.type, textures, fonts) };
		enemy->setPosition(spawn.x, spawn.y);
		enemy->setRotation(180.f);

		sceneLayers[UpperAir]->attachChild(std::move(enemy));

		enemySpawnPoints.pop_back();
	}
}



void World::addEnemy(Aircraft::Type type, float x, float y)
{
	enemySpawnPoints.push_back(SpawnPoint(type, x, y));
}



void World::addEnemies()
{
	addEnemy(Aircraft::Type::Raptor, 100.f, 3300.f);
	addEnemy(Aircraft::Type::Avenger, 700.f, 3000.f);
	addEnemy(Aircraft::Type::Avenger, 500.f, 3200.f);
	addEnemy(Aircraft::Type::Avenger, 510.f, 3210.f);
	addEnemy(Aircraft::Type::Avenger, 700.f, 2500.f);
	addEnemy(Aircraft::Type::Avenger, 500.f, 2500.f);
	addEnemy(Aircraft::Type::Raptor, 1000.f, 3200.f);
	addEnemy(Aircraft::Type::Raptor, 500.f, 2300.f);
	addEnemy(Aircraft::Type::Raptor, 700.f, 2500.f);
	addEnemy(Aircraft::Type::Raptor, 800.f, 2300.f);
	addEnemy(Aircraft::Type::Raptor, 300.f, 2500.f);

	addEnemy(Aircraft::Type::Raptor, 320.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 340.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 360.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 380.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 400.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 420.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 440.f, 2200.f);

	addEnemy(Aircraft::Type::Avenger, 220.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 240.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 260.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 280.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 300.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 320.f, 2000.f);
	addEnemy(Aircraft::Type::Avenger, 340.f, 2000.f);

	addEnemy(Aircraft::Type::Raptor, 320.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 340.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 360.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 380.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 400.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 420.f, 2200.f);
	addEnemy(Aircraft::Type::Raptor, 440.f, 2200.f);

	addEnemy(Aircraft::Type::Avenger, 220.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 240.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 260.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 280.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 300.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 320.f, 2400.f);
	addEnemy(Aircraft::Type::Avenger, 340.f, 2400.f);

	std::sort(enemySpawnPoints.begin(), enemySpawnPoints.end(),
		[](SpawnPoint lhs, SpawnPoint rhs) {
		return lhs.y < rhs.y;
	});
}



void World::adaptPlayerPosition()
{

	sf::FloatRect viewBounds(worldView.getCenter() - worldView.getSize() / 2.f, worldView.getSize());

	const float borderDistance{ 40.f };

	auto position{ hero->getPosition() };

	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	hero->setPosition(position);
}



void World::adaptPlayerVelocity()
{
	auto velocity{ hero->getVelocity() };

	if (velocity.x != 0.f && velocity.y != 0.f)
	{
		hero->setVelocity(velocity / std::sqrt(2.f));
	}

	hero->accelerate(0.f, scrollSpeed);
}



void World::guideMissiles()
{
	Command enemyCollector;
	enemyCollector.category = Category::EnemyAircraft;
	enemyCollector.action = derivedAction<Aircraft>([this](Aircraft& enemy, sf::Time dt)
	{
		if (!enemy.isDestroyed())
		{
			activeEnemies.push_back(&enemy);
		}
	});

	Command missileGuider;
	missileGuider.category = Category::AlliedProjectile;
	missileGuider.action = derivedAction<Projectile>([this](Projectile& missile, sf::Time dt)
	{
		if (!missile.isGuided())
		{
			return;
		}

		auto minDistance{ std::numeric_limits<float>::max() };
		Aircraft* closestEnemy{ nullptr };

		for (Aircraft* e : activeEnemies)
		{
			auto d{ distance(missile, *e) };
			if (d < minDistance)
			{
				minDistance = d;
				closestEnemy = e;
			}
		}

		if (closestEnemy)
		{
			missile.guideTowards(closestEnemy->getWorldPosition());
		}
	});

	commands.push(enemyCollector);
	commands.push(missileGuider);

	activeEnemies.clear();
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
	std::set<SceneNode::Pair> collisionPairs;
	sceneGraph.checkSceneCollision(sceneGraph, collisionPairs);

	for (auto pair : collisionPairs)
	{
		if (matchesCategories(pair, Category::Type::PlayerAircraft, Category::Type::EnemyAircraft))
		{
			auto& alliedPlane{ static_cast<Aircraft&>(*(pair.first)) };
			auto& enemyPlane{ static_cast<Aircraft&>(*(pair.second)) };

			alliedPlane.damage(enemyPlane.getHitPoints());
			enemyPlane.destroy();
		}
		else if (matchesCategories(pair, Category::Type::PlayerAircraft, Category::Type::Pickup))
		{
			auto& alliedPlane{ static_cast<Aircraft&>(*(pair.first)) };
			auto& pickup{ static_cast<Pickup&>(*(pair.second)) };

			pickup.apply(alliedPlane);
			pickup.destroy();

			//hero->playLocalSound(commands, SoundEffectID::CollectPickup);
		}
		else if (matchesCategories(pair, Category::Type::PlayerAircraft, Category::Type::EnemyProjectile) ||
			matchesCategories(pair, Category::Type::EnemyAircraft, Category::Type::AlliedProjectile))
		{
			auto& plane{ static_cast<Aircraft&>(*(pair.first)) };
			auto& projectile{ static_cast<Projectile&>(*(pair.second)) };

			plane.damage(projectile.getDamage());
			projectile.destroy();
		}
	}
}



void World::destroyEntitiesOutOfView()
{
	auto battlefieldBounds{ getBattlefieldBounds() };

	Command command;
	command.category = Category::SpaceJunk;

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



World::SpawnPoint::SpawnPoint(Aircraft::Type _type, float _x, float _y)
	: type(_type)
	, x(_x)
	, y(_y)
{
}
