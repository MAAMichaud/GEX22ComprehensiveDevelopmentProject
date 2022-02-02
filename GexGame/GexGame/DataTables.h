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

#include "AnimatedNode.h"
#include "Animation2.h"
#include "Particle.h"
#include "ResourceIdentifiers.h"
#include "World.h"

#include <map>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>



struct LevelData
{
	TextureID			backgroundTexture;
	std::string			backgroundTexturePath;
};



struct EnemyData
{
	TextureID										texture;
	std::map<AnimatedNode::Direction, Animation2>	animations;

};



struct ParticleData
{
	sf::Color			color;
	sf::Time			lifetime;

};



std::map<World::Type, LevelData> initializeLevelData();
std::map<AnimatedNode::Type, EnemyData> initializeEnemyData();
std::map<Particle::Type, ParticleData> initializeParticleData();
