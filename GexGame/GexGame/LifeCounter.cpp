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
#include "LifeCounter.h"
#include "TextNode.h"



LifeCounter::LifeCounter(const FontHolder_t& fonts, int initialLives)
	: lifeDisplay(nullptr)
	, lifeCount(initialLives)
{
	auto lifeNode{ std::make_unique<TextNode>(fonts, std::to_string(initialLives))};
	lifeDisplay = lifeNode.get();
	attachChild(std::move(lifeNode));
}



void LifeCounter::loseLife()
{
	lifeCount -= 1;
	lifeDisplay->setString(std::to_string(lifeCount));
}



bool LifeCounter::hasLivesRemaining() const
{
	return lifeCount > 0;
}
