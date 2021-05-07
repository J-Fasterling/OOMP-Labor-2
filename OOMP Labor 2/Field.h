#pragma once

#include <string>
#include <iostream>

class Board;
class Field
{
private:
	
	Field* next;
	Field* prev;
	std::string name;
	//Board* board;

public:
	//Field();
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();
};

