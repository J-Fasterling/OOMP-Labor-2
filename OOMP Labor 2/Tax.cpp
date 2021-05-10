#include "Tax.h"
#include <iostream>
#include <string>

Tax::Tax(int _amount, std::string _name) : amount{_amount}, Field(_name) {

	std::cout << "Feldname: " << _name << std::endl;
}

Tax::~Tax() {}

void Tax::enter(Player& player) 
{
	Field::enter(player);
	player.setMoney(player.getMoney() - amount);
}

Monopoly* Tax::getMonopoly() 
{
	return NULL;
}