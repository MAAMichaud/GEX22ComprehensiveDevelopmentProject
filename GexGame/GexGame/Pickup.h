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
#include "Entity.h"
#include "ResourceIdentifiers.h"
#include <SFML/Graphics/Sprite.hpp>

class Aircraft;



class Pickup : public Entity
{
public:
	enum class Type
	{
		HealthRefill = 0,
		MissileRefill,
		FireSpread,
		FireRate,
		TypeCount,
	};

public:
								Pickup(Pickup::Type type, const TextureHolder_t& textures);

	virtual unsigned int		getCategory() const override;
	virtual sf::FloatRect		getBoundingRect() const override;

	void						apply(Aircraft& player) const;

protected:
	virtual void				drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Pickup::Type				type;
	sf::Sprite					sprite;

};
