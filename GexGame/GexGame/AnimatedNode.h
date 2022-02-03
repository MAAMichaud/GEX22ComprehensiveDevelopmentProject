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

#include "Animation2.h"
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>



const sf::Time HOP_DURATION = sf::seconds(1.0f);
const float HORIZONTAL_HOP_LENGTH = 36.f;
const float VERTICAL_HOP_LENGTH = 24.f;
const float HORIZONTAL_HOP_PER_FRAME = (HORIZONTAL_HOP_LENGTH / HOP_DURATION.asSeconds());
const float VERTICAL_HOP_PER_FRAME = (VERTICAL_HOP_LENGTH / HOP_DURATION.asSeconds());

class AnimatedNode: public SceneNode
{
public:
	enum class Type 
	{
		Lich,
	};

	enum class Direction 
	{
		UpRight,
		DownRight,
		DownLeft,
		UpLeft
	};


public:
	explicit			AnimatedNode(const TextureHolder_t& textures, Type type);


private:
	void				turn(Direction direction);
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	sf::Sprite						sprite;
	sf::Vector2f					velocity;
	sf::Vector2f					bearing;
	const Type						type;
	Animation2						animation;
	std::map<Direction, Animation2>	animations;
	Direction						direction;
	const sf::Time					movementSpeed;
	sf::Time						timeRemaining;

};
