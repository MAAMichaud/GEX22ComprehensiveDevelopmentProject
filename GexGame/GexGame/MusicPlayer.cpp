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
#include "MusicPlayer.h"
#include <stdexcept>

MusicPlayer::MusicPlayer()
	: music()
	, filenames()
	, volume(1)
{
}

void MusicPlayer::play(MusicID theme)
{
	if (!music.openFromFile(filenames[theme]))
		throw std::runtime_error("Music could not open file");

	music.setVolume(volume);
	music.setLoop(true);
	//music.play();
}

void MusicPlayer::stop()
{
	music.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		music.pause();
	else
		music.play();
}

void MusicPlayer::setVolume(float volume)
{
	volume = volume;
	music.setVolume(volume);
}
