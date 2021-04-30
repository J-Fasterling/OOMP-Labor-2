#include "Field.h"
#include <iostream>
#include <string>

Field::Field(std::string _name, Field* _next, Field* _prev, Board* _board) : name{ _name }, next{ _next }, prev{ _prev }, board{ _board }{
	std::cout << "Feldname: " << __name << "Nächstes Feld: " << _next->name << "Letzes Feld: " << _prev->name << std::endl;
}

