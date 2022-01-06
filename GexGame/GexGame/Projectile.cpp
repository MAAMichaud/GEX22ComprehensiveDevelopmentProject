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
#include <cassert>
#include "Projectile.h"
#include "utility.h"
#include "DataTables.h"
#include "ResourceHolder.h"
#include "EmitterNode.h"
#include <SFML/Graphics/RenderTarget.hpp>



namespace
{
	const auto PROJECTILE_TABLE{ initializeProjectileData() };
}



Projectile::Projectile(Projectile::Type _type, const TextureHolder_t& textures)
	: Entity(1)
	, type(_type)
	, sprite(textures.get(PROJECTILE_TABLE.at(_type).texture), PROJECTILE_TABLE.at(_type).textureRect)
	, targetDirection()
{
	centerOrigin(sprite);

	if (isGuided())
	{
		auto smoke{ std::make_unique<EmitterNode>(Particle::Type::Smoke) };
		smoke->setPosition(0.f, Projectile::getBoundingRect().height / 2.f);
		attachChild(std::move(smoke));

		auto propellant{ std::make_unique<EmitterNode>(Particle::Type::Propellant) };
		propellant->setPosition(0.f, Projectile::getBoundingRect().height / 2.f);
		attachChild(std::move(propellant));
	}
}



void Projectile::guideTowards(sf::Vector2f position)
{
	assert(isGuided());
	targetDirection = normalizeVector(position - getWorldPosition());
}



bool Projectile::isGuided() const
{
	return type == Type::Missile;
}



unsigned int Projectile::getCategory() const
{
	if (type == Type::EnemyBullet)
	{
		return Category::EnemyProjectile;
	}
	else
	{
		return Category::AlliedProjectile;
	}
}



sf::FloatRect Projectile::getBoundingRect() const
{
	return getWorldTransform().transformRect(sprite.getGlobalBounds());
}



float Projectile::getMaxSpeed() const
{
	return PROJECTILE_TABLE.at(type).speed;
}



int Projectile::getDamage() const
{
	return PROJECTILE_TABLE.at(type).damage;
}



void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (isGuided())
	{
		static const float APPROACH_RATE{ 200.f };

		auto newVelocity{ normalizeVector(APPROACH_RATE *
			dt.asSeconds() * targetDirection + getVelocity()) };

		newVelocity *= getMaxSpeed();

		const float ANGLE{ gex::atan2(newVelocity.y, newVelocity.x) };

		setRotation(ANGLE + 90.f);
		setVelocity(newVelocity);
	}

	Entity::updateCurrent(dt, commands);

	/*
	if (isDestroyed())
	{
		setMarkedForRemoval(true);
	}
	*/
}



void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}