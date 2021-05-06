#include "Field.h"
#include "Player.h"
#include "Monopoly.h"
#include <string>

#pragma once
class Board
{
private:
	Field* go;
	vector <Player> player;
	vector <Monopoly> monopolies;
	int dice[2];

public:
	Board();
	virtual ~Board();
	void Anfangsfeld(string _name, Field* next, Field* prev, Board* board);
};

