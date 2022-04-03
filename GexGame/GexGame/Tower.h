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
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

#include <map>
#include <string>

class Enemy;



class Tower: public SceneNode
{
public:
									Tower(const TextureHolder_t& textures, const FontHolder_t& fonts, TowerType towerType, TowerData towerData, const sf::Vector2i tile);
	bool							isAttackPending() const;
	sf::Vector2i					getTile() const;
	std::size_t						getRange() const;
	void							attack(Enemy* target);
	void							applyDamage(Enemy* target);
	ProjectileType					getProjectileType() const;
	AttackEffect					getAttackEffect() const;
	double							getAttackDamage() const;
	sf::Time						getProjectileSpeed() const;
	void							gainExperience(std::size_t amount);
	bool							isLevelingUp() const;
	bool							canUseExperience() const;
	void							levelUp(TowerType towerType, TowerData towerData);
	TowerType						getType() const;
	void							playLocalSound(CommandQueue& commands, SoundEffectID effect);

private:
	void							turn(Direction direction);
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands) override;
	void							updateSounds(sf::Time dt, CommandQueue& commands);
	void							faceEnemy(Enemy* target);
	void							fireProjectile(Enemy* target);

private:
	sf::Sprite						sprite;
	TowerType						towerType;
	std::map<Direction, Animation2>	animations;
	Direction						direction;
	sf::Time						swingSpeed;
	sf::Time						cooldownDuration;
	sf::Time						cooldownRemaining;
	std::size_t						experiencePoints;
	std::size_t						range;
	sf::Sprite						levelupSprite;
	sf::Vector2i					tile;
	ProjectileType					projectileType;
	double							damage;
	AttackEffect					attackEffect;
	std::size_t						experienceToNextLevel;
	const FontHolder_t&				fonts;
	bool							playAttackSound;

};
