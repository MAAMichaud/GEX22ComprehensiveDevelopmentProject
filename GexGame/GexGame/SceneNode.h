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

#include "Category.h"

#include <memory>
#include <set>
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>



struct Command;
class CommandQueue;



class SceneNode : public sf::Transformable, public sf::Drawable
{
public:
	using Ptr = std::unique_ptr<SceneNode>;
	using Pair = std::pair<SceneNode*, SceneNode*>;

public:
									SceneNode(const SceneNode&) = delete; // non-copyable
									SceneNode(unsigned int _category = Category::None);

	void							attachChild(Ptr child);
	Ptr								detatchChild(const SceneNode& node);

	void							update(sf::Time dt, CommandQueue& commands);

	sf::Vector2f					getWorldPosition() const;
	sf::Transform					getWorldTransform() const;

	virtual unsigned int			getCategory() const;
	void							onCommand(const Command& command, sf::Time dt);

	virtual sf::FloatRect			getBoundingRect() const;
	void							drawBoundingBox(sf::RenderTarget& target, sf::RenderStates states) const;

	void							checkSceneCollision(SceneNode& rootNode, std::set<Pair>& collisionPair);
	void							checkNodeCollision(SceneNode& root, std::set<Pair>& collisionPair);

	virtual bool					isDestroyed() const;
	virtual bool					isMarkedForRemoval() const;
	void							removeWrecks();

private:

	virtual void					updateCurrent(sf::Time dt, CommandQueue& commands);
	void							updateChildren(sf::Time dt, CommandQueue& commands);

	virtual void					draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void					drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void							drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	std::vector<Ptr>				children;

private:
	SceneNode*						parent;
	unsigned int					category;

};



bool								collision(const SceneNode& lhs, const SceneNode& rhs);
float								distance(const SceneNode& lhs, const SceneNode& rhs);
