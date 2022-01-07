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



class SoundPlayer;



class SoundNode : public SceneNode
{
public:
	explicit 		SoundNode(SoundPlayer& player);

	void			playSound(SoundEffectID sound, sf::Vector2f position);

	unsigned int	getCategory() const override;

private:
	SoundPlayer&	sounds;
};
