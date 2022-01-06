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



class Entity : public SceneNode
{
public:
	Entity(int _hitPoints);

	void				setVelocity(sf::Vector2f v);
	void				setVelocity(float vx, float vy);
	virtual void		accelerate(sf::Vector2f v);
	virtual void		accelerate(float vx, float vy);
	sf::Vector2f		getVelocity() const;

	int					getHitPoints() const;
	virtual void		damage(int points);
	void				repair(int points);
	void				destroy();
	virtual bool		isDestroyed() const;

	virtual void		remove();

protected:
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	sf::Vector2f		velocity;
	int					hitPoints;

};

