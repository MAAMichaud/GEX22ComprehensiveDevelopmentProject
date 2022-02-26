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
#include "NextWaveIcon.h"
#include "utility.h"

#include <SFML/Graphics/RenderTarget.hpp>



NextWaveIcon::NextWaveIcon(const TextureHolder_t& _textures)
	: sprite()
	, textures(_textures)
{
	hide();
}



bool NextWaveIcon::isHidden() const
{
	return sprite.getColor().a == 0;
}



void NextWaveIcon::show(EnemyData nextEnemy)
{
	sprite.setTexture(textures.get(nextEnemy.texture));

	auto frame{ nextEnemy.animations.at(Direction::DownLeft).frames.at(0) };
	sprite.setTextureRect(frame.getRect());
	sprite.setRotation(frame.isRotated ? 90.f : 0.f);

	centerOrigin(sprite);

	sprite.setColor(sf::Color(255, 255, 255, 255));
}



void NextWaveIcon::hide()
{
	sprite.setColor(sf::Color(0, 0, 0, 0));
}



void NextWaveIcon::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}