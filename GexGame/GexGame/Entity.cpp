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
#include "CommandQueue.h"
#include "Entity.h"

#include <cassert>



Entity::Entity(const int _hitPoints)
	: velocity()
	, hitPoints(_hitPoints)
{
}



void Entity::setVelocity(const sf::Vector2f v)
{
	velocity = v;
}



void Entity::setVelocity(const float vx, const float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}



void Entity::accelerate(const sf::Vector2f v)
{
	velocity += v;
}



void Entity::accelerate(const float vx, const float vy)
{
	accelerate(sf::Vector2f(vx, vy));
}



sf::Vector2f Entity::getVelocity() const
{
	return velocity;
}



int Entity::getHitPoints() const
{
	return hitPoints;
}



void Entity::damage(const int points)
{
	assert(points > 0);
	hitPoints -= points;
}



void Entity::repair(const int points)
{
	assert(points > 0);
	hitPoints += points;
}



void Entity::destroy()
{
	hitPoints = 0;
}



bool Entity::isDestroyed() const
{
	return hitPoints <= 0;
}



void Entity::remove()
{
	destroy();
}



void Entity::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	move(velocity * dt.asSeconds());
}