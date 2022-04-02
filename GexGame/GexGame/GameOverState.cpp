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
#include "GameOverState.h"
#include "GameState.h"
#include "PlayerControl.h"
#include "ResourceHolder.h"
#include "Utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>



GameOverState::GameOverState(StateStack& stack, Context context)
	: State(stack, context)
	, gameOverText()
	, elapsedTime(sf::Time::Zero)
{
	sf::Font& font = context.fonts->get(FontID::Main);
	sf::Vector2f windowSize(context.window->getSize());

	gameOverText.setFont(font);

	if (context.player->getMissionStatus() == PlayerControl::MissionStatus::MissionFailure)
	{
		gameOverText.setString("Game Over");
		gameOverText.setFillColor(sf::Color(150, 0, 0, 255));
	}
	else
	{
		gameOverText.setString("Level Complete");
		gameOverText.setFillColor(sf::Color(100, 255, 100, 255));
	}

	gameOverText.setCharacterSize(80);
	centerOrigin(gameOverText);
	gameOverText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

}



void GameOverState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(50, 50, 50, 105));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(gameOverText);
}



bool GameOverState::update(sf::Time dt)
{
	elapsedTime += dt;
	if (elapsedTime > sf::seconds(5))
	{
		requestStackClear();
		requestStackPush(StateID::Menu);
	}
	return false;
}



bool GameOverState::handleEvent(const sf::Event& event)
{
	return false;
}