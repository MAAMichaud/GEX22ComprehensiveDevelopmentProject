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
#include "Command.h"
#include "CommandQueue.h"
#include "SceneNode.h"
#include "utility.h"

#include <algorithm>
#include <cassert>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>



SceneNode::SceneNode(unsigned int _category) 
	: children()
	, parent(nullptr)
	, category(_category)
{
}



void SceneNode::attachChild(Ptr child)
{
	child->parent = this;
	children.push_back(std::move(child));
}



SceneNode::Ptr SceneNode::detatchChild(const SceneNode& node)
{
	auto found{ std::find_if(
		children.begin(),
		children.end(),
		[&](Ptr& p) {
			return p.get() == &node;
		}
	)};

	assert(found != children.cend());

	auto result{ std::move(*found) };
	result->parent = nullptr;
	children.erase(found);

	return result;
}



void SceneNode::update(sf::Time dt, CommandQueue& commands)
{
	updateCurrent(dt, commands);
	updateChildren(dt, commands);
}



sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}



sf::Transform SceneNode::getWorldTransform() const
{
	auto transform{ sf::Transform::Identity };

	for (const SceneNode* node{ this }; node != nullptr; node = node->parent)
	{
		transform = node->getTransform() * transform;
	}

	return transform;
}



unsigned int SceneNode::getCategory() const
{
	return category;
}



void SceneNode::onCommand(const Command& command, sf::Time dt)
{
	if (command.category & getCategory())
	{
		command.action(*this, dt);
	}

	std::for_each(children.begin(), children.end(),
		[&](auto& child) { child->onCommand(command, dt); } );
}



sf::FloatRect SceneNode::getBoundingRect() const
{
	return sf::FloatRect();
}



void SceneNode::drawBoundingBox(sf::RenderTarget& target, sf::RenderStates states) const
{
	auto rect{ getBoundingRect() };

	sf::RectangleShape box;

	box.setPosition(sf::Vector2f(rect.left, rect.top));
	box.setSize(sf::Vector2f(rect.width, rect.height));
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Magenta);
	box.setOutlineThickness(1.5f);

	target.draw(box);
}



void SceneNode::checkSceneCollision(SceneNode& rootNode, std::set<Pair>& collisionPairs)
{
	checkNodeCollision(rootNode, collisionPairs);

	for (Ptr& child : rootNode.children)
	{
		checkSceneCollision(*child, collisionPairs);
	}
}



void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
	if (this != &node && !isDestroyed() && !node.isDestroyed()
		&& collision(*this, node))
	{
		collisionPairs.insert(std::minmax(this, &node));
	}

	for (Ptr& child : this->children)
	{
		child->checkNodeCollision(node, collisionPairs);
	}
}



void SceneNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	// virtual
}



void SceneNode::updateChildren(sf::Time dt, CommandQueue& commands)
{
	std::for_each(children.begin(), children.end(),
		[&](auto& child) { child->update(dt, commands); } );
}



void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// get current transform
	const auto& transform{ getTransform() };
	
	// apply transform to states
	states.transform *= transform;

	// draw
	drawCurrent(target, states);
	drawChildren(target, states);

	drawBoundingBox(target, states);
}



void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	// virtual
}



void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::for_each(children.cbegin(), children.cend(),
		[&](auto& child) { child->draw(target, states); } );
}



bool SceneNode::isDestroyed() const
{
	return false;
}



bool SceneNode::isMarkedForRemoval() const
{
	return isDestroyed();
}



void SceneNode::removeWrecks()
{
	auto wreckFieldBegin{ std::remove_if(children.begin(), children.end(), std::mem_fn(&SceneNode::isMarkedForRemoval)) };
	children.erase(wreckFieldBegin, children.end());

	std::for_each(children.begin(), children.end(),
		std::mem_fn(&SceneNode::removeWrecks));
}



bool collision(const SceneNode& lhs, const SceneNode& rhs)
{
	return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}



float distance(const SceneNode& lhs, const SceneNode& rhs)
{
	return length(lhs.getWorldPosition() - rhs.getWorldPosition());
}