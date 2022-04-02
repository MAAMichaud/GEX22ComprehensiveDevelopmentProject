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

#include "TextNode.h"



class string;



class FloatingTextNode : public TextNode
{
public:
	explicit						FloatingTextNode(const FontHolder_t& fonts, const std::string& text, const sf::Color color);

private:
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual bool					isDestroyed() const;
	void							driftUp(sf::Time dt);
	void							fadeColor(sf::Time dt);

};

