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



enum class StateID
{
	None,
	Title,
	Menu,
	Game,
	Loading,
	Pause,
	GameOver,
	ForestLevel,
	CemeteryLevel,
	BeachLevel,
	MountainLevel,
};
