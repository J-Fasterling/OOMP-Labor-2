#include "ActionField.h"

ActionField::ActionField(std::string _name, Field* _next, Field* _prev) : Field(_name, _next, _prev) {

	std::cout << "Feldname: " << _name << std::endl;
}

ActionField::ActionField() {}

ActionField::~ActionField() {}