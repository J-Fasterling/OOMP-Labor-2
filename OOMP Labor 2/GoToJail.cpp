#include "GoToJail.h"
#include <iostream>
#include <string>

GoToJail::GoToJail(std::string _name, Field* _jail) : Field(_name), jail{ _jail } {
	
	std::cout << "Feldname: " << _name << std::endl;
}

GoToJail::~GoToJail() {}

void enter(Player& player) {}
