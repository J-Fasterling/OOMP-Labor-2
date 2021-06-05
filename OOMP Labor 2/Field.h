#pragma once

#include <string>
#include <iostream>
#include <Windows.h>
#include "Player.h"

class Board;
class Monopoly;
class Field
{
private:
	//nachfolgendes Feld
	Field* next;
	//Vorangehendes Feld
	Field* prev;
	//Name des Felds
	std::string name;	

protected:
	Board* board;


public:
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();

	//Ausgabe, welcher Spieler welches Feld betreten hat
	virtual void enter(Player& player) = 0;

	//Setzt das nachfolgende Feld
	void set_Next(Field* fNext);

	//setzt das vorangegangene Feld
	void set_Prev(Field* fPrev);

	//Gibt das nachfolgende Feld zurueck
	Field* get_Next();

	//Gibt den Namen des Felds zurueck
	std::string get_Name();

	//gibt das zugeh�rige Monopol eines Feldes zur�ck
	virtual Monopoly* get_Monopoly();

	//gibt den Hauspreis zurueck
	virtual Monopoly* get_House_price();

	//Gibt den Besitzer des Felds zurueck
	virtual Player* get_Owner();


};

