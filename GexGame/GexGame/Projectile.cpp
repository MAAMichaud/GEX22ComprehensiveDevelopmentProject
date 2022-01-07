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



Projectile::Projectile(Projectile::Type _type, const TextureHolder_t& textures)
	: Entity(1)
	, type(_type)
	, sprite()
	, targetDirection()
{
}



void Projectile::guideTowards(sf::Vector2f position)
{
}



bool Projectile::isGuided() const
{
	return false;
}



unsigned int Projectile::getCategory() const
{
	return 1;
}



sf::FloatRect Projectile::getBoundingRect() const
{
	return getWorldTransform().transformRect(sprite.getGlobalBounds());
}



float Projectile::getMaxSpeed() const
{
	return 10.f;
}



int Projectile::getDamage() const
{
	return 1;
}



void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
}



void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}