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

#include "Animation2.h"
#include "DataTables.h"
#include "LaneController.h"
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include <map>
#include <queue>
#include <string>

class Tower;
class HealthBar;



const float HORIZONTAL_HOP_LENGTH = 18.f;
const float VERTICAL_HOP_LENGTH = 12.f;


struct compareAttackTimings{
    bool operator()(std::pair<sf::Time, Tower*> rhs, std::pair<sf::Time, Tower*> lhs) {
		return rhs.first > lhs.first;
    }
};

class Enemy: public SceneNode
{
public:
									Enemy(const TextureHolder_t& textures, EnemyData enemyData, std::vector<Direction>& route, LaneController& _controller);
	std::pair<int, int>				getTile() const;
	bool							isAtTile(const int tileX, const int tileY) const;
	bool							isAtTiles(const std::pair<int, int> tile, const std::size_t range) const; 
	double							getProgress() const;
	void							destroy();
	void							damage(double damage);
	void							damage(double damage, Tower* tower);
	void							registerAttack(sf::Time attackTime, Tower* tower);
	void							attachProjectile(Tower* tower);

private:
	void							turn(Direction direction);
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands) override;
	virtual bool					isDestroyed() const override;
	sf::Time						processAilments(sf::Time dt);
	void							processAttacks();

private:
	sf::Sprite						sprite;
	sf::Vector2f					velocity;
	sf::Vector2f					bearing;
	std::map<Direction, Animation2>	animations;
	Direction						direction;
	const sf::Time					movementSpeed;
	sf::Time						timeRemaining;
	std::vector<Direction>&			route;
	std::size_t						routeIndex;
	double							healthPoints;
	double							progress;
	sf::Clock						clock;
	std::priority_queue<std::pair<sf::Time, Tower*>, std::vector<std::pair<sf::Time, Tower*>>, compareAttackTimings> attackTimings;
	const TextureHolder_t&			textures;
	SceneNode*						projectileHolder;
	HealthBar*						healthBar;
	sf::Time						freezeTime;
	sf::Time						deepFreezeTime;
	sf::Time						stunTime;
	sf::Time						poisonTime;
	sf::Time						greatPoisonTime;
	sf::Time						greaterPoisonTime;
	LaneController&					controller;
	Tower*							lastAttacker;
	std::size_t						gold;
	std::size_t						experiencePoints;

};