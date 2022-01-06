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
#include "CommandQueue.h"
#include <SFML/Graphics/Sprite.hpp>



class Projectile : public Entity
{
public:
	enum class Type
	{
		AlliedBullet,
		EnemyBullet,
		Missile,
	};

public:
								Projectile(Projectile::Type type, const TextureHolder_t& textures);

	void						guideTowards(sf::Vector2f position);
	bool						isGuided() const;

	virtual unsigned int		getCategory() const;
	virtual sf::FloatRect		getBoundingRect() const override;

	float						getMaxSpeed() const;
	int							getDamage() const;

private:
	virtual void				updateCurrent(sf::Time dt, CommandQueue& commands) override;
	virtual void				drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Projectile::Type			type;
	sf::Sprite					sprite;
	sf::Vector2f				targetDirection;

};
