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
#include "MusicPlayer.h"
#include "PauseState.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>



PauseState::PauseState(StateStack& stack, Context context)
    : State(stack, context)
    , backgroundSprite()
    , pausedText()
    , instructionText()
{
	context.music->setPaused(true);

	pausedText.setFont(context.fonts->get(FontID::Main));
	pausedText.setString("Game Paused");
	pausedText.setCharacterSize(80);
	centerOrigin(pausedText);

	instructionText.setFont(context.fonts->get(FontID::Main));
	instructionText.setString("RESUME\n\nQUIT");
	centerOrigin(instructionText);

	sf::Vector2f viewSize = context.window->getView().getSize();
	pausedText.setPosition(0.5f * viewSize.x, 0.4f * viewSize.y);
	instructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
}



PauseState::~PauseState()
{
	getContext().music->setPaused(false);
}



void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(100, 0, 0, 150));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(pausedText);
	window.draw(instructionText);

}

bool PauseState::update(sf::Time dt)
{
    return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
	static const float RESUME_BUTTON_LEFT{ 640 };
	static const float RESUME_BUTTON_TOP{ 560 };
	static const float RESUME_BUTTON_RIGHT{ 765 };
	static const float RESUME_BUTTON_BOTTOM{ 600 };

	static const float QUIT_BUTTON_LEFT{ 640 };
	static const float QUIT_BUTTON_TOP{ 635 };
	static const float QUIT_BUTTON_RIGHT{ 720 };
	static const float QUIT_BUTTON_BOTTOM{ 665 };

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.mouseButton.x < RESUME_BUTTON_RIGHT 
				&& event.mouseButton.x > RESUME_BUTTON_LEFT
				&& event.mouseButton.y < RESUME_BUTTON_BOTTOM
				&& event.mouseButton.y > RESUME_BUTTON_TOP)
			{
				requestStackPop();
			}

			if (event.mouseButton.x < QUIT_BUTTON_RIGHT 
				&& event.mouseButton.x > QUIT_BUTTON_LEFT
				&& event.mouseButton.y < QUIT_BUTTON_BOTTOM
				&& event.mouseButton.y > QUIT_BUTTON_TOP)
			{
				requestStackClear();
				requestStackPush(StateID::Menu);
			}
		}
	}

	if (event.type != sf::Event::KeyPressed)
	{
		return false;
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		requestStackPop();
	}

	if (event.key.code == sf::Keyboard::BackSpace)
	{
		requestStackClear();
		requestStackPush(StateID::Menu);
	}

	return false;
}