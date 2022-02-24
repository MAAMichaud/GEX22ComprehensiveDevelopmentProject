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
#include "Animation2.h"
#include "Enemy.h"
#include "Tower.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>



Tower::Tower(const TextureHolder_t& textures, TowerData towerData, std::pair<int, int> _tile)
	: sprite(textures.get(TextureID::Towers))
	, animations()
	, direction(Direction::Down)
	, timeRemaining(sf::seconds(1.0f))
	, cooldownDuration(sf::seconds(2.5f))
	, cooldownRemaining(sf::Time::Zero)
	, experiencePoints(0)
	, range(towerData.range)
	, rangeSprite()
	, tile(_tile)
	, projectileType(towerData.projectileType)
	, damage(4)
{
	for (auto a : towerData.animations)
	{
		animations[a.first] = a.second;
	}

	auto frame{ animations.at(direction).getCurrentFrame() };

	sprite.setTextureRect(frame.getRect());
	if (direction == Direction::UpLeft || direction == Direction::Left || direction == Direction::DownLeft)
	{
		sprite.setRotation(frame.isRotated ? 90.f : 0.f);
	}
	else
	{
		sprite.setRotation(frame.isRotated ? -90.f : 0.f);
	}
	sprite.setPosition(frame.offset.first, frame.offset.second);
}



bool Tower::isAttackPending() const
{
	return cooldownRemaining <= sf::Time::Zero;
}



std::pair<int, int> Tower::getTile() const
{
	return tile;
}



std::size_t Tower::getRange() const
{
	return range;
}



void Tower::attack(Enemy* target)
{
	if (target)
	{
		cooldownRemaining = cooldownDuration;

		faceEnemy(target);

		target->registerAttack(sf::seconds(0.8f), this);

		fireProjectile(target);
	}
}



void Tower::applyDamage(Enemy* target)
{
	if (target)
	{
		faceEnemy(target);

		target->damage(damage);
	}
}

ProjectileType Tower::getProjectileType() const
{
	return projectileType;
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
	if (cooldownRemaining > cooldownDuration - sf::seconds(1.0f))
	{
		auto frame{ animations.at(direction).update(dt) };

		if (cooldownRemaining - dt <= cooldownDuration - sf::seconds(1.0f))
		{
			for (auto& animation : animations)
			{
				animation.second.restart();
			}

			frame = animations.at(direction).getCurrentFrame();
		}

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
	}


	cooldownRemaining -= dt;
}



void Tower::faceEnemy(Enemy* target)
{
	if (target)
	{
		auto [eX, eY] { target->getTile() };
		auto [tX, tY] { this->getTile() };

		if (tX > eX && tY > eY)
		{
			direction = Direction::Up;
		}
		else if (tX == eX && tY > eY)
		{
			direction = Direction::UpRight;
		}
		else if (tX > eX && tY == eY)
		{
			direction = Direction::UpLeft;
		}
		else if (tX < eX && tY > eY)
		{
			direction = Direction::Right;
		}
		else if (tX > eX && tY < eY)
		{
			direction = Direction::Left;
		}
		else if (tX < eX && tY == eY)
		{
			direction = Direction::DownRight;
		}
		else if (tX == eX && tY < eY)
		{
			direction = Direction::DownLeft;
		}
		else if (tX < eX && tY < eY)
		{
			direction = Direction::Down;
		}
	}
}



void Tower::fireProjectile(Enemy* target)
{
	if (target)
	{
		target->attachProjectile(this);
	}
}
