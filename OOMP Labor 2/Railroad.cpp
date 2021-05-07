#include "Railroad.h"

/// <summary>
/// Railroad
/// </summary>
/// <param name="_name"></param>
/// <param name="_value"></param>
/// <param name="_monopoly"></param>
Railroad::Railroad(std::string _name, Monopoly* _monopoly)
	: Property(_name, 200, _monopoly)
{
	rent[0] = 25;
	rent[1] = 50;
	rent[2] = 100;
	rent[3] = 200;
}

Railroad::~Railroad() {}

int Railroad::get_rent(int _type) { return rent[_type]; }