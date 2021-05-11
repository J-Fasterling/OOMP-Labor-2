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
	~Monopoly();

	//Setzt die Properties
	void set_Properties(Field* property);
	
	//Gibt den Namen des Monopols zurueck
	std::string get_name();

	//Zaehlt die Grundstuecke eines Monopols eines Spielers
	int count_owned_properties(Player& player);

	//Abfrage ob ein Spieler alle Felder eines Monopols besitzt
	bool has_all(Player& player);

	//Preis eines Hauses
	int get_PriceforHouse();
};

