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

#include "ResourceIdentifiers.h"

#include <map>
#include <string>

#include <SFML/Audio/Music.hpp>



class MusicPlayer
{
public:
									MusicPlayer();
									~MusicPlayer() = default;
									MusicPlayer(const MusicPlayer&) = delete;
									MusicPlayer& operator=(const MusicPlayer&) = delete;

	void							play(MusicID theme);
	void							stop();
	void							setPaused(bool paused);
	void							setVolume(float volume);
	void							volumeUp();
	void							volumeDown();


private:
	sf::Music						music;
	std::map<MusicID, std::string>	filenames;
	float							volume;
};
