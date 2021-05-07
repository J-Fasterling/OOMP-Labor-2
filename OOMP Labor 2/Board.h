#pragma once
#include <vector>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"

class Board
{
private:
	Field* playField;
	std::vector <Player*> vPlayer;
	Monopoly* monopolies[6];
	int dice[2];
	std::vector <Field*> vBoard;

	void createPlayboard(std::vector<Field*> vField);
	void choosePlayers();

public:
	Board();
	~Board();
};

