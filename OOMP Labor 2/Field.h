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
	//Board* board;

public:
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();

	//virtual void enter(Player& player, int fields_to_go);
};

