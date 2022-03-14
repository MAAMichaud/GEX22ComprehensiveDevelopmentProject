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
#include "HealthBar.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>



HealthBar::HealthBar(const double _maxHealth)
	: maxHealth(_maxHealth)
	, currentHealth(_maxHealth)
{
}



void HealthBar::setHealth(const double newHealth)
{
	currentHealth = newHealth;
}



void HealthBar::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle;
	sf::Vector2f size;
	size.y = 4.f;
	size.x = fmax(0.f, 52.f * (currentHealth / maxHealth));
	rectangle.setSize(size);

	rectangle.setFillColor(sf::Color(255, 0, 0));

	rectangle.setPosition(20.f, 0.f);
	target.draw(rectangle, states);
}
