#include "Board.h"
#include <stdlib.h>

Board::Board(Field* fGo, Player pPlayer[], Monopoly mMonopolies[], int iDice[2]):
	go{fGo}, player[]{pPlayer}, monopolies[]{mMonopolies}, dice[2]{iDice[2]}
