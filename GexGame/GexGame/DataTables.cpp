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
#include "DataTables.h"
#include "JsonFrameParser.h"



std::map<LevelType, LevelData> initializeLevelData()
{
	std::map<LevelType, LevelData> data;

	data[LevelType::Forest].backgroundTexture = TextureID::ForestBoard;
	data[LevelType::Forest].backgroundTexturePath = "../Media/Textures/ForestBoard.png";
	data[LevelType::Forest].lanes.push_back(LaneData());
	data[LevelType::Forest].lanes.at(0).position = sf::Vector2f(1042.f, 84.f);

	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 18; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownRight);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 12; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownRight);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 10; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::UpLeft);
	}
	for (int i{ 0 }; i < 2; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 6; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::UpLeft);
	}
	for (int i{ 0 }; i < 4; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}
	for (int i{ 0 }; i < 8; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownRight);
	}
	for (int i{ 0 }; i < 5; ++i)
	{
		data[LevelType::Forest].lanes.at(0).route.push_back(AnimatedNode::Direction::DownLeft);
	}


	data[LevelType::Cemetery].backgroundTexture = TextureID::CemeteryBoard;
	data[LevelType::Cemetery].backgroundTexturePath = "../Media/Textures/CemeteryBoard.png";

	data[LevelType::Beach].backgroundTexture = TextureID::BeachBoard;
	data[LevelType::Beach].backgroundTexturePath = "../Media/Textures/BeachBoard.png";

	data[LevelType::Mountain].backgroundTexture = TextureID::MountainBoard;
	data[LevelType::Mountain].backgroundTexturePath = "../Media/Textures/MountainBoard.png";

	return data;
}



std::map<AnimatedNode::Type, EnemyData> initializeEnemyData()
{
	std::map<AnimatedNode::Type, EnemyData> data;

	JsonFrameParser frames{ JsonFrameParser("../Media/Textures/LichAtlasFlipped.json") };
	data[AnimatedNode::Type::Lich].texture = TextureID::Lich;
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpRight].addFrameSet(frames.getFramesFor("LichWalkUpRight"));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpRight].setDuration(sf::seconds(1.0f));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpRight].setRepeating(true);
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownRight].addFrameSet(frames.getFramesFor("LichWalkDownRight"));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownRight].setDuration(sf::seconds(1.0f));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownRight].setRepeating(true);
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownLeft].addFrameSet(frames.getFramesFor("LichWalkDownLeft"));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownLeft].setDuration(sf::seconds(1.0f));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::DownLeft].setRepeating(true);
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpLeft].addFrameSet(frames.getFramesFor("LichWalkUpLeft"));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpLeft].setDuration(sf::seconds(1.0f));
	data[AnimatedNode::Type::Lich].animations[AnimatedNode::Direction::UpLeft].setRepeating(true);

	return data;
}



std::map<Particle::Type, ParticleData> initializeParticleData()
{
	std::map<Particle::Type, ParticleData> data;

	data[Particle::Type::Propellant].color = sf::Color(255, 255, 50);
	data[Particle::Type::Propellant].lifetime = sf::seconds(0.6f);

	data[Particle::Type::Smoke].color = sf::Color(50, 50, 50);
	data[Particle::Type::Smoke].lifetime = sf::seconds(4.f);

	return data;
}
