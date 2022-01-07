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
#include "StateStack.h"

#include <cassert>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



StateStack::StateStack(State::Context _context)
	: stack()
	, pendingList()
	, context(_context)
	, factories()
{
}



void StateStack::update(sf::Time dt)
{
	for (auto itr{ stack.rbegin() }; itr != stack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
		{
			return;
		}
	}

	applyPendingChanges();
}



void StateStack::draw()
{
	for (auto& s : stack)
	{
		s->draw();
	}
}



void StateStack::handleEvent(const sf::Event& event)
{
	for (auto itr{ stack.rbegin() }; itr != stack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
		{
			break;
			//return;
		}
	}

	
	if (event.type == sf::Event::Closed)
	{
		clearStates();
		context.window->close();
	}

	applyPendingChanges();
}



void StateStack::pushState(StateID stateID)
{
	pendingList.push_back(PendingChange(Action::Push, stateID));
}



void StateStack::popState()
{
	pendingList.push_back(PendingChange(Action::Pop));
}



void StateStack::clearStates()
{
	pendingList.push_back(PendingChange(Action::Clear));
}



bool StateStack::isEmpty() const
{
	return stack.empty();
}



State::Ptr StateStack::createState(StateID stateID)
{
	auto found{ factories.find(stateID) };
	assert(found != factories.end());

	return found->second();
}



void StateStack::applyPendingChanges()
{
	for (PendingChange change : pendingList)
	{
		switch (change.action)
		{
		case Action::Push:
			stack.push_back(createState(change.stateID));
			break;

		case Action::Pop:
			stack.pop_back();
			break;

		case Action::Clear:
			stack.clear();
			break;

		}
	}

	pendingList.clear();
}



StateStack::PendingChange::PendingChange(Action _action, StateID _stateID)
	: action(_action)
	, stateID(_stateID)
{
}