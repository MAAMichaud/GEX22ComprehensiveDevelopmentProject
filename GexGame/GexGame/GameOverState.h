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

#include "State.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>



class GameOverState : public State
{
public:

	GameOverState( StateStack& stack, Context context);


	void					draw() override;
	bool					update(sf::Time dt) override;
	bool					handleEvent(const sf::Event& event) override;

private:

	sf::Text				gameOverText;
	sf::Time				elapsedTime;

};
