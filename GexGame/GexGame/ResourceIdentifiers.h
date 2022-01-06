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
	Entities,
    Jungle,
    Desert,
    TitleScreen,
    Explosion,
    Particle,
    FinishLine,

    Hero2,
    Zombie1,
    Zombie2,
    Zombie3,
    Zombie4,
    Zombie5,
    Road,
};



enum class FontID
{
	Main
};



enum class SoundEffectID
{
    AlliedGunfire,
    EnemyGunfire,
    Explosion1,
    Explosion2,
    LaunchMissile,
    CollectPickup,
    Button,
};



enum class MusicID
{
    MenuTheme,
    MissionTheme,
};



template <typename Resource, typename Id>
class ResourceHolder;



using TextureHolder_t = ResourceHolder<sf::Texture, TextureID>;
using FontHolder_t = ResourceHolder<sf::Font, FontID>;
