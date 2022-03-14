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
#include "Animation.h"
#include "utility.h"

#include <random>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>



namespace
{
	std::default_random_engine createRandomEngine()
	{
		auto seed{ static_cast<unsigned long>(std::time(nullptr)) };
		return std::default_random_engine(seed);
	}

	auto randomEngine{ createRandomEngine() };
}



sf::Vector2i pixelXYToTileXY(const sf::Vector2i v)
{
    return sf::Vector2i(calculateXTile(v), calculateYTile(v));
}



sf::Vector2i pixelXYToTileXY(int x, int y)
{
	return pixelXYToTileXY(sf::Vector2i(x, y));
}



int calculateXTile(const sf::Vector2i v)
{
	static const double xTriangleTangent{ 2.0 / 3 };

	static const int tileHeight{ 48 };
	static const int xTriangleTotalHeight{ 888 };
	static const int xTriangleExcess{ 504 - 158 };
	const double xTriangleHeight{ xTriangleTangent * (v.x + xTriangleExcess) };

	return (v.y - (xTriangleTotalHeight - xTriangleHeight)) / tileHeight;
}



int calculateXTile(int x, int y)
{
	return calculateXTile(sf::Vector2i(x, y));
}



int calculateYTile(const sf::Vector2i v)
{
	static const double yTriangleTangent{ 1.5 };

	static const int tileWidth{ 72 };
	static const int yTriangleOffset{ 72 };
	static const int yTriangleExcess{ 408 + 106 };
	const double yTriangleWidth{ yTriangleTangent * (v.y + yTriangleExcess) };

	return (yTriangleWidth + yTriangleOffset - v.x) / tileWidth;
}



int calculateYTile(int x, int y)
{
	return calculateYTile(sf::Vector2i(x, y));
}



sf::IntRect flip(const sf::IntRect& rec)
{
	auto temp = rec;
	temp.left += temp.width;
	temp.width *= 1;
	return temp;
}



int randomInt(int exclusiveMax)
{
	std::uniform_int_distribution<int> dist{ 0, exclusiveMax - 1 };

	return dist(randomEngine);
}



void centerOrigin(sf::Sprite& sprite)
{
	auto bounds{ sprite.getLocalBounds() };

	sprite.setOrigin(
		std::floor(bounds.left + bounds.width / 2.f),
		std::floor(bounds.top + bounds.height / 2.f)
	);
}



void centerOrigin(sf::Text& text)
{
	auto bounds { text.getLocalBounds() };

	text.setOrigin(
		std::floor(bounds.left + bounds.width / 2.f),
		std::floor(bounds.top + bounds.height / 2.f)
	);
}



void centerOrigin(Animation& animation)
{
	auto bounds { animation.getLocalBounds() };

	animation.setOrigin(
		std::floor(bounds.left + bounds.width / 2.f),
		std::floor(bounds.top + bounds.height / 2.f)
	);
}



float length(sf::Vector2f v)
{
	return std::sqrt(pow(v.x, 2.f) + pow(v.y, 2.f));
}



sf::Vector2f normalizeVector(sf::Vector2f v)
{
	const float vectorLength{ length(v) };

    if (vectorLength > 0.0001f) {
		v /= vectorLength;
    }

	return v;
}