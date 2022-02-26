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

#include "JsonFrameParser.h"

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>



//
// An animaiton is a collection of frames. 
// 


class Animation2
{
public:
	explicit 					Animation2(bool repeat = true, sf::Time duration = sf::seconds(1.0f));

	void						addFrame(Frame frame);
	void						addFrameSet(std::vector<Frame> frames);
	void 						setDuration(sf::Time d);
	sf::Time 					getDuration() const;

	void 						setRepeating(bool flag);
	bool 						isRepeating() const;

	void 						restart();
	bool 						isFinished() const;

	Frame						getCurrentFrame() const;

	Frame 						update(sf::Time dt);

public:
	std::vector<Frame>			frames;
	std::size_t					currentFrame;
	sf::Time					elapsedTime;
	sf::Time					duration;
	//sf::Time					timePerFrame;
	bool						repeat;

};
