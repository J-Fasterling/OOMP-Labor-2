#pragma once

#include <stdio.h>
#include <vector>
#include <string>

class Property;
class Monopoly
{
private:
	std::string name;
	int price_for_house;
	std::vector <Property> properties;

public:
	Monopoly(int _price_for_house, std::string _name = "Monopoly", std::vector <Property> _properties = std::vector<Property>());
	~Monopoly();
};

