#pragma once
#include <vector>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"

class Board
{
private:
	Field* playField;
	std::vector <Player> player;
	std::vector <Monopoly> monopolies;
	int dice[2];

public:
	Board();
	Board(Field* fPlayField);
	~Board();
	void Anfangsfeld(std::string sName, Field* next, Field* prev);
};

