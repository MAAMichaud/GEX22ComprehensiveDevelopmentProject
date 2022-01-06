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
#include "Pickup.h"
#include "Utility.h"
#include "Aircraft.h"
#include "ResourceHolder.h"
#include "DataTables.h"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>



namespace
{
	const auto PICKUP_TABLE{ initializePickupData() };
}



Pickup::Pickup(Pickup::Type _type, const TextureHolder_t& textures)
	: Entity(1)
	, type(_type)
	, sprite(textures.get(PICKUP_TABLE.at(_type).texture), PICKUP_TABLE.at(_type).textureRect)
{
	centerOrigin(sprite);
}



unsigned int Pickup::getCategory() const
{
	return Category::Pickup;
}



sf::FloatRect Pickup::getBoundingRect() const
{
	return getWorldTransform().transformRect(sprite.getGlobalBounds());
}



void Pickup::apply(Aircraft& player) const
{
	PICKUP_TABLE.at(type).action(player);
}



void Pickup::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
