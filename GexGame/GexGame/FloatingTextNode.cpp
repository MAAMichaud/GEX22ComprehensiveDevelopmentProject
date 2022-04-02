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
#include "FloatingTextNode.h"



namespace
{
	static const auto FLOAT_SPEED{ 8.f };
	static const auto FADE_SPEED{ 0.005f };
}



FloatingTextNode::FloatingTextNode(const FontHolder_t& fonts, const std::string& _text, const sf::Color color) 
	: TextNode(fonts, _text)
{
	text.setFillColor(color);

	static const auto xOffset{ 36.f };

	auto initialPosition{ getPosition() };
	initialPosition.x += xOffset;
	setPosition(initialPosition);
}



void FloatingTextNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	driftUp(dt);
	fadeColor(dt);
}



bool FloatingTextNode::isDestroyed() const
{
	return text.getFillColor().a < 0.01;
}



void FloatingTextNode::driftUp(sf::Time dt)
{
	auto floatPosition{ getPosition() };
	//floatPosition.y -= dt.asSeconds() * FLOAT_SPEED;
	floatPosition.y -= dt.asSeconds() * FLOAT_SPEED;
	setPosition(floatPosition);
}



void FloatingTextNode::fadeColor(sf::Time dt)
{
	auto fadedColor{ text.getFillColor() };
	const auto MULTIPLIER{ 255 / fadedColor.a };
	fadedColor.a -= dt.asSeconds() * FADE_SPEED * MULTIPLIER;
	text.setFillColor(fadedColor);
}