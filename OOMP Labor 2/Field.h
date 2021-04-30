#include <string>
#include "Board.h"
#include "Player.h"

#pragma once
class Field
{
private:
	std::string name;
	Field* next;
	Field* prev;
	Board* boad;

public:
	Field();
	~Field();

	void enter(Player& player, int fields_to_go);
};

