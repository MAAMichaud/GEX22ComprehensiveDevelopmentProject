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
#include "SpriteNode.h"

#include <SFML/Graphics/RenderTarget.hpp>



SpriteNode::SpriteNode(const sf::Texture& texture) :
	sprite(texture)
{
}



SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect) :
	sprite(texture, textureRect)
{
}



void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
