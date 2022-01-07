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
#include "GameState.h"
#include "MusicPlayer.h"
#include "PlayerControl.h"

#include <SFML/Graphics/RenderWindow.hpp>



GameState::GameState(StateStack& stack, Context context)
    : State(stack, context)
	, world(*context.window, *context.fonts, *context.sound)
	, player(*context.player)
{
}



void GameState::draw()
{
    world.draw();
}



bool GameState::update(sf::Time dt)
{
    world.update(dt);

	if (!world.hasAlivePlayer())
	{
		player.setMissionStatus(PlayerControl::MissionStatus::MissionFailure);
		requestStackPush(StateID::GameOver);
	}
	else if (world.hasPlayerReachedTheEnd())
	{
		player.setMissionStatus(PlayerControl::MissionStatus::MissionSuccess);
		requestStackPush(StateID::GameOver);
	}

	processInput();

	return true;
}



bool GameState::handleEvent(const sf::Event& event)
{
    auto& commands{ world.getCommandQueue() };

	player.handleEvent(event, commands);

	if (event.type != sf::Event::KeyPressed)
	{
		return false;
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		requestStackPush(StateID::Pause);
	}


    return true;
}



void GameState::processInput()
{
    auto& commands{ world.getCommandQueue() };

    player.handleRealTimeInput(commands);
}