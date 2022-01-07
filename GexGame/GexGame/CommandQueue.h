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

#include "Command.h"

#include <queue>



class CommandQueue
{
public:
	void		push(const Command& command);
	Command		pop();
	bool		isEmpty() const;

private:
	std::queue<Command> queue;

};
