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
#include "SoundNode.h"
#include "SoundPlayer.h"



SoundNode::SoundNode(SoundPlayer& player)
	: SceneNode()
	, sounds(player)
{}



void SoundNode::playSound(SoundEffectID sound, sf::Vector2f position)
{
	sounds.play(sound, position);
}



unsigned SoundNode::getCategory() const
{
	return Category::SoundEffect;
}
