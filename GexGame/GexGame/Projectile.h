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

#include "DataTables.h"
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>



class Projectile: public SceneNode
{
public:
									Projectile(const TextureHolder_t& textures, ProjectileType projectileType, sf::Time lifeSpan);

private:
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands) override;
	virtual bool					isDestroyed() const override;
	bool							isOnTarget() const;
	void							pointToTarget();

private:
	sf::Sprite						sprite;
	sf::Time						timeRemaining;
	float							timeRatio;

};
