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
#include "CommandQueue.h"



void CommandQueue::push(const Command& command)
{
	queue.push(command);
}



Command CommandQueue::pop()
{
	Command command = queue.front();
	queue.pop();
	return command;
}



bool CommandQueue::isEmpty() const
{
	return queue.empty();
}
