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
#include "MusicPlayer.h"
#include "PlayerControl.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SoundPlayer.h"
#include "StateStack.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>



class Application
{
public:
								Application();
								Application(const Application&) = delete;

	void						run();

private:
	void						registerStates();
	void						processInput();
	void						update(sf::Time dt);
	void						updateStatistics(sf::Time dt);
	void						draw();

private:
	sf::RenderWindow			window;
	TextureHolder_t				textures;
	FontHolder_t				fonts;
	PlayerControl				player;
	MusicPlayer					music;
	SoundPlayer					sound;
	StateStack					stateStack;
	static const sf::Time		TIME_PER_FRAME;


	sf::Text					statisticsText;
	sf::Time					statisticsUpdateTime;
	unsigned int				statisticsNumFrames;

};
