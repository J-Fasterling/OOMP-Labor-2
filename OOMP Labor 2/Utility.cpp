#include "Utility.h"

Utility::Utility(std::string _name, Monopoly* _monopoly)
	: Property(_name, 150, _monopoly), dice_factor_single{ 4 },
	dice_factor_monopoly {10} {
	std::cout << "Feldname " << _name << std::endl; 
}

Utility::~Utility() {}

int Utility::get_rent()
{
	return 1;
}

