#pragma once

#include <string>
#include <iostream>
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

public:
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();

	//Ausgabe, welcher Spieler welches Feld betreten hat
	virtual void enter(Player& player) = 0;

	//Setzt das nachfolgende Feld
	void setNext(Field* fNext);

	//setzt das vorangegangene Feld
	void setPrev(Field* fPrev);

	//Gibt das nachfolgende Feld zurueck
	Field* getNext();

	//Gibt den Namen des Felds zurueck
	std::string getName();

	//gibt das zugehörige Monopol eines Feldes zurück
	virtual Monopoly* getMonopoly();

	virtual Player* getOwner();
};

