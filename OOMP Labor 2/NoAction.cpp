#include "NoAction.h"
#include <iostream>
#include <string>

NoAction::NoAction(int _get_money, std::string _name) : Field(_name), get_money{_get_money} {

	std::cout << "Feldname: " << _name << std::endl;
}

NoAction::~NoAction() {}

void NoAction::enter(Player& player)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Field::enter(player);
	player.setMoney(player.getMoney() + get_money);
	std::cout << player.get_Name() << " ist auf Los gekommen und bekommt zusaetzlich ";
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "200$." << std::endl;
	SetConsoleTextAttribute(hConsole, 15); 
	
}

Monopoly* NoAction::getMonopoly() 
{
	return NULL;
}