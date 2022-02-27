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
#include "HealthBar.h"
#include "Projectile.h"
#include "Tower.h"
#include "utility.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

#include <iostream>


Enemy::Enemy(const TextureHolder_t& _textures, EnemyData enemyData, std::vector<Direction>& _route, LaneController& _controller)
	: sprite(_textures.get(enemyData.texture))
	, velocity(HORIZONTAL_HOP_LENGTH / enemyData.speed, VERTICAL_HOP_LENGTH / enemyData.speed)
	, bearing(-1, 1)
	, animations()
	, direction(Direction::DownLeft)
	, movementSpeed(sf::seconds(enemyData.speed))
	, timeRemaining(sf::seconds(enemyData.speed))
	, route(_route)
	, routeIndex(0)
	, healthPoints(enemyData.healthPoints)
	, progress(0.0)
	, clock()
	, attackTimings()
	, textures(_textures)
	, projectileHolder(nullptr)
	, freezeTime(sf::Time::Zero)
	, deepFreezeTime(sf::Time::Zero)
	, stunTime(sf::Time::Zero)
	, poisonTime(sf::Time::Zero)
	, greatPoisonTime(sf::Time::Zero)
	, greaterPoisonTime(sf::Time::Zero)
	, controller(_controller)
	, lastAttacker(nullptr)
	, gold(enemyData.gold)
	, experiencePoints(enemyData.experiencePoints)
	, reachedEnd(false)
{
	for (auto a : enemyData.animations)
	{
		animations[a.first] = a.second;
	}

	auto holderNode{ std::make_unique<SceneNode>() };
	holderNode->setPosition(28.f, 34.f);
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



void Enemy::damage(double damage)
{
	if (!healthBar)
	{
		auto healthNode{ std::make_unique<HealthBar>(healthPoints) };
		healthBar = healthNode.get();
		this->attachChild(std::move(healthNode));
	}

	if (!isDestroyed())
	{
		healthPoints -= damage;
		healthBar->setHealth(healthPoints);
		if (isDestroyed())
		{
			if (lastAttacker)
			{
				lastAttacker->gainExperience(experiencePoints);
			}
			controller.addGold(gold);
		}
	}
}



void Enemy::damage(double damage, Tower* tower)
{
	lastAttacker = tower->canUseExperience() ? tower : lastAttacker;
	this->damage(damage);
}



void Enemy::registerAttack(sf::Time attackTime, Tower* tower)
{
	if (!healthBar)
	{
		auto healthNode{ std::make_unique<HealthBar>(healthPoints) };
		healthBar = healthNode.get();
		this->attachChild(std::move(healthNode));
	}

	attackTimings.push({ attackTime + clock.getElapsedTime() , tower });
}



void Enemy::attachProjectile(Tower* tower)
{
	auto projectileNode{ std::make_unique<Projectile>(textures, tower->getProjectileType(), tower->getProjectileSpeed()) };
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
	dt = processAilments(dt);

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

		if (!reachedEnd && routeIndex >= route.size())
		{
			reachedEnd = true;
			controller.loseLife();
		}
	}

	timeRemaining -= dt;
	progress += abs(velocity.x * bearing.x * dt.asSeconds());
	move(velocity.x * bearing.x * dt.asSeconds(), velocity.y * bearing.y * dt.asSeconds());

	for (auto& projectile : projectileHolder->children)
	{
		projectile->move(-velocity.x * bearing.x * dt.asSeconds(), -velocity.y * bearing.y * dt.asSeconds());
	}

	processAttacks();
}



bool Enemy::isDestroyed() const
{
	if (healthPoints <= 0)
	{
		return true;
	}

	return routeIndex >= route.size();
}



sf::Time Enemy::processAilments(sf::Time dt)
{
	freezeTime -= dt;
	deepFreezeTime -= dt;
	stunTime -= dt;
	poisonTime -= dt;
	greatPoisonTime -= dt;
	greaterPoisonTime -= dt;

	sprite.setColor(sf::Color(255, 255, 255, 255));
	if (greaterPoisonTime > sf::Time::Zero)
	{
		auto color = sprite.getColor();
		color.r -= 100;
		color.b -= 100;
		sprite.setColor(color);
		damage(4.f * dt.asSeconds());
	}
	else if (greatPoisonTime > sf::Time::Zero)
	{
		auto color = sprite.getColor();
		color.r -= 75;
		color.b -= 75;
		sprite.setColor(color);
		damage(2.f * dt.asSeconds());
	}
	else if (poisonTime > sf::Time::Zero)
	{
		auto color = sprite.getColor();
		color.r -= 50;
		color.b -= 50;
		sprite.setColor(color);
		damage(dt.asSeconds());
	}

	if (stunTime > sf::Time::Zero)
	{
		dt = sf::seconds(dt.asSeconds() / 40);
	}

	if (deepFreezeTime > sf::Time::Zero)
	{
		dt = sf::seconds(dt.asSeconds() / 3);
		auto color = sprite.getColor();
		color.r -= 100;
		color.g -= 100;
		sprite.setColor(color);
	}
	else if (freezeTime > sf::Time::Zero)
	{
		dt = sf::seconds(dt.asSeconds() / 2);
		auto color = sprite.getColor();
		color.r -= 100;
		color.g -= 50;
		sprite.setColor(color);
	}

	return dt;
}



void Enemy::processAttacks()
{
	while (!attackTimings.empty() && attackTimings.top().first <= clock.getElapsedTime())
	{
		switch (attackTimings.top().second->getAttackEffect())
		{
		case AttackEffect::Area:
			controller.areaAttack(this, attackTimings.top().second, 30.f);
			break;

		case AttackEffect::BigArea:
			controller.areaAttack(this, attackTimings.top().second, 50.f);
			break;

		default:
			attackTimings.top().second->applyDamage(this);
			break;

		}


		switch (attackTimings.top().second->getAttackEffect())
		{
		case AttackEffect::Freeze:
			freezeTime = sf::seconds(5.f);
			break;

		case AttackEffect::DeepFreeze:
			deepFreezeTime = sf::seconds(5.f);
			break;

		case AttackEffect::Stun:
			stunTime = sf::seconds(0.5f);
			break;

		case AttackEffect::Poison:
			poisonTime = sf::seconds(8.f);
			break;

		case AttackEffect::GreatPoison:
			greatPoisonTime = sf::seconds(8.f);
			break;

		case AttackEffect::GreaterPoison:
			greaterPoisonTime = sf::seconds(8.f);
			break;

		default:
			break;

		}

		attackTimings.pop();
	}
}