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

#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "Aircraft.h"
#include "Pickup.h"
#include "Projectile.h"
#include "Particle.h"
#include "Actor.h"
#include <functional>
#include <map>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>



struct Direction
{
	Direction(float _angle, float _distance);
	float				angle;
	float				distance;

};



struct AircraftData
{
	int						hitpoints;
	float					speed;
	TextureID				texture;
	sf::IntRect				textureRect;
	sf::Time				fireInterval;
	std::vector<Direction>	directions;
	bool					hasRollAnimation = false;

};



struct ProjectileData
{
	int					damage;
	float				speed;
	TextureID			texture;
	sf::IntRect			textureRect;

};



struct PickupData
{
	std::function<void(Aircraft&)>	action;
	TextureID						texture;
	sf::IntRect						textureRect;

};



struct ParticleData
{
	sf::Color			color;
	sf::Time			lifetime;

};



struct ActorData
{
	int										hitpoints;
	int										damageDone;
	float									speed;
	TextureID								texture;
	std::map<Actor::State, Animation2>		animations;
	std::vector<Direction>					directions;

};



std::map<Aircraft::Type, AircraftData> initializeAircraftData();

std::map<Projectile::Type, ProjectileData> initializeProjectileData();

std::map<Pickup::Type, PickupData> initializePickupData();

std::map<Particle::Type, ParticleData> initializeParticleData();

std::map<Actor::Type, ActorData> initializeActorData();
