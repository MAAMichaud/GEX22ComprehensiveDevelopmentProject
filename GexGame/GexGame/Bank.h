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

#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"



class TextNode;



class Bank : public SceneNode
{
public:
								Bank(const FontHolder_t& fonts, std::size_t balance = 60);

	std::size_t					withdraw(std::size_t amount);
	void						deposit(std::size_t amount);
	std::size_t					getBalance();

private:
	TextNode*					goldDisplay;
	std::size_t					balance;

};
