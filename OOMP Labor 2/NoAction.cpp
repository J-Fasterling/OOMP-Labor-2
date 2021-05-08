#include "NoAction.h"
#include <iostream>
#include <string>

NoAction::NoAction(int _get_money, std::string _name) : Field(_name), get_money{_get_money} {

	std::cout << "Feldname: " << _name << std::endl;
}

NoAction::~NoAction() {}

void NoAction::enter(Player& player) {
	Field::enter(Player & player);
}
