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

#include "Particle.h"
#include "ResourceIdentifiers.h"

#include <map>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>



struct ParticleData
{
	sf::Color			color;
	sf::Time			lifetime;

};

std::map<Particle::Type, ParticleData> initializeParticleData();
