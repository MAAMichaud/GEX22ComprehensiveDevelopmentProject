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
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	sf::Sprite						sprite;
	sf::Vector2f					velocity;
	Type							type;
	Animation2						animation;
	std::map<Direction, Animation2>	animations;
	Direction						direction;

};
