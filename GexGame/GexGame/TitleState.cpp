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
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "State.h"
#include "TitleState.h"
#include "Utility.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context)
	, text()
	, showText(true)
	, textEffectTime(sf::Time::Zero)
{
	backgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));

	text.setFont(context.fonts->get(FontID::Main));
	text.setString("Press any key to start");

	centerOrigin(text);
	text.setPosition(context.window->getView().getSize() / 2.f);
}



void TitleState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(backgroundSprite);

	if (showText)
	{
		window.draw(text);
	}
}



bool TitleState::update(sf::Time dt)
{
	textEffectTime += dt;

	if (textEffectTime >= sf::seconds(0.5f))
	{
		showText = !showText;
		textEffectTime = sf::Time::Zero;
	}

	return true;
}



bool TitleState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(StateID::Menu);
	}
		requestStackPop();
		requestStackPush(StateID::Menu);

	return true;
}
