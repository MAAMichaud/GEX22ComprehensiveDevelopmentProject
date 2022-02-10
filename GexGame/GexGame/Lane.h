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

#include "AnimatedNode.h"
#include "DataTables.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"



class Lane: public SceneNode
{
public:
	explicit			Lane(const TextureHolder_t& textures, LaneData data);

private:
	void				loadEnemy(AnimatedNode::Type enemyType);
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

private:
	const TextureHolder_t&						textures;
	AnimatedNode::Type							enemyType;
	float										spawnRate;
	sf::Time									timeRemaining;
	std::vector<AnimatedNode::Direction>		route;

};

