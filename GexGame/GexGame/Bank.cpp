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
#include "Bank.h"
#include "TextNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"



Bank::Bank(const FontHolder_t& fonts, std::size_t _balance)
	: goldDisplay(nullptr)
	, balance(_balance)
{
	auto goldNode{ std::make_unique<TextNode>(fonts, std::to_string(balance))};
	goldDisplay = goldNode.get();
	attachChild(std::move(goldNode));
}



std::size_t Bank::withdraw(const std::size_t amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		goldDisplay->setString(std::to_string(balance));
		return amount;
	}
	else
	{
		return 0;
	}
}



void Bank::deposit(const std::size_t amount)
{
	balance += amount;
	goldDisplay->setString(std::to_string(balance));
}



std::size_t Bank::getBalance() const
{
	return balance;
}
