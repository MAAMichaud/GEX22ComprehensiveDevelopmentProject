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
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Text.hpp>



class string;



class TextNode : public SceneNode
{
public:
	explicit				TextNode(const FontHolder_t& fonts, const std::string& text);
	void					setString(const std::string& text);

private:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Text				text;

};
