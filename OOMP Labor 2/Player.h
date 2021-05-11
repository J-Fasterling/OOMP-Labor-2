#pragma once

//#include "Field.h"
#include <stdio.h>
#include <string>

class Field;
class Property;
class Monopoly;
class Player
{
private:
	//Kontostand des Spielers
	int money;
	//aktuelles Feld des Spielers
	Field* field;
	//Name des Spielers
	std::string name;


public:
	Player(Field* fField, std::string sName);
	~Player();

	//gibt den Namen des Spielers zurueck
	std::string get_Name();

	//Setzt den Spieler auf ein angegebenes Feld
	void setField(Field* fField);

	//Gibt das Feld zurueck, auf dem sich der Spieler befindet
	Field* getField();

	//Setzt den Kontostand des Spielers 
	void setMoney(int iMoney);

	//Gibt den Kontostand des Spielers aus
	int getMoney();

	//Abfrage ob der Spieler ein freies Feld kaufen moechte
	bool want_to_buy_Property(Property& property, Player& player);

	//Abfrage ob Spieler Haeser kaufen will
	bool want_to_buy_Houses(Property& property, Player& player, Monopoly& _price_for_house);

};
