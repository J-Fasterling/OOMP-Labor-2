#include "ActionField.h"

ActionField::ActionField(std::string _name) : Field(_name) {

	std::cout << "Feldname: " << _name << std::endl;
}

ActionField::~ActionField() {}