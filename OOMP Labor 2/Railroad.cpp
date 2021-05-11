#include "Railroad.h"


Railroad::Railroad(std::string _name, Monopoly* _monopoly)
	: Property(_name, 200, _monopoly)
{
	rent[0] = 25;
	rent[1] = 50;
	rent[2] = 100;
	rent[3] = 200;
	std::cout <<  " Feldname " << _name << std::endl;
}

Railroad::~Railroad() {}


int Railroad::get_rent() 
{
	return rent[this->getMonopoly()->count_owned_properties(*this->getOwner()) - 1]; 
}
