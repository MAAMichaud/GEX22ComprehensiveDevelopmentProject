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
#include "Animation2.h"

#include <cassert>



Animation2::Animation2(bool _repeat, sf::Time _duration)
	: currentFrame(0)
	, duration(_duration)
	, elapsedTime(sf::Time::Zero)
	, repeat(_repeat)
{
}



void Animation2::addFrame(Frame f)
{
	frames.emplace_back(f);
}



void Animation2::addFrameSet(std::vector<Frame> f )
{
	frames = f ;
}



void Animation2::setDuration(sf::Time d )
{
	duration = d ;
}



sf::Time Animation2::getDuration() const
{
	return duration;
}



void Animation2::setRepeating(bool flag)
{
	repeat = flag;
}



bool Animation2::isRepeating() const
{
	return repeat;
}



void Animation2::restart()
{
	currentFrame = 0;
}



bool Animation2::isFinished() const
{
	return (!repeat && currentFrame >= frames.size());
}



Frame Animation2::getCurrentFrame() const
{
	return frames[currentFrame >= frames.size() ? frames.size() - 1 : currentFrame];
}



Frame Animation2::update(sf::Time dt)
{
	if (frames.size() <= 0)
	{
		return Frame();
	}

	sf::Time timePerFrame = duration / static_cast<float>(frames.size());
	elapsedTime += dt;

	// While we have a frame to process
	while (elapsedTime >= timePerFrame && (currentFrame < frames.size() || repeat))
	{
		// And progress to next frame
		elapsedTime -= timePerFrame;
		currentFrame++;
		if (repeat)
		{
			currentFrame %= frames.size();
		}
	}
	return getCurrentFrame();
}