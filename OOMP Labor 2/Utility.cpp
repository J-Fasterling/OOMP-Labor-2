#include "Utility.h"

Utility::Utility(std::string _name, Monopoly* _monopoly)
	: Property(_name, 150, _monopoly), dice_factor_single{ 4 },
	dice_factor_monopoly {10} {
	std::cout << "Feldname " << _name << std::endl; 
}

Utility::~Utility() {}

int Utility::get_rent()
{	
	if (this->getMonopoly()->has_all(*this->getOwner()))
	{
		return dice_factor_monopoly * ((rand() % ((12 + 2) - 2)) + 2);
	}
	else
	{
		return dice_factor_single * ((rand() % ((12 + 2) - 2)) + 2);
	}
}

