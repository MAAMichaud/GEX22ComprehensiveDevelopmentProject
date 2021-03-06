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

/*
#include "Animation2.h"
#include "DataTables.h"
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>



const sf::Time HOP_DURATION = sf::seconds(1.0f);

const float HORIZONTAL_HOP_LENGTH = 18.f;
const float VERTICAL_HOP_LENGTH = 12.f;
const float HORIZONTAL_HOP_PER_FRAME = (HORIZONTAL_HOP_LENGTH / HOP_DURATION.asSeconds());
const float VERTICAL_HOP_PER_FRAME = (VERTICAL_HOP_LENGTH / HOP_DURATION.asSeconds());

class AnimatedNode: public SceneNode
{
public:
									AnimatedNode(const TextureHolder_t& textures, EnemyData enemyData, std::vector<Direction>& route);

private:
	void							turn(Direction direction);
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands) override;
	virtual bool					isDestroyed() const override;

private:
	sf::Sprite						sprite;
	sf::Vector2f					velocity;
	sf::Vector2f					bearing;
	std::map<Direction, Animation2>	animations;
	Direction						direction;
	const sf::Time					movementSpeed;
	sf::Time						timeRemaining;
	std::vector<Direction>&			route;
	std::size_t						routeIndex;

};
*/
