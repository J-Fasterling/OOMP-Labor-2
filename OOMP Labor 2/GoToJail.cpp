#include "GoToJail.h"
#include <iostream>
#include <string>

GoToJail::GoToJail(std::string _name, Field* _jail) : Field(_name), jail{ _jail } {
	
	std::cout << "Feldname: " << _name << std::endl;
}

GoToJail::~GoToJail() {}

void GoToJail::enter(Player& player)
{
	//Spieler in das Gefaengnis setzen
	player.setField(jail);
	Field::enter(player);
	std::cout << player.get_Name() << " muss ins " << player.getField()->getName() << std::endl;
}

Monopoly* GoToJail::getMonopoly() {
	return NULL;
}
