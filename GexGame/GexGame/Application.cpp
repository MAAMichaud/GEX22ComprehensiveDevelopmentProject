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
#include "Application.h"
#include "GameOverState.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "State.h"
#include "StateIdentifiers.h"
#include "StateStack.h"
#include "TitleState.h"

#include <SFML/Window/Event.hpp>



const sf::Time Application::TIME_PER_FRAME{ sf::seconds(1.f / 60.f) };



Application::Application()
    : window(sf::VideoMode(1524, 912), "Defenders of Ragnar", sf::Style::Close)
	, textures()
	, fonts()
	, player()
	, music()
	, sound()
	, stateStack(State::Context(window, textures, fonts, player, music, sound))
	, statisticsText()
	, statisticsUpdateTime()
	, statisticsNumFrames(0)
{
	window.setKeyRepeatEnabled(false);

	fonts.load(FontID::Main, "../Media/Sansation.ttf");
	textures.load(TextureID::TitleScreen, "../Media/Textures/GEX.png");
	textures.load(TextureID::MainMenu, "../Media/Textures/MainMenu.png");
	textures.load(TextureID::OnebyOne, "../Media/Textures/1by1.png");
	textures.load(TextureID::ThreebyThree, "../Media/Textures/3by3.png");
	textures.load(TextureID::FivebyFive, "../Media/Textures/5by5.png");
	textures.load(TextureID::SevenbySeven, "../Media/Textures/7by7.png");

	statisticsText.setFont(fonts.get(FontID::Main));
	statisticsText.setPosition(15.0f, 15.0f);
	statisticsText.setCharacterSize(15);

	registerStates();
	stateStack.pushState(StateID::Title);
}



void Application::registerStates()
{
	stateStack.registerState<TitleState>(StateID::Title);
	stateStack.registerState<MenuState>(StateID::Menu);
	stateStack.registerState<PauseState>(StateID::Pause);
	stateStack.registerState<GameOverState>(StateID::GameOver);
	stateStack.registerLevelState<GameState>(StateID::ForestLevel);
	stateStack.registerLevelState<GameState>(StateID::CemeteryLevel);
	stateStack.registerLevelState<GameState>(StateID::BeachLevel);
	stateStack.registerLevelState<GameState>(StateID::MountainLevel);
}



void Application::processInput()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		stateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}



void Application::update(sf::Time dt)
{
	stateStack.update(dt);

	if (stateStack.isEmpty())
	{
		window.close();
	}
}



void Application::updateStatistics(sf::Time dt)
{
	statisticsUpdateTime += dt;
	statisticsNumFrames += 1;
	if (statisticsUpdateTime >= sf::seconds(1.0f))
	{
		statisticsText.setString("FPS: " + std::to_string(statisticsNumFrames));

		statisticsUpdateTime -= sf::seconds(1.0f);
		statisticsNumFrames = 0;
	}
}



void Application::draw()
{
	window.clear();
	stateStack.draw();

	window.setView(window.getDefaultView());
	window.draw(statisticsText);

	window.display();
}



void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate{ sf::Time::Zero };

    while (window.isOpen())
    {
        sf::Time elapsedTime{ clock.restart() };
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
			processInput();

			update(TIME_PER_FRAME);

			if (stateStack.isEmpty())
			{
				window.close();
			}
        }

		updateStatistics(elapsedTime);
        draw();
    }
}