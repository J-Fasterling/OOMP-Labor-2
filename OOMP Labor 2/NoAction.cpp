#include "NoAction.h"
#include <iostream>
#include <string>

NoAction::NoAction(int _get_money, std::string _name, Field* _next, Field* _prev) : Field(_name, _next, _prev), get_money{_get_money} {

	std::cout << "Feldname: " << _name << std::endl;
}
