#include "Tax.h"
#include <iostream>
#include <string>

Tax::Tax(int _amount, std::string _name) : amount{_amount}, Field(_name) {

	std::cout << "Feldname: " << _name << std::endl;
}

Tax::~Tax() {}

void Tax::enter(Player& player) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Field::enter(player);

	//Spieler bezahlt Steuern
	player.setMoney(player.getMoney() - amount);
	std::cout << player.get_Name() << " muss ";
	//Konsolenschriftfarbe auf rot setzen
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << amount << "$";
	//Konsolenschriftfarbe zuruecksetzen 
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " an Steuern bezahlen." << std::endl;
}

Monopoly* Tax::getMonopoly() 
{
	return NULL;
}