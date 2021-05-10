#pragma once

#include <stdio.h>
#include <vector>
#include <string>

class Property;
class Field;
class Player;
class Monopoly
{
private:
	//Name des Monopols
	std::string name;
	//Preis pro Haus
	int price_for_house;
	//Container aller Grundtuecke des Monopols
	std::vector <Field*> vProperties;

public:
	Monopoly(int _price_for_house, std::string _name = "Monopoly", std::vector <Field*> _properties = std::vector<Field*>());
	Monopoly();
	~Monopoly();
	void setProperties(Field* property);
	std::string get_name();

	int count_owned_properties(Player& player);

	bool has_all(Player& player);
};

