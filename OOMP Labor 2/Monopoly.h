#pragma once

#include <stdio.h>
#include <vector>
#include "Property.h"

class Monopoly
{
private:
	std::string name;
	int price_for_house;
	std::vector <Property> properties;

public:
	Monopoly();
	Monopoly(std::string sName, int iPrFoHo = 0);
	~Monopoly();
};

