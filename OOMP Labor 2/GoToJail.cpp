#include "GoToJail.h"
#include <iostream>
#include <string>

GoToJail::GoToJail(std::string _name, Field* _next, Field* _prev, Field* _jail) : Field(_name, _next, _prev), jail{ _jail } {
	
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
