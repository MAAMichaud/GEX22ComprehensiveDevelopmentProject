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
#include "AnimatedNode.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include "JsonFrameParser.h"
#include "Animation2.h"
#include "utility.h"
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>


AnimatedNode::AnimatedNode(const TextureHolder_t& textures, std::string name)
	: sprite(textures.get(TextureID::Lich))
	, animation()
{
	static JsonFrameParser frames{ JsonFrameParser("../Media/Textures/LichAtlasFlipped.json") };

	animation.addFrameSet(frames.getFramesFor(name));
	animation.setDuration(sf::seconds(1.0f));
	animation.setRepeating(true);
	animation.restart();
	sprite.setTextureRect(animation.getCurrentFrame().intRect);
}



void AnimatedNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



void AnimatedNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	auto frame = animation.update(dt);

	sprite.setTextureRect(frame.intRect);
	sprite.setPosition(frame.offset.first, frame.offset.second);

}
