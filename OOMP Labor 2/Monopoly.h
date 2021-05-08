#pragma once

#include <stdio.h>
#include <vector>
#include <string>

class Property;
class Monopoly
{
private:
	//Name des Monopols
	std::string name;
	//Preis pro Haus
	int price_for_house;
	//Container aller Grundtuecke des Monopols
	std::vector <Property*> properties;

public:
	Monopoly(int _price_for_house, std::string _name = "Monopoly", std::vector <Property*> _properties = std::vector<Property*>());
	Monopoly();
	~Monopoly();
};

