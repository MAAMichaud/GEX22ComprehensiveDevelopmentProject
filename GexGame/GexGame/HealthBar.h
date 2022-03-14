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

#include "SceneNode.h"



class HealthBar : public SceneNode
{
public:
								HealthBar(const double maxHealth);

	void						setHealth(const double newHealth);

private:
	void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	const double				maxHealth;
	double						currentHealth;

};
