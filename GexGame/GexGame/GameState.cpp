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
#include "utility.h"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>



GameState::GameState(StateStack& stack, Context context, StateID stateId)
    : State(stack, context)
	, world(*context.window, *context.fonts, *context.sound, getWorldType(stateId), *context.window)
	, player(*context.player)
	, musicPlayer(*context.music)
{
	context.music->play(MusicID::LevelMusic);
}



void GameState::draw()
{
    world.draw();
}



bool GameState::update(sf::Time dt)
{
    world.update(dt);

	if (world.gameWon())
	{
		player.setMissionStatus(PlayerControl::MissionStatus::MissionSuccess);
		requestStackPush(StateID::GameOver);
	}
	else if (world.gameLost())
	{
		player.setMissionStatus(PlayerControl::MissionStatus::MissionFailure);
		requestStackPush(StateID::GameOver);
	}

	processInput();

	return true;
}



bool GameState::handleEvent(const sf::Event& event)
{
	static const sf::IntRect SOUND_DOWN_RECT{ 14, 114, 20, 41 };
	static const sf::IntRect SOUND_UP_RECT{ 61, 114, 25, 41 };
	static const sf::IntRect MUSIC_DOWN_RECT{ 97, 114, 23, 41 };
	static const sf::IntRect MUSIC_UP_RECT{ 159, 114, 25, 41 };
	static const sf::IntRect NOVICE_WIZARD_RECT{ 51, 254, 31, 56 };
	static const sf::IntRect CLUB_WARRIOR_RECT{ 114, 254, 31, 56 };
	static const sf::IntRect PRESTIGE_ICE_RECT{ 38, 418, 31, 56 };
	static const sf::IntRect PRESTIGE_FIRE_RECT{ 81, 418, 31, 56 };
	static const sf::IntRect PRESTIGE_ENERGY_RECT{ 129, 418, 31, 56 };
	static const sf::IntRect START_WAVE_RECT{ 7, 793, 180, 52 };
	static const sf::IntRect PAUSE_BUTTON_RECT{ 26, 851, 118, 48 };


	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			const auto mousePosition{ sf::Vector2i(event.mouseButton.x, event.mouseButton.y) };

			if (isMouseOverRect(mousePosition, SOUND_DOWN_RECT))
			{
				std::cout << "SOUND_DOWN Button Pressed." << std::endl;
				world.soundDown();
			}

			else if (isMouseOverRect(mousePosition, SOUND_UP_RECT))
			{
				std::cout << "SOUND_UP Button Pressed." << std::endl;
				world.soundUp();
			}

			else if (isMouseOverRect(mousePosition, MUSIC_DOWN_RECT))
			{
				std::cout << "MUSIC_DOWN Button Pressed." << std::endl;
				musicPlayer.volumeDown();
			}

			else if (isMouseOverRect(mousePosition, MUSIC_UP_RECT))
			{
				std::cout << "MUSIC_UP Button Pressed." << std::endl;
				musicPlayer.volumeUp();
			}

			else if (isMouseOverRect(mousePosition, NOVICE_WIZARD_RECT))
			{
				std::cout << "NOVICE_WIZARD Button Pressed." << std::endl;
				world.selectTower(World::State::BuildWizard);
			}

			else if (isMouseOverRect(mousePosition, CLUB_WARRIOR_RECT))
			{
				std::cout << "CLUB_WARRIOR Button Pressed." << std::endl;
				world.selectTower(World::State::BuildWarrior);
			}

			else if (isMouseOverRect(mousePosition, PRESTIGE_ICE_RECT))
			{
				std::cout << "PRESTIGE_ICE Button Pressed." << std::endl;
				world.selectTower(World::State::BuildIce);
			}

			else if (isMouseOverRect(mousePosition, PRESTIGE_FIRE_RECT))
			{
				std::cout << "PRESTIGE_FIRE Button Pressed." << std::endl;
				world.selectTower(World::State::BuildFire);
			}

			else if (isMouseOverRect(mousePosition, PRESTIGE_ENERGY_RECT))
			{
				std::cout << "PRESTIGE_ENERGY Button Pressed." << std::endl;
				world.selectTower(World::State::BuildEnergy);
			}

			else if (isMouseOverRect(mousePosition, START_WAVE_RECT))
			{
				std::cout << "START_WAVE Button Pressed." << std::endl;
				world.startWave();
			}

			else if (isMouseOverRect(mousePosition, PAUSE_BUTTON_RECT))
			{
				std::cout << "PAUSE Button Pressed." << std::endl;
				requestStackPush(StateID::Pause);
			}
			else
			{
				world.boardClicked();
			}
		}
	}

    auto& commands{ world.getCommandQueue() };

	player.handleEvent(event, commands);

	if (event.type != sf::Event::KeyPressed)
	{
		return false;
	} 
	else if (event.key.code == sf::Keyboard::P)
	{
		requestStackPush(StateID::Pause);
	}
	else if (event.key.code == sf::Keyboard::G)
	{
		world.addGold(100);
	}
	else if (event.key.code == sf::Keyboard::Escape)
	{
		world.cancel();
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
