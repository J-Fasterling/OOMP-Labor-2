#include "Field.h"
#include "Player.h"
#include "Monopoly.h"

#pragma once
class Board
{
private:
	Field* go;
	Player player[];
	Monopoly monopolies[];
	int dice[2];

public:
	Board();
	Board(Field* fGo, Player pPlayer[], Monopoly mMonopolies[], int iDice[2]);
	virtual ~Board();
};

