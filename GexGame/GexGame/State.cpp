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
#include "State.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include "StateStack.h"
#include "ResourceIdentifiers.h"



State::Context::Context(
	sf::RenderWindow& window, 
	TextureHolder_t& textures, 
	FontHolder_t& fonts, 
	PlayerControl& player,
	MusicPlayer& music,
	SoundPlayer& sound)
	: window(&window)
	, textures(&textures)
	, fonts(&fonts)
	, player(&player)
	, music(&music)
	, sound(&sound)
{
}



State::State(StateStack& stack, Context context)
	: stack(&stack)
	, context(context)
{
}



State::~State()
{
}



void State::requestStackPush(StateID stateID)
{
	stack->pushState(stateID);
}



void State::requestStackPop()
{
	stack->popState();
}



void State::requestStackClear()
{
	stack->clearStates();
}



State::Context State::getContext() const
{
	return context;
}