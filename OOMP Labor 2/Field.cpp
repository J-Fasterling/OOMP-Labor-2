#include "Field.h"
#include "Player.h"
#include <iostream>
#include <string>

Field::Field(std::string _name, Field* _next, Field* _prev) 
	: name{ _name }, next{ _next }, prev{_prev}{
	std::cout << "Es wurde ein Feld erzeugt"<< std::endl;
}

Field::~Field() {}

void Field::setNext(Field* fNext)
{
	next = fNext;
}

void Field::setPrev(Field* fPrev)
{
	prev = fPrev;
}

void enter(Player& player) {}
