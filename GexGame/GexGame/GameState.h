
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
#include "World.h"

#include <SFML/System/Time.hpp>



class PlayerControl;



class GameState : public State
{
public:
						GameState(StateStack& stack, Context context, StateID stateId);

	virtual void		draw() override;
	virtual bool		update(sf::Time dt) override;
	virtual bool		handleEvent(const sf::Event& event) override;

private:
	void				processInput();
	World::Type			getWorldType(StateID stateId);

private:
	World				world;
	PlayerControl&		player;
	static const sf::Time	TIME_PER_FRAME;

};
