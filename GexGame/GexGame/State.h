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

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

#include <memory>



namespace sf {
	class RenderWindow;
	class Time;
	class Event;
}
class StateStack;
class PlayerControl;
class MusicPlayer;
class SoundPlayer;



class State
{
public:
	using Ptr = std::unique_ptr<State>;

	struct Context
	{
		Context(
			sf::RenderWindow& window, 
			TextureHolder_t& textures, 
			FontHolder_t& fonts, 
			PlayerControl& player,
			MusicPlayer& music,
			SoundPlayer& sound);

		sf::RenderWindow*			window;
		TextureHolder_t*			textures;
		FontHolder_t*				fonts;
		PlayerControl*				player;
		MusicPlayer*				music;
		SoundPlayer*				sound;
	};

public:
									State(StateStack& stack, Context context);
	virtual							~State();

	virtual void					draw() = 0;
	virtual bool					update(sf::Time dt) = 0;
	virtual bool					handleEvent(const sf::Event& event) = 0;

protected:
	void							requestStackPush(StateID stateID);
	void							requestStackPop();
	void							requestStackClear();

	Context							getContext() const;

private:
	StateStack*						stack;
	Context							context;

};
