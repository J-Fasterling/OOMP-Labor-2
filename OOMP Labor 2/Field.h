#include <string>
#include <iostream>

#include "Board.h"

#pragma once
class Field
{
private:
	
	Field* next;
	Field* prev;
	std::string name;
	//Board* board;

public:
	
	Field(std::string _name = "Neues Feld", Field* _next = NULL, Field* _prev = NULL);
	//~Field();

	virtual void enter(Player& player, int fields_to_go);
};

