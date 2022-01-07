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
#include "State.h"
#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

#include <functional>
#include <map>
#include <utility>
#include <vector>

#include <SFML/System/Time.hpp>



namespace sf
{
	class Event;
}



class StateStack
{
public:
	enum class Action
	{
		Push,
		Pop,
		Clear,
	};

public:
	explicit					StateStack(State::Context context);
								StateStack(const StateStack&) = delete;

	template <typename T>
	void						registerState(StateID stateID);
	void						update(sf::Time dt);
	void						draw();
	void						handleEvent(const sf::Event& event);
	void						pushState(StateID stateID);
	void						popState();
	void						clearStates();
	bool						isEmpty() const;

private:
	State::Ptr					createState(StateID stateID);
	void						applyPendingChanges();

private:
	struct PendingChange
	{
	public:
		explicit		PendingChange(Action action, StateID stateID = StateID::None);

	public:
		Action			action;
		StateID			stateID;
	};
	
private:
	std::vector<State::Ptr>							stack;
	std::vector<PendingChange>						pendingList;
	State::Context									context;
	std::map<StateID, std::function<State::Ptr()>>	factories;

};



template<typename T>
inline void StateStack::registerState(StateID stateID)
{
	factories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, context));
	};
}
