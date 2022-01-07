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
#include "Particle.h"
#include <map>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>



struct ParticleData
{
	sf::Color			color;
	sf::Time			lifetime;

};

std::map<Particle::Type, ParticleData> initializeParticleData();
