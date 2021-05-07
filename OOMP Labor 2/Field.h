#include <string>
//#include "Board.h"
//#include "Player.h"

#pragma once
class Field
{
private:
	std::string name;
	Field* next;
	Field* prev;

public:
	Field();
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();

};

