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
#include "PlayerControl.h"
#include <algorithm>
#include "CommandQueue.h"
#include "Command.h"



PlayerControl::PlayerControl()
{
	initializeKeys();
	initializeActions();
}



void PlayerControl::handleEvent(const sf::Event& event, CommandQueue& queue)
{
	if (event.type == sf::Event::KeyPressed)
	{
		auto found{ keyBindings.find(event.key.code) };
		if (found != keyBindings.end() && !isRealTimeAction(found->second))
		{
			queue.push(actionBindings[found->second]);
		}
	}
}



void PlayerControl::handleRealTimeInput(CommandQueue& queue)
{
	std::for_each(keyBindings.begin(), keyBindings.end(),
		[&](auto& p) { 
			auto key{ p.first };
			auto action{ p.second };
			if (sf::Keyboard::isKeyPressed(key) && isRealTimeAction(action))
			{
				queue.push(actionBindings[action]);
			}
		});
	/*
	for (auto& [key, action] : keyBindings)
	{
		if (sf::Keyboard::isKeyPressed(key) && isRealTimeAction(action))
		{
			queue.push(actionBindings[action]);
		}
	}
	*/
}



void PlayerControl::assignKey(Action action, sf::Keyboard::Key key)
{
}



sf::Keyboard::Key PlayerControl::getAssignedKey(Action action) const
{
	return sf::Keyboard::Key();
}



void PlayerControl::setMissionStatus(MissionStatus status)
{
	currentMissionStatus = status;
}



PlayerControl::MissionStatus PlayerControl::getMissionStatus() const
{
	return currentMissionStatus;
}



void PlayerControl::initializeKeys()
{
	keyBindings[sf::Keyboard::Left] = Action::MoveLeft;
	keyBindings[sf::Keyboard::Right] = Action::MoveRight;
	keyBindings[sf::Keyboard::Up] = Action::MoveUp;
	keyBindings[sf::Keyboard::Down] = Action::MoveDown;

	keyBindings[sf::Keyboard::A] = Action::MoveLeft;
	keyBindings[sf::Keyboard::D] = Action::MoveRight;
	keyBindings[sf::Keyboard::W] = Action::MoveUp;
	keyBindings[sf::Keyboard::S] = Action::MoveDown;

	keyBindings[sf::Keyboard::Space] = Action::Fire;
	keyBindings[sf::Keyboard::M] = Action::LaunchMissile;
}



void PlayerControl::initializeActions()
{
	const float speed{ 200.f };

	/*
	actionBindings[Action::MoveLeft].action = derivedAction<Actor>(
		[=](Actor& n, sf::Time dt) { n.walk(-speed, 0.f); });
	actionBindings[Action::MoveRight].action = derivedAction<Actor>(
		[=](Actor& n, sf::Time dt) { n.walk(speed, 0.f); });
	actionBindings[Action::MoveUp].action = derivedAction<Actor>(
		[=](Actor& n, sf::Time dt) { n.walk(0.f , -speed); });
	actionBindings[Action::MoveDown].action = derivedAction<Actor>(
		[=](Actor& n, sf::Time dt) { n.walk(0.f , speed); });


	std::for_each(actionBindings.begin(), actionBindings.end(),
		[](auto& p) { p.second.category = Category::Hero; });
	*/

	/*
	for (auto& [action, cmd] : actionBindings)
	{
		cmd.category = Category::PlayerAircraft;
	}
	*/
}



bool PlayerControl::isRealTimeAction(Action action)
{
	switch (action)
	{
	case Action::MoveDown:
	case Action::MoveUp:
	case Action::MoveLeft:
	case Action::MoveRight:
	case Action::Fire:
		return true;
		break;

	default:
		return false;
		break;

	}
}