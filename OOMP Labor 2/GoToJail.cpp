#include "GoToJail.h"
#include <iostream>
#include <string>

GoToJail::GoToJail(Field* _jail, std::string _name, Field* _next, Field* _prev) : Field(_name, _next, _prev), jail{ _jail } {
	
	std::cout << "Feldname: " << _name << std::endl;

}
