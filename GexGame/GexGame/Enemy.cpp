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
#include "Projectile.h"
#include "Tower.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>


Enemy::Enemy(const TextureHolder_t& _textures, EnemyData enemyData, std::vector<Direction>& _route)
	: sprite(_textures.get(enemyData.texture))
	, velocity(HORIZONTAL_HOP_LENGTH / enemyData.speed.asSeconds(), VERTICAL_HOP_LENGTH / enemyData.speed.asSeconds())
	, bearing(-1, 1)
	, animations()
	, direction(Direction::DownLeft)
	, movementSpeed(enemyData.speed)
	, timeRemaining(enemyData.speed)
	, route(_route)
	, routeIndex(0)
	, healthPoints(1)
	, progress(0.0)
	, clock()
	, attackTimings()
	, textures(_textures)
	, projectileHolder(nullptr)
{
	for (auto a : enemyData.animations)
	{
		animations[a.first] = a.second;
	}

	auto holderNode{ std::make_unique<SceneNode>() };
	holderNode->setPosition(18.f, 34.f);
	projectileHolder = holderNode.get();
	this->attachChild(std::move(holderNode));
}



std::pair<int, int> Enemy::getTile() const
{
	if (isDestroyed())
	{
		return std::pair<int, int>{ -100, -100 };
	}

	const auto [pixelX,  pixelY] { getWorldPosition() };

	const auto [thisTileX, thisTileY] { pixelXYToTileXY(pixelX + 36, pixelY + 72) };

	return std::pair<int, int>(thisTileX, thisTileY);
}



bool Enemy::isAtTile(const int tileX, const int tileY) const
{
	if (isDestroyed())
	{
		return false;
	}

	const auto [thisTileX, thisTileY] { getTile() };

	return thisTileX == tileX && thisTileY == tileY;
}



bool Enemy::isAtTiles(const std::pair<int, int> tile, const std::size_t range) const
{
	if (isDestroyed())
	{
		return false;
	}

	const auto [thisTileX, thisTileY] { getTile() };

	return thisTileX <= tile.first + range
		&& thisTileX >= tile.first - (int) range
		&& thisTileY <= tile.second + range
		&& thisTileY >= tile.second - (int) range;
}



double Enemy::getProgress() const
{
	return progress;
}



void Enemy::destroy()
{
	healthPoints = 0;
}



void Enemy::damage(int damage)
{
	healthPoints -= damage;
}



void Enemy::registerAttack(sf::Time attackTime, Tower* tower)
{
	attackTimings.push({ attackTime + clock.getElapsedTime() , tower });
	std::cout << attackTimings.top().first.asSeconds() << std::endl;
}



void Enemy::attachProjectile(Tower* tower)
{
	auto projectileNode{ std::make_unique<Projectile>(textures, tower->getProjectileType()) };
	const auto [tX,  tY] { tower->getWorldPosition() };
	const auto [eX,  eY] { this->getWorldPosition() };
	projectileNode->setPosition(tX + 18.f - eX, tY + 24.f - eY);
	projectileHolder->attachChild(std::move(projectileNode));
}



void Enemy::turn(Direction _direction)
{
	direction = _direction;

	switch (direction)
	{
	case Direction::UpRight:
		bearing.x = 1;
		bearing.y = -1;
		break;

	case Direction::DownRight:
		bearing.x = 1;
		bearing.y = 1;
		break;

	case Direction::DownLeft:
		bearing.x = -1;
		bearing.y = 1;
		break;

	case Direction::UpLeft:
		bearing.x = -1;
		bearing.y = -1;
		break;

	}
}



void Enemy::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}



void Enemy::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	auto frame{ animations.at(direction).update(dt) };

	sprite.setTextureRect(frame.getRect());
	//sprite.setColor(frame.isRotated ? sf::Color(0, 255, 255, 255) : sf::Color(255, 0, 255, 255));
	if (direction == Direction::UpRight || direction == Direction::DownRight)
	{
		sprite.setRotation(frame.isRotated ? -90.f : 0.f);
	}
	else
	{
		sprite.setRotation(frame.isRotated ? 90.f : 0.f);
	}
	sprite.setPosition(frame.offset.first, frame.offset.second);


	while (dt > timeRemaining)
	{
		dt -= timeRemaining;
		move(velocity * timeRemaining.asSeconds());
		timeRemaining = movementSpeed;

		turn(route.at(routeIndex % route.size()));
		routeIndex += 1;

	}

	timeRemaining -= dt;
	progress += abs(velocity.x * bearing.x * dt.asSeconds());
	move(velocity.x * bearing.x * dt.asSeconds(), velocity.y * bearing.y * dt.asSeconds());

	for (auto& projectile : projectileHolder->children)
	{
		projectile->move(-velocity.x * bearing.x * dt.asSeconds(), -velocity.y * bearing.y * dt.asSeconds());
	}

	while (!attackTimings.empty() && attackTimings.top().first <= clock.getElapsedTime())
	{
		attackTimings.top().second->applyDamage(this);
		attackTimings.pop();
	}
}



bool Enemy::isDestroyed() const
{
	if (healthPoints <= 0)
	{
		return true;
	}

	return routeIndex >= route.size();
}

/*
bool Enemy::compareAttackTimings(std::pair<const sf::Time, const Tower*> rhs, std::pair<const sf::Time, const Tower*> lhs) const
{
	return rhs.first > lhs.first;
}
*/
