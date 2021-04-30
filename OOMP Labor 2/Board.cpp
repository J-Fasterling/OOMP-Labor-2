#include "Board.h"
#include <stdlib.h>
#include <string>

using namespace std;

Board::Board(Field* fGo, Player pPlayer[], Monopoly mMonopolies[], int iDice[2]):
	go{ fGo }, player[]{ pPlayer }, monopolies[]{ mMonopolies }, dice[2]{ iDice[2] } {

}

Board::~Board()
{
}

void Board::Anfangsfeld(string _name, Field* _next, Field* _prev, Board* _board) { 
	Field* go = new Field("Los", next _next , prev _prev, board _board);
	
}
