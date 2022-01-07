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

#include <SFML/Graphics/Sprite.hpp>



class SpriteNode : public SceneNode
{
public:
	explicit			SpriteNode(const sf::Texture& texture);
						SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);

private:
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite			sprite;

};
