#include "Field.h"
#include <iostream>
#include <string>

Field::Field(std::string _name, Board* _board) : name{ _name }, board{ _board }{
	std::cout << "Feldname: " << _name << "Nächstes Feld: " << _next->name << "Vorheriges Feld: " << _prev->name << std::endl;
}

