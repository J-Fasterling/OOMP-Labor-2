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
	//Monopoly monopolies[6];
	int dice[2];
	//void addField(Field fField);
	std::vector <Field*> vBoard;

public:
	Board(int iPlayer);
	~Board();
};

