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
	//Spieler Geld zuschreiben
	player.set_Money(player.get_Money() + get_money);
	std::cout << player.get_Name() << " ist auf Los gekommen und bekommt zusaetzlich ";
	//Konsolenschriftfarbe auf gruen setzen
	SetConsoleTextAttribute(hConsole, 10);
	std::cout << "200$." << std::endl;
	//Konsolenschriftfarbe zuruecksetzen
	SetConsoleTextAttribute(hConsole, 15); 
	
}

Monopoly* NoAction::get_Monopoly() 
{
	return NULL;
}