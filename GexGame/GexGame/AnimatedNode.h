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

#include <string>


class AnimatedNode: public SceneNode
{
public:
	explicit			AnimatedNode(const TextureHolder_t& textures, std::string name);


private:
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	sf::Sprite			sprite;
	Animation2			animation;

};
