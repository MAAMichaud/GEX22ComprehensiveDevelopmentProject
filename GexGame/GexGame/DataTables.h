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

#include <map>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>



enum class LevelType
{
	Forest,
	Cemetery,
	Beach,
	Mountain,
};



struct LaneData
{
	sf::Vector2f									position;
	std::vector<AnimatedNode::Direction>			route;

};



struct LevelData
{
	TextureID						backgroundTexture;
	std::string						backgroundTexturePath;
	std::vector<LaneData>			lanes;

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



std::map<LevelType, LevelData> initializeLevelData();
std::map<AnimatedNode::Type, EnemyData> initializeEnemyData();
std::map<Particle::Type, ParticleData> initializeParticleData();