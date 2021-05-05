#include "Field.h"
#include <iostream>
#include <string>

Field::Field(std::string _name, Field* _next, Field* _prev) : name{ _name }, next{ _next }, prev{_prev}{
	std::cout << "Feldname: " << _name << std::endl;
}

