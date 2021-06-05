#include "Field.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Board.h"

Field::Field(std::string _name, Field* _next, Field* _prev) 
	: name{ _name }, next{ _next }, prev{ _prev }{
	std::cout << "Es wurde ein Feld erzeugt"<< std::endl;
}

Field::Field(std::string _name, Board* _board)
	: name {_name}, board {_board}{
	std::cout << "Es wurde ein Feld erzeugt" << std::endl;
}

Field::~Field() {}


void Field::set_Next(Field* fNext)
{
	next = fNext;
}


void Field::set_Prev(Field* fPrev)
{
	prev = fPrev;
}


void Field::enter(Player& player)
{
	std::cout << player.get_Name() << " betritt " << name << "." << std::endl;
}


Field* Field::get_Next()
{
	return next;
}


std::string Field::get_Name()
{
	return name;
}


Monopoly* Field::get_Monopoly()
{
	return NULL;
}

Monopoly* Field::get_House_price() 
{
	return NULL;
}

Player* Field::get_Owner()
{
	return NULL;
}
