#include "NoAction.h"
#include <iostream>
#include <string>

NoAction::NoAction(int _get_money, std::string _name, Field* _next, Field* _prev) : Field(_name, _next, _prev), get_money{_get_money} {

	std::cout << "Feldname: " << _name << std::endl;

	/*
	if (_next != NULL) {
		std::cout << "Naechstes Feld: " << _next->name << std::endl;
	}
	if (_prev != NULL) {
		std::cout << "Vorheriges Feld: " << _prev->name << std::endl;
	}
	*/
}
