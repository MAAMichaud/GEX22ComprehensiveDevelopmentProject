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
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"



class TextNode;



class LifeCounter : public SceneNode
{
public:
								LifeCounter(const FontHolder_t& fonts, int initialLives = 60);

	void						loseLife();
	bool						hasLivesRemaining();

private:
	TextNode*					lifeDisplay;
	int							lifeCount;

};
