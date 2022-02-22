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
#include "Tower.h"
#include "Animation2.h"
#include "JsonFrameParser.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>



Tower::Tower(const TextureHolder_t& textures, TowerData towerData)
	: sprite(textures.get(TextureID::Towers))
	, animations()
	, direction(Direction::Up)
	, timeRemaining(sf::seconds(1.0f))
{
	for (auto a : towerData.animations)
	{
		animations[a.first] = a.second;
	}
}



void Tower::turn(Direction _direction)
{
	direction = _direction;
}



void Tower::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



void Tower::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	auto frame = animations.at(direction).update(dt);

	sprite.setTextureRect(frame.getRect());
	//sprite.setColor(frame.isRotated ? sf::Color(0, 255, 255, 255) : sf::Color(255, 0, 255, 255));
	if (direction == Direction::UpLeft || direction == Direction::Left || direction == Direction::DownLeft)
	{
		sprite.setRotation(frame.isRotated ? 90.f : 0.f);
	}
	else
	{
		sprite.setRotation(frame.isRotated ? -90.f : 0.f);
	}
	sprite.setPosition(frame.offset.first, frame.offset.second);

	while (dt > timeRemaining)
	{
		dt -= timeRemaining;

		switch (direction)
		{
		case Direction::Up:
			direction = Direction::UpRight;
			break;

		case Direction::Down:
			direction = Direction::DownLeft;
			break;

		case Direction::Left:
			direction = Direction::UpLeft;
			break;

		case Direction::Right:
			direction = Direction::DownRight;
			break;

		case Direction::UpRight:
			direction = Direction::Right;
			break;

		case Direction::DownRight:
			direction = Direction::Down;
			break;

		case Direction::DownLeft:
			direction = Direction::Left;
			break;

		case Direction::UpLeft:
			direction = Direction::Up;
			break;

		}

		timeRemaining = sf::seconds(1.0f);
	}

	timeRemaining -= dt;
}
