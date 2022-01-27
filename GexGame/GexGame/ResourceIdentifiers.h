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



namespace sf {
	class Texture;
	class Font;
}



enum class TextureID
{
    TitleScreen,
    MainMenu,
    ForestBoard,
    CemeteryBoard,
    BeachBoard,
    MountainBoard,
    OnebyOne,
    ThreebyThree,
    FivebyFive,
    SevenbySeven,
    Particle,
};



enum class FontID
{
	Main
};



enum class SoundEffectID
{
};



enum class MusicID
{
};



template <typename Resource, typename Id>
class ResourceHolder;



using TextureHolder_t = ResourceHolder<sf::Texture, TextureID>;
using FontHolder_t = ResourceHolder<sf::Font, FontID>;