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



namespace Category
{
	enum Type 
	{
		None				= 0,
		SceneAirLayer		= 1 << 0,
		ParticleSystem		= 1 << 7,
		SoundEffect			= 1 << 8,

		//SpaceJunk			= Aircraft | Projectile | Pickup,

	};
}
