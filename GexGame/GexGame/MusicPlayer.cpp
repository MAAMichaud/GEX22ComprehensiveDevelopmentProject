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

#include <cmath>
#include <stdexcept>



namespace
{
	static const float MAX_VOLUME{ 25.f };
}



MusicPlayer::MusicPlayer()
	: music()
	, filenames()
	, volume(MAX_VOLUME)
{
	filenames[MusicID::ForestMusic] = "../Media/Music/Forest.ogg";
	filenames[MusicID::CemeteryMusic] = "../Media/Music/Cemetery.ogg";
	filenames[MusicID::BeachMusic] = "../Media/Music/Beach.ogg";
	filenames[MusicID::MountainMusic] = "../Media/Music/Mountain.ogg";
	filenames[MusicID::MenuMusic] = "../Media/Music/MainMenu.ogg";
}



void MusicPlayer::play(MusicID theme)
{
	if (!music.openFromFile(filenames[theme]))
	{
		throw std::runtime_error("Music could not open file");
	}

	music.setVolume(volume);
	music.setLoop(true);
	music.play();
}



void MusicPlayer::stop()
{
	music.stop();
}



void MusicPlayer::setPaused(bool paused)
{
	if (paused)
	{
		music.pause();
	}
	else
	{
		music.play();
	}
}



void MusicPlayer::setVolume(float volume)
{
	volume = volume;
	music.setVolume(volume);
}



void MusicPlayer::volumeUp()
{
	const auto newVolume{ volume + MAX_VOLUME / 10.f };
	volume = std::min(MAX_VOLUME, newVolume);
	music.setVolume(volume);
}



void MusicPlayer::volumeDown()
{
	const auto newVolume{ volume - MAX_VOLUME / 10.f };
	volume = std::max(0.f, newVolume);
	music.setVolume(volume);
}