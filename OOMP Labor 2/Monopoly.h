#include "Property.h"
#include <string>

#pragma once
class Monopoly
{
private:
	std::string name;
	int price_for_house;
	Property* properties[];

public:
	Monopoly();
	~Monopoly();
};

