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
#include "TextNode.h"
#include "CommandQueue.h"
#include "Projectile.h"
#include "Pickup.h"
#include "Animation.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>



class Aircraft : public Entity
{
public:
	enum class Type
	{
		Eagle,
		Raptor,
		Avenger,
	};

public:
							Aircraft(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts);

	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual unsigned int	getCategory() const override;

	void					fire();
	void					launchMissile();
	bool					isAllied() const;
	void					playLocalSound(CommandQueue& commands, SoundEffectID effect);

	void					collectMissiles(unsigned int count);
	void					increaseSpread();
	void					increaseFireRate();

	virtual sf::FloatRect	getBoundingRect() const override;

	void					remove() override;
	bool					isMarkedForRemoval() const override;

private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands) override;
	void					updateRollAnimation();

	float					getMaxSpeed() const;
	void					updateMovementPattern(sf::Time dt);
	void					instantiateTexts(const FontHolder_t& fonts);
	void					updateTexts();

	void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);
	void					checkPickupDrop(CommandQueue& commands);
	void					createBullets(SceneNode& node, const TextureHolder_t& textures) const;
	void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder_t& textures) const;
	void					createPickup(SceneNode& node, const TextureHolder_t& textures) const;

private:
	Type					type;
	sf::Sprite				sprite;

	Animation				explosion;
	bool					showExplosion;
	bool					hasSpawnedPickup;
	bool					hasPlayedExplosionSound;

	int						missileAmmo;
	int						spreadLevel;
	int						fireRateLevel;

	std::size_t				directionIndex;
	float					travelledDistance;

	Command					fireCommand;
	Command					missileCommand;
	Command					dropPickupCommand;
	sf::Time				fireCountdown;

	bool					isFiring;
	bool					isLaunchingMissile;
	bool					_isMarkedForRemoval;

	TextNode*				healthDisplay;
	TextNode*				missileDisplay;

};

