#include "Tax.h"
#include <iostream>
#include <string>

Tax::Tax(int _amount, std::string _name, Field* _next, Field* _prev) : Field(_name, _next, _prev), amount{_amount} {

	std::cout << "Feldname: " << _name << std::endl;
}
