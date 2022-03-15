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

#include <cmath>
#include <random>

#include <SFML/System/Vector2.hpp>



namespace sf {
	class Sprite;
	class Text;
}
class Animation;



bool isMouseOverRect(const sf::Vector2i mousePosition, const sf::Vector2f offset, const sf::IntRect rect);

bool isMouseOverRect(const sf::Vector2i mousePosition, const sf::IntRect rect);

sf::Vector2i pixelXYToTileXY(const sf::Vector2i);

sf::Vector2i pixelXYToTileXY(int x, int y);

int calculateXTile(const sf::Vector2i);

int calculateXTile(int x, int y);

int calculateYTile(const sf::Vector2i);

int calculateYTile(int x, int y);

sf::IntRect flip(const sf::IntRect& rec);

int	randomInt(int exclusiveMax);

void centerOrigin(sf::Sprite& sprite);

void centerOrigin(sf::Text& text);

void centerOrigin(Animation& animation);

float length(sf::Vector2f v);

sf::Vector2f normalizeVector(sf::Vector2f v);



// trig helper
const float PI{ 3.14159265f };



inline float radToDeg(float rad) 
{
	return rad * 180.f / PI;
}



inline float degToRad(float deg) 
{
	return deg * PI / 180.f;
}



inline float bering(float x, float y) 
{
	return 180 - radToDeg(std::atan2(x, y));
}



inline float bering(sf::Vector2f v) 
{
	return 180 - radToDeg(std::atan2(v.x, v.y));
}



namespace gex 
{
	inline float	sin(float deg) { return std::sin(degToRad(deg)); }
	inline float	cos(float deg) { return std::cos(degToRad(deg)); }
	inline float	atan2(float opp, float adj) { return radToDeg(std::atan2(opp, adj)); }

}
