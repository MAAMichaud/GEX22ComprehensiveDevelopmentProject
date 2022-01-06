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
#include "TextNode.h"
#include "utility.h"
#include "ResourceHolder.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>



TextNode::TextNode(const FontHolder_t& fonts, const std::string& _text)
	: text()
{
	text.setFont(fonts.get(FontID::Main));
	text.setCharacterSize(20);
	setString(_text);
}



void TextNode::setString(const std::string& _text)
{
	text.setString(_text);
	centerOrigin(text);
}



void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text, states);
}
