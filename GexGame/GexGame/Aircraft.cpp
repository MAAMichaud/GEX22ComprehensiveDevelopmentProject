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
#include "Aircraft.h"
#include "Category.h"
#include "ResourceHolder.h"
#include "DataTables.h"
#include "Utility.h"
#include "SoundNode.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <stdexcept>
#include <string>
#include <map>



namespace
{
	const std::map<Aircraft::Type, AircraftData> AIRCRAFT_DATA{ initializeAircraftData() };
}



Aircraft::Aircraft(Type _type, const TextureHolder_t& textures, const FontHolder_t& fonts)
	: Entity(AIRCRAFT_DATA.at(_type).hitpoints)
	, type(_type)
	, sprite(textures.get(AIRCRAFT_DATA.at(_type).texture), AIRCRAFT_DATA.at(_type).textureRect)
	, explosion(textures.get(TextureID::Explosion))
	, showExplosion(true)
	, hasSpawnedPickup(false)
	, hasPlayedExplosionSound(false)
	, missileAmmo(5)
	, spreadLevel(1)
	, fireRateLevel(1)
	, directionIndex(0)
	, travelledDistance(0)
	, fireCommand()
	, missileCommand()
	, dropPickupCommand()
	, fireCountdown(sf::Time::Zero)
	, isFiring(false)
	, isLaunchingMissile(false)
	, _isMarkedForRemoval(false)
	, healthDisplay(nullptr)
	, missileDisplay(nullptr)
{
	explosion.setFrameSize(sf::Vector2i(256, 256));
	explosion.setNumFrames(16);
	explosion.setDuration(sf::seconds(2));
	centerOrigin(explosion);

	centerOrigin(sprite);

	fireCommand.category = Category::SceneAirLayer;
	fireCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		this->createBullets(node, textures);
	};

	missileCommand.category = Category::SceneAirLayer;
	missileCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		this->createProjectile(node, Projectile::Type::Missile, 0.f, 0.5f, textures);
	};


	dropPickupCommand.category = Category::SceneAirLayer;
	dropPickupCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		this->createPickup(node, textures);
	};

	instantiateTexts(fonts);
}



void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (isDestroyed() && showExplosion)
	{
		target.draw(explosion, states);
	}
	else
	{
		target.draw(sprite, states);
	}
}



unsigned int Aircraft::getCategory() const
{
	switch (type)
	{
	case Type::Eagle:
		return Category::PlayerAircraft;
		break;

	default:
		return Category::EnemyAircraft;
		break;

	}
}



void Aircraft::fire()
{
	if (AIRCRAFT_DATA.at(type).fireInterval != sf::Time::Zero)
	{
		isFiring = true;
	}
}



void Aircraft::launchMissile()
{
	if (missileAmmo > 0)
	{
		isLaunchingMissile = true;
		missileAmmo -= 1;
	}
}



bool Aircraft::isAllied() const
{
	return type == Type::Eagle;
}



void Aircraft::playLocalSound(CommandQueue& commands, SoundEffectID effect)
{
	Command playSoundCommand;
	auto pos{ getWorldPosition() };
	playSoundCommand.category = Category::SoundEffect;
	playSoundCommand.action = derivedAction<SoundNode>([pos, effect](SoundNode& node, sf::Time)
	{
		node.playSound(effect, pos);
	});

	commands.push(playSoundCommand);
}



void Aircraft::collectMissiles(unsigned int count)
{
	missileAmmo += count;
}



void Aircraft::increaseSpread()
{
	if (spreadLevel < 3)
	{
		spreadLevel += 1;
	}
}



void Aircraft::increaseFireRate()
{
	if (fireRateLevel < 10)
	{
		fireRateLevel += 1;
	}
}



sf::FloatRect Aircraft::getBoundingRect() const
{
	return getWorldTransform().transformRect(sprite.getGlobalBounds());
}



void Aircraft::remove()
{
	Entity::remove();
	showExplosion = false;
}



bool Aircraft::isMarkedForRemoval() const
{
	return isDestroyed() && (explosion.isFinished() || !showExplosion) && !(getCategory() == Category::PlayerAircraft);
}



void Aircraft::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	updateTexts();

	if (isDestroyed())
	{
		if (!hasSpawnedPickup)
		{
			checkPickupDrop(commands);
			hasSpawnedPickup = true;
		}
		if (!hasPlayedExplosionSound)
		{
			auto effect{ (randomInt(2) == 0) ? SoundEffectID::Explosion1 : SoundEffectID::Explosion2 };
			playLocalSound(commands, effect);
		}

		explosion.update(dt);

		return;
	}

	updateRollAnimation();

	checkProjectileLaunch(dt, commands);

	updateMovementPattern(dt);

	Entity::updateCurrent(dt, commands);
}



void Aircraft::updateRollAnimation()
{
	if (AIRCRAFT_DATA.at(type).hasRollAnimation)
	{
		auto textureRect{ AIRCRAFT_DATA.at(type).textureRect };

		if (getVelocity().x < 0.f)
		{
			textureRect.left += textureRect.width;
		}
		else if (getVelocity().x > 0.f)
		{
			textureRect.left += 2 * textureRect.width;
		}

		sprite.setTextureRect(textureRect);
	}
}




float Aircraft::getMaxSpeed() const
{
	return AIRCRAFT_DATA.at(type).speed;
}



void Aircraft::updateMovementPattern(sf::Time dt)
{
	const auto& DIRECTIONS{ AIRCRAFT_DATA.at(type).directions };

	if (!DIRECTIONS.empty())
	{
		auto distanceToTravel{ DIRECTIONS.at(directionIndex).distance };

		if (travelledDistance > distanceToTravel)
		{
			directionIndex = (directionIndex + 1) % DIRECTIONS.size();
			travelledDistance = 0;
		}

		travelledDistance += getMaxSpeed() * dt.asSeconds();

		auto degrees{ DIRECTIONS[directionIndex].angle + 90.f };
		auto vx{ getMaxSpeed() * gex::cos(degrees) };
		auto vy{ getMaxSpeed() * gex::sin(degrees) };
		setVelocity(vx, vy);
	}
}



void Aircraft::instantiateTexts(const FontHolder_t& fonts)
{
	auto uHealthDisplay{ std::make_unique<TextNode>(fonts, "") };
	healthDisplay = uHealthDisplay.get();
	healthDisplay->setPosition(0.f, 50.f);
	attachChild(std::move(uHealthDisplay));

	if (getCategory() & Category::PlayerAircraft)
	{
		auto uMissileDisplay{ std::make_unique<TextNode>(fonts, "") };
		missileDisplay = uMissileDisplay.get();
		missileDisplay->setPosition(0.f, 70.f);
		missileDisplay->setRotation(-getRotation());
		attachChild(std::move(uMissileDisplay));
	}
}



void Aircraft::updateTexts()
{
	if (isDestroyed())
	{
		healthDisplay->setString("");

		if (missileDisplay)
		{
			missileDisplay->setString("");
		}

		return;
	}

	healthDisplay->setString(std::to_string(getHitPoints()) + " HP");
	healthDisplay->setRotation(-getRotation());

	if (missileDisplay)
	{
		missileDisplay->setString(std::to_string(missileAmmo) + " M");
	}
}



void Aircraft::checkProjectileLaunch(sf::Time dt, CommandQueue& commands)
{
	if (!isAllied())
	{
		fire();
	}

	if (isFiring && fireCountdown <= sf::Time::Zero)
	{
		commands.push(fireCommand);
		playLocalSound(commands, isAllied() ? SoundEffectID::AlliedGunfire : SoundEffectID::EnemyGunfire);
		fireCountdown += AIRCRAFT_DATA.at(type).fireInterval / (fireRateLevel + 1.f);
	}
	else if (fireCountdown > sf::Time::Zero)
	{
		fireCountdown -= dt;
	}

	if (isLaunchingMissile)
	{
		commands.push(missileCommand);
		playLocalSound(commands, SoundEffectID::LaunchMissile);
	}

	isLaunchingMissile = false;
	isFiring = false;
}



void Aircraft::checkPickupDrop(CommandQueue& commands)
{
	if (!isAllied() && randomInt(3) == 0)
	{
		commands.push(dropPickupCommand);
	}
}



void Aircraft::createBullets(SceneNode& node, const TextureHolder_t& textures) const
{
	auto type{ isAllied() ? Projectile::Type::AlliedBullet : Projectile::Type::EnemyBullet };

	switch (spreadLevel)
	{
	case 1:
		createProjectile(node, type, 0.0f, 0.5f, textures);
		break;

	case 2:
		createProjectile(node, type, -0.33f, 0.33f, textures);
		createProjectile(node, type, 0.33f, 0.33f, textures);
		break;

	case 3:
		createProjectile(node, type, -0.5f, 0.33f, textures);
		createProjectile(node, type, 0.0f, 0.5f, textures);
		createProjectile(node, type, 0.5f, 0.33f, textures);
		break;

	default:
		createProjectile(node, type, 0.0f, 0.5f, textures);
		break;


	}
}



void Aircraft::createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder_t& textures) const
{
	auto projectile{ std::make_unique<Projectile>(type, textures) };

	sf::Vector2f offset(xOffset * sprite.getGlobalBounds().width, yOffset * sprite.getGlobalBounds().height);
	sf::Vector2f velocity(0, projectile->getMaxSpeed());

	auto sign{ isAllied() ? -1.f : 1.f };
	projectile->setPosition(getWorldPosition() + offset * sign);
	projectile->setVelocity(velocity * sign);
	projectile->setRotation(getRotation() * sign);
	node.attachChild(std::move(projectile));
}



void Aircraft::createPickup(SceneNode& node, const TextureHolder_t& textures) const
{
	Pickup::Type type{ randomInt(static_cast<int>(Pickup::Type::TypeCount)) };

	auto pickup{ std::make_unique<Pickup>(type, textures) };

	pickup->setPosition(getWorldPosition());
	pickup->setVelocity(0.f, 1.f);
	node.attachChild(std::move(pickup));
}