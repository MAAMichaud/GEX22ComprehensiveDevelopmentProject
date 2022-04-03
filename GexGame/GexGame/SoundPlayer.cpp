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
#include "SoundPlayer.h"

#include <cassert>
#include <cmath>
#include <stdexcept>

#include <SFML/Audio/Listener.hpp>
#include <SFML/System/Vector2.hpp>



namespace
{
	// Sound coordinate system, point of view of a player in front of the screen:
	// X = left; Y = up; Z = back (out of the screen)
	const float ListenerZ = 3300.f;
	const float Attenuation = 0.f;
	const float MinDistance2D = 200.f;
	const float MinDistance3D = std::sqrt(MinDistance2D * MinDistance2D + ListenerZ * ListenerZ);
	const float MAX_VOLUME{ 25.f };
}



SoundPlayer::SoundPlayer()
	: soundBuffers()
	, sounds()
	, volume(MAX_VOLUME)
{
	loadBuffer(SoundEffectID::SpellSound, "../Media/Sound/LaunchMissile.wav");
	loadBuffer(SoundEffectID::SwingSound, "../Media/Sound/EnemyGunfire.wav");

	// Listener points towards the screen (default in SFML)
	sf::Listener::setDirection(0.f, 0.f, -1.f);
}



void SoundPlayer::play(SoundEffectID effect)
{
	play(effect, getListenerPosition());
}



void SoundPlayer::play(SoundEffectID effect, sf::Vector2f position)
{
	sounds.push_back(sf::Sound());
	sf::Sound& sound = sounds.back();

	sound.setBuffer(*soundBuffers[effect]);
	sound.setPosition(position.x, -position.y, 0.f);
	sound.setAttenuation(Attenuation);
	sound.setMinDistance(MinDistance3D);
	sound.setVolume(volume);

	sound.play();
}



void SoundPlayer::removeStoppedSounds()
{
	sounds.remove_if([](const sf::Sound& s)
	{
		return s.getStatus() == sf::Sound::Stopped;
	});
}



void SoundPlayer::setListenerPosition(const sf::Vector2f position)
{
	sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}



sf::Vector2f SoundPlayer::getListenerPosition() const
{
	sf::Vector3f pos = sf::Listener::getPosition();
	return sf::Vector2f(pos.x, -pos.y);
}



void SoundPlayer::volumeUp()
{
	const auto newVolume{ volume + MAX_VOLUME / 10.f };
	volume = std::min(MAX_VOLUME, newVolume);
}



void SoundPlayer::volumeDown()
{
	const auto newVolume{ volume - MAX_VOLUME / 10.f };
	volume = std::max(0.f, newVolume);
}



void SoundPlayer::loadBuffer(SoundEffectID id, const std::string path)
{
	std::unique_ptr<sf::SoundBuffer> buffer(new sf::SoundBuffer);
	if (!buffer->loadFromFile(path))
	{
		throw std::runtime_error("Sound Effect Load Failed");
	}

	auto inserted = soundBuffers.insert(std::make_pair(id, std::move(buffer)));
	assert(inserted.second);
}