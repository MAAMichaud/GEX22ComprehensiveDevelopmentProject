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
#include "Projectile.h"
#include "utility.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>



Projectile::Projectile(const TextureHolder_t& textures, ProjectileType projectileType)
	: sprite(textures.get(TextureID::Spells))
	, timeRemaining(sf::seconds(0.8f))
	, timeRatio(sf::seconds(timeRemaining / timeRemaining) / timeRemaining)
{
	switch (projectileType)
	{
	case ProjectileType::MagicArrow:
		sprite.setTextureRect(sf::IntRect(22 * 0, 0, 22, 30));
		break;

	case ProjectileType::IceBall:
		sprite.setTextureRect(sf::IntRect(22 * 1, 0, 22, 30));
		break;

	case ProjectileType::Fireball:
		sprite.setTextureRect(sf::IntRect(22 * 2, 0, 22, 30));
		break;

	case ProjectileType::Lightning:
		sprite.setTextureRect(sf::IntRect(22 * 3, 0, 22, 30));
		break;

	case ProjectileType::Poison:
		sprite.setTextureRect(sf::IntRect(22 * 4, 0, 22, 30));
		break;

	default:
		sprite.setTextureRect(sf::IntRect(22 * 0, 0, 22, 30));
		break;

	}
	centerOrigin(sprite);
}



void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (!isOnTarget())
	{
		pointToTarget();

		const auto ratio{ dt.asSeconds() / timeRemaining.asSeconds() };

		const auto [pixelX, pixelY] { getPosition() };

		move(-(pixelX) * ratio, -(pixelY) * ratio);

		timeRemaining -= dt;
	}
}



bool Projectile::isDestroyed() const
{
	return isOnTarget();
}



bool Projectile::isOnTarget() const
{
	const auto [pixelX, pixelY] { getPosition() };

	return abs(pixelX) < 2.0f && abs(pixelY) < 2.0f;
}



void Projectile::pointToTarget()
{
	const auto [pixelX, pixelY] { getPosition() };

	setRotation(radToDeg(std::atan2(pixelX * -1, pixelY)));
}



void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}