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

#include <list>
#include <map>
#include <memory>
#include <string>

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Vector2.hpp>



class SoundPlayer
{
public:
					SoundPlayer();
					~SoundPlayer() = default;
					SoundPlayer(const SoundPlayer&) = delete;
					SoundPlayer& operator=(const SoundPlayer&) = delete;

	void			play(SoundEffectID effect);
	void			play(SoundEffectID effect, sf::Vector2f position);

	void			removeStoppedSounds();
	void			setListenerPosition(sf::Vector2f position);
	sf::Vector2f	getListenerPosition() const;

private:
	void			loadBuffer(SoundEffectID id, const std::string path);

private:
	std::map<SoundEffectID, std::unique_ptr<sf::SoundBuffer>>	soundBuffers;
	std::list<sf::Sound>										sounds;

};
