#pragma once

//#include "Field.h"
#include <stdio.h>
#include <string>
#include <array>

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
	//Ist Spieler im Gefaengnis
	bool is_in_jail;
	//Rundencounter im Gefaengnis
	int rounds_in_jail;
	//Bankrott Attribut
	bool broke;
	

public:
	Player(Field* fField, std::string sName);
	~Player();

	//gibt den Namen des Spielers zurueck
	std::string get_Name();

	//Setzt den Spieler auf ein angegebenes Feld
	void set_Field(Field* fField);

	//Gibt das Feld zurueck, auf dem sich der Spieler befindet
	Field* get_Field();

	//Geldzustand
	//Setzt den Kontostand des Spielers 
	void set_Money(int iMoney);

	//Gibt den Kontostand des Spielers aus
	int get_Money();

	//Player pleite setzen
	bool set_broke();

	//get Geldstatus Spieler
	bool get_broke();

	//kaufen
	//Abfrage ob der Spieler ein freies Feld kaufen moechte
	bool want_to_buy_Property(Property& property, Player& player);

	//Abfrage ob Spieler Haeser kaufen will
	bool want_to_buy_Houses(Property& property, Player& player);

	//Array erstellen mit allen Grundstuecken die Spieler gehören
	std::array<Property*, 28> imperium = { };

	//Gefaengnis
	//Markiert Spieler als Gefaengnis Insassen
	void is_inmate();
	
	//Spieler kommt aus dem Gefaengnis
	void prison_break(Player& player);

	//Gibt aus ob im Gefaengnis
	bool get_is_in_jail();

	//Gibt Runden im Gefaengnis zurueck
	int get_rounds_in_jail();

	//Zaehlt Runden im Gefaegnis hoch
	void set_rounds_in_jail();

};
