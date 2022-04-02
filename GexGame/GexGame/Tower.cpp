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
#include "FloatingTextNode.h"
#include "Tower.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>



Tower::Tower(const TextureHolder_t& textures, const FontHolder_t& _fonts, TowerType _towerType, TowerData towerData, const sf::Vector2i _tile)
	: sprite(textures.get(TextureID::Towers))
	, towerType(_towerType)
	, animations()
	, direction(Direction::Down)
	, swingSpeed(sf::seconds(towerData.swingSpeed))
	, cooldownDuration(sf::seconds(towerData.swingSpeed + towerData.cooldown))
	, cooldownRemaining(sf::Time::Zero)
	, experiencePoints(0)
	, range(towerData.range)
	, levelupSprite(textures.get(TextureID::OnebyOne))
	, tile(_tile)
	, projectileType(towerData.projectileType)
	, damage(towerData.damage)
	, attackEffect(towerData.attackEffect)
	, experienceToNextLevel(towerData.experienceToNextLevel)
	, fonts(_fonts)
{
	for (auto a : towerData.animations)
	{
		animations[a.first] = a.second;
	}

	levelupSprite.setColor(sf::Color(255, 255, 155, 155));
	levelupSprite.move(0.f, 48.f);

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



sf::Vector2i Tower::getTile() const
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

		target->registerAttack(getProjectileSpeed(), this);

		fireProjectile(target);
	}
}



void Tower::applyDamage(Enemy* target)
{
	if (target)
	{
		faceEnemy(target);

		target->damage(damage, this);
	}
}



ProjectileType Tower::getProjectileType() const
{
	return projectileType;
}



AttackEffect Tower::getAttackEffect() const
{
	return attackEffect;
}



double Tower::getAttackDamage() const
{
	return damage;
}



sf::Time Tower::getProjectileSpeed() const
{
	return sf::seconds(swingSpeed.asSeconds() * 0.8f);
}



void Tower::gainExperience(std::size_t amount)
{
	experiencePoints += amount;
	std::cout << "Experience points " << experiencePoints << std::endl;

	auto floatNode{ std::make_unique<FloatingTextNode>(fonts, std::to_string(amount) + "Exp", sf::Color(100, 255, 100, 255))};
	attachChild(std::move(floatNode));
}



bool Tower::isLevelingUp() const
{
	return experienceToNextLevel && experiencePoints >= experienceToNextLevel;
}



bool Tower::canUseExperience() const
{
	return experienceToNextLevel;
}



void Tower::levelUp(TowerType _towerType, TowerData towerData)
{
	std::cout << "level up!!" << std::endl;

	towerType = _towerType;
	experiencePoints -= experienceToNextLevel;
	experienceToNextLevel = towerData.experienceToNextLevel;
	projectileType = towerData.projectileType;
	attackEffect = towerData.attackEffect;
	swingSpeed = sf::seconds(towerData.swingSpeed);
	cooldownDuration = sf::seconds(towerData.swingSpeed + towerData.cooldown);
	damage = towerData.damage;
	range = towerData.range;

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



TowerType Tower::getType() const
{
	return towerType;
}



void Tower::turn(Direction _direction)
{
	direction = _direction;
}



void Tower::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (isLevelingUp())
	{
		target.draw(levelupSprite, states);
	}
	target.draw(sprite, states);
}



void Tower::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (cooldownRemaining > cooldownDuration - swingSpeed)
	{
		auto frame{ animations.at(direction).update(dt) };

		if (cooldownRemaining - dt <= cooldownDuration - swingSpeed)
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