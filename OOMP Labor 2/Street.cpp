#include "Street.h"

Street::Street(std::string _name, int _value, Monopoly* _monopoly,
	int m1, int m2, int m3, int m4, int m5, int m6)
	: Property(_name, _value, _monopoly), houses {0}
{
	rent[0] = m1;
	rent[1] = m2;
	rent[2] = m3;
	rent[3] = m4;
	rent[4] = m5;
	rent[5] = m6;
	std::cout << "Feldname " << _name << std::endl;
}


Street::~Street() {}

int Street::get_rent() 
{
	if (this->getMonopoly()->has_all(*this->getOwner()) && houses == 0)
	{
		return rent[0] * 2;
	}
	else
	{
		return rent[houses];
	}
}

int Street::build_houses()
{
	if (houses < 5)
	{
		return houses + 1;
	}
	else
	{
		return 0;
	}
}

