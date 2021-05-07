#pragma once

#include <stdio.h>
#include <vector>
#include <string>
//#include "Property.h"
class Property;
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

