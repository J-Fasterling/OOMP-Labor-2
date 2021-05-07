#include <string>
#include <iostream>

#include "Board.h"

#pragma once
class Field
{
private:
	
	Field* next;
	Field* prev;

public:
	Field();
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();

};

