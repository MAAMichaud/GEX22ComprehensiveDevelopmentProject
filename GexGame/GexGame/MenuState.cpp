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
#include "MenuState.h"
#include "MusicPlayer.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "State.h"
#include "StateIdentifiers.h"
#include "Utility.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
{
	sf::Texture& texture = context.textures->get(TextureID::MainMenu);

	backgroundSprite.setTexture(texture);
}



void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(backgroundSprite);
}



bool MenuState::update(sf::Time dt)
{
	return true;
}



bool MenuState::handleEvent(const sf::Event& event)
{
	static const float THUMBNAIL_WIDTH{ 317 };
	static const float THUMBNAIL_HEIGHT{ 211 };

	static const float FOREST_LEVEL_LEFT{ 217 };
	static const float FOREST_LEVEL_TOP{ 211 };

	static const float CEMETERY_LEVEL_LEFT{ 971 };
	static const float CEMETERY_LEVEL_TOP{ 211 };

	static const float BEACH_LEVEL_LEFT{ 217 };
	static const float BEACH_LEVEL_TOP{ 633 };

	static const float MOUNTAIN_LEVEL_LEFT{ 971 };
	static const float MOUNTAIN_LEVEL_TOP{ 633 };

	static const float QUIT_BUTTON_LEFT{ 700 };
	static const float QUIT_BUTTON_TOP{ 780 };
	static const float QUIT_BUTTON_RIGHT{ 820 };
	static const float QUIT_BUTTON_BOTTOM{ 850 };

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (event.mouseButton.x < THUMBNAIL_WIDTH + FOREST_LEVEL_LEFT 
				&& event.mouseButton.x > FOREST_LEVEL_LEFT
				&& event.mouseButton.y < THUMBNAIL_HEIGHT + FOREST_LEVEL_TOP
				&& event.mouseButton.y > FOREST_LEVEL_TOP)
			{
				requestStackPop();
				requestStackPush(StateID::ForestLevel);
			}

			if (event.mouseButton.x < THUMBNAIL_WIDTH + CEMETERY_LEVEL_LEFT 
				&& event.mouseButton.x > CEMETERY_LEVEL_LEFT
				&& event.mouseButton.y < THUMBNAIL_HEIGHT + CEMETERY_LEVEL_TOP
				&& event.mouseButton.y > CEMETERY_LEVEL_TOP)
			{
				requestStackPop();
				requestStackPush(StateID::CemeteryLevel);
			}

			if (event.mouseButton.x < THUMBNAIL_WIDTH + BEACH_LEVEL_LEFT 
				&& event.mouseButton.x > BEACH_LEVEL_LEFT
				&& event.mouseButton.y < THUMBNAIL_HEIGHT + BEACH_LEVEL_TOP
				&& event.mouseButton.y > BEACH_LEVEL_TOP)
			{
				requestStackPop();
				requestStackPush(StateID::BeachLevel);
			}

			if (event.mouseButton.x < THUMBNAIL_WIDTH + MOUNTAIN_LEVEL_LEFT 
				&& event.mouseButton.x > MOUNTAIN_LEVEL_LEFT
				&& event.mouseButton.y < THUMBNAIL_HEIGHT + MOUNTAIN_LEVEL_TOP
				&& event.mouseButton.y > MOUNTAIN_LEVEL_TOP)
			{
				requestStackPop();
				requestStackPush(StateID::MountainLevel);
			}

			if (event.mouseButton.x < QUIT_BUTTON_RIGHT 
				&& event.mouseButton.x > QUIT_BUTTON_LEFT
				&& event.mouseButton.y < QUIT_BUTTON_BOTTOM
				&& event.mouseButton.y > QUIT_BUTTON_TOP)
			{
				requestStackPop();
			}
		}
	}

	if (event.type != sf::Event::KeyPressed)
	{
		return true;
	}

	if (event.key.code == sf::Keyboard::Escape)
	{
		requestStackPop();
	}

	return true;
}
