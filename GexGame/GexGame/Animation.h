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

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>



class Animation : public sf::Drawable, public sf::Transformable
{
public:
							Animation();
	explicit 				Animation(const sf::Texture& texture);

	void 					setTexture(const sf::Texture& texture);
	const sf::Texture*		getTexture() const;

	void 					setFrameSize(sf::Vector2i frameSize);
	sf::Vector2i		 	getFrameSize() const;

	void 					setNumFrames(std::size_t numFrames);
	std::size_t 			getNumFrames() const;

	void 					setDuration(sf::Time duration);
	sf::Time 				getDuration() const;

	void 					setRepeating(bool flag);
	bool 					isRepeating() const;

	void 					restart();
	bool 					isFinished() const;

	sf::FloatRect 			getLocalBounds() const;
	sf::FloatRect 			getGlobalBounds() const;

	void 					update(sf::Time dt);


private:
	void 					draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
	sf::Sprite 				sprite;
	sf::Vector2i 			frameSize;
	std::size_t 			numberOfFrames;
	std::size_t 			currentFrame;
	sf::Time 				duration;
	sf::Time 				elapsedTime;
	bool 					repeat;
};
