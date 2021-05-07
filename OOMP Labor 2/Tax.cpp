#include "Tax.h"
#include <iostream>
#include <string>

Tax::Tax(int _amount, std::string _name, Field* _next, Field* _prev) : amount{_amount}, Field(_name, _next, _prev) {

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
