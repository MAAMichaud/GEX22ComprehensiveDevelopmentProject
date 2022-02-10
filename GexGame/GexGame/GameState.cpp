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

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>



GameState::GameState(StateStack& stack, Context context, StateID stateId)
    : State(stack, context)
	, world(*context.window, *context.fonts, *context.sound, getWorldType(stateId), *context.window)
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

	/*
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
	*/

	processInput();

	return true;
}



bool GameState::handleEvent(const sf::Event& event)
{
	static const float SOUND_DOWN_BUTTON_LEFT{ 14 };
	static const float SOUND_DOWN_BUTTON_TOP{ 114 };
	static const float SOUND_DOWN_BUTTON_RIGHT{ 14 + 20 };
	static const float SOUND_DOWN_BUTTON_BOTTOM{ 114 + 41 };

	static const float SOUND_UP_BUTTON_LEFT{ 21 };
	static const float SOUND_UP_BUTTON_TOP{ 114 };
	static const float SOUND_UP_BUTTON_RIGHT{ 61 + 26 };
	static const float SOUND_UP_BUTTON_BOTTOM{ 114 + 41 };

	static const float MUSIC_DOWN_BUTTON_LEFT{ 97 };
	static const float MUSIC_DOWN_BUTTON_TOP{ 114 };
	static const float MUSIC_DOWN_BUTTON_RIGHT{ 97 + 23 };
	static const float MUSIC_DOWN_BUTTON_BOTTOM{ 114 + 41 };

	static const float MUSIC_UP_BUTTON_LEFT{ 159 };
	static const float MUSIC_UP_BUTTON_TOP{ 114 };
	static const float MUSIC_UP_BUTTON_RIGHT{ 159 + 25 };
	static const float MUSIC_UP_BUTTON_BOTTOM{ 114 + 41 };

	static const float NOVICE_WIZARD_BUTTON_LEFT{ 51 };
	static const float NOVICE_WIZARD_BUTTON_TOP{ 254 };
	static const float NOVICE_WIZARD_BUTTON_RIGHT{ 51 + 31 };
	static const float NOVICE_WIZARD_BUTTON_BOTTOM{ 254 + 56 };

	static const float NOVICE_WARRIOR_BUTTON_LEFT{ 114 };
	static const float NOVICE_WARRIOR_BUTTON_TOP{ 254 };
	static const float NOVICE_WARRIOR_BUTTON_RIGHT{ 114 + 31 };
	static const float NOVICE_WARRIOR_BUTTON_BOTTOM{ 254 + 56 };

	static const float PRESTIGE_ICE_BUTTON_LEFT{ 38 };
	static const float PRESTIGE_ICE_BUTTON_TOP{ 418 };
	static const float PRESTIGE_ICE_BUTTON_RIGHT{ 38 + 31 };
	static const float PRESTIGE_ICE_BUTTON_BOTTOM{ 418 + 56 };

	static const float PRESTIGE_FIRE_BUTTON_LEFT{ 81 };
	static const float PRESTIGE_FIRE_BUTTON_TOP{ 418 };
	static const float PRESTIGE_FIRE_BUTTON_RIGHT{ 81 + 31 };
	static const float PRESTIGE_FIRE_BUTTON_BOTTOM{ 418 + 56 };

	static const float PRESTIGE_ENERGY_BUTTON_LEFT{ 129 };
	static const float PRESTIGE_ENERGY_BUTTON_TOP{ 418 };
	static const float PRESTIGE_ENERGY_BUTTON_RIGHT{ 129 + 31 };
	static const float PRESTIGE_ENERGY_BUTTON_BOTTOM{ 418 + 56 };

	static const float START_WAVE_BUTTON_LEFT{ 7 };
	static const float START_WAVE_BUTTON_TOP{ 793 };
	static const float START_WAVE_BUTTON_RIGHT{ 7 + 180 };
	static const float START_WAVE_BUTTON_BOTTOM{ 793 + 52 };

	static const float PAUSE_BUTTON_LEFT{ 26 };
	static const float PAUSE_BUTTON_TOP{ 851 };
	static const float PAUSE_BUTTON_RIGHT{ 26 + 118 };
	static const float PAUSE_BUTTON_BOTTOM{ 851 + 48 };

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.mouseButton.x < SOUND_DOWN_BUTTON_RIGHT 
				&& event.mouseButton.x > SOUND_DOWN_BUTTON_LEFT
				&& event.mouseButton.y < SOUND_DOWN_BUTTON_BOTTOM
				&& event.mouseButton.y > SOUND_DOWN_BUTTON_TOP)
			{
				std::cout << "SOUND_DOWN Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < SOUND_UP_BUTTON_RIGHT 
				&& event.mouseButton.x > SOUND_UP_BUTTON_LEFT
				&& event.mouseButton.y < SOUND_UP_BUTTON_BOTTOM
				&& event.mouseButton.y > SOUND_UP_BUTTON_TOP)
			{
				std::cout << "SOUND_UP Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < MUSIC_DOWN_BUTTON_RIGHT 
				&& event.mouseButton.x > MUSIC_DOWN_BUTTON_LEFT
				&& event.mouseButton.y < MUSIC_DOWN_BUTTON_BOTTOM
				&& event.mouseButton.y > MUSIC_DOWN_BUTTON_TOP)
			{
				std::cout << "MUSIC_DOWN Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < MUSIC_UP_BUTTON_RIGHT 
				&& event.mouseButton.x > MUSIC_UP_BUTTON_LEFT
				&& event.mouseButton.y < MUSIC_UP_BUTTON_BOTTOM
				&& event.mouseButton.y > MUSIC_UP_BUTTON_TOP)
			{
				std::cout << "MUSIC_UP Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < NOVICE_WIZARD_BUTTON_RIGHT 
				&& event.mouseButton.x > NOVICE_WIZARD_BUTTON_LEFT
				&& event.mouseButton.y < NOVICE_WIZARD_BUTTON_BOTTOM
				&& event.mouseButton.y > NOVICE_WIZARD_BUTTON_TOP)
			{
				std::cout << "NOVICE_WIZARD Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < NOVICE_WARRIOR_BUTTON_RIGHT 
				&& event.mouseButton.x > NOVICE_WARRIOR_BUTTON_LEFT
				&& event.mouseButton.y < NOVICE_WARRIOR_BUTTON_BOTTOM
				&& event.mouseButton.y > NOVICE_WARRIOR_BUTTON_TOP)
			{
				std::cout << "NOVICE_WARRIOR Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < PRESTIGE_ICE_BUTTON_RIGHT 
				&& event.mouseButton.x > PRESTIGE_ICE_BUTTON_LEFT
				&& event.mouseButton.y < PRESTIGE_ICE_BUTTON_BOTTOM
				&& event.mouseButton.y > PRESTIGE_ICE_BUTTON_TOP)
			{
				std::cout << "PRESTIGE_ICE Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < PRESTIGE_FIRE_BUTTON_RIGHT 
				&& event.mouseButton.x > PRESTIGE_FIRE_BUTTON_LEFT
				&& event.mouseButton.y < PRESTIGE_FIRE_BUTTON_BOTTOM
				&& event.mouseButton.y > PRESTIGE_FIRE_BUTTON_TOP)
			{
				std::cout << "PRESTIGE_FIRE Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < PRESTIGE_ENERGY_BUTTON_RIGHT 
				&& event.mouseButton.x > PRESTIGE_ENERGY_BUTTON_LEFT
				&& event.mouseButton.y < PRESTIGE_ENERGY_BUTTON_BOTTOM
				&& event.mouseButton.y > PRESTIGE_ENERGY_BUTTON_TOP)
			{
				std::cout << "PRESTIGE_ENERGY Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < START_WAVE_BUTTON_RIGHT 
				&& event.mouseButton.x > START_WAVE_BUTTON_LEFT
				&& event.mouseButton.y < START_WAVE_BUTTON_BOTTOM
				&& event.mouseButton.y > START_WAVE_BUTTON_TOP)
			{
				std::cout << "START_WAVE Button Pressed." << std::endl;
			}

			if (event.mouseButton.x < PAUSE_BUTTON_RIGHT 
				&& event.mouseButton.x > PAUSE_BUTTON_LEFT
				&& event.mouseButton.y < PAUSE_BUTTON_BOTTOM
				&& event.mouseButton.y > PAUSE_BUTTON_TOP)
			{
				std::cout << "PAUSE Button Pressed." << std::endl;
				requestStackPush(StateID::Pause);
			}
		}
	}

    auto& commands{ world.getCommandQueue() };

	player.handleEvent(event, commands);

	if (event.type != sf::Event::KeyPressed)
	{
		return false;
	}

	if (event.key.code == sf::Keyboard::P)
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



LevelType GameState::getWorldType(StateID stateId)
{
	switch (stateId)
	{
	case StateID::ForestLevel:
		return LevelType::Forest;
		break;

	case StateID::CemeteryLevel:
		return LevelType::Cemetery;
		break;

	case StateID::BeachLevel:
		return LevelType::Beach;
		break;

	case StateID::MountainLevel:
		return LevelType::Mountain;
		break;

	default:
		return LevelType::Forest;
		break;

	}

	return LevelType::Forest;
}
