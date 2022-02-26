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
#include "DataTables.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"



#include <SFML/Graphics/Sprite.hpp>

class Tower;
class Bank;



class NextWaveIcon : public SceneNode
{
public:
										NextWaveIcon(const TextureHolder_t& textures);

	bool								isHidden() const;
	void								show(EnemyData nextEnemy);
	void								hide();

private:
	virtual void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite							sprite;
	const TextureHolder_t&				textures;

};
