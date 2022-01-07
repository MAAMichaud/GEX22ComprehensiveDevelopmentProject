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
#pragma once
#include "Command.h"

#include <map>

#include <SFML/Window/Event.hpp>



class CommandQueue;



class PlayerControl
{
public:

	enum class Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount,
		Fire,
		LaunchMissile,
	};

	enum class MissionStatus
	{
		MissionRunning,
		MissionSuccess,
		MissionFailure,
	};

public:

									PlayerControl();

	void							handleEvent(const sf::Event& event, CommandQueue& queue);
	void							handleRealTimeInput(CommandQueue& queue);

	void							assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key				getAssignedKey(Action action) const;

	void							setMissionStatus(MissionStatus status);
	MissionStatus					getMissionStatus() const;

private:
	void							initializeKeys();
	void							initializeActions();
	static bool						isRealTimeAction(Action action);

private:
	std::map<sf::Keyboard::Key, Action>			keyBindings;
	std::map<Action, Command>					actionBindings;
	MissionStatus								currentMissionStatus;

};
