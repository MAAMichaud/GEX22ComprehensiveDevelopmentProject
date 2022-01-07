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

#include "Particle.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"

#include <deque>	

#include <SFML/Graphics/VertexArray.hpp>



class ParticleNode : public SceneNode
{
public:
								ParticleNode(Particle::Type type, const TextureHolder_t& textures);

	void						addParticle(sf::Vector2f position);
	Particle::Type				getParticleType() const;
	virtual unsigned int		getCategory() const;


private:
	virtual void				updateCurrent(sf::Time dt, CommandQueue& commands);
	virtual void				drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	void						addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
	void						computeVertices() const;


private:
	std::deque<Particle>		particles;
	const sf::Texture&			texture;
	Particle::Type				type;

	mutable sf::VertexArray		vertexArray;
	mutable bool				needsVertexUpdate;
};
