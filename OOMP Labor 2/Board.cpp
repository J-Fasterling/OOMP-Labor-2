#include "Board.h"
#include <stdlib.h>
#include <string>

using namespace std;

Board::Board(Player pPlayer[], Monopoly mMonopolies[], int iDice[2]):player[]{ pPlayer }, monopolies[]{ mMonopolies }, dice[2]{ iDice[2] } {

	//40 Felder sollen erstellt werden
	Field* fields_on_board[40];

	//Die Stelle vom Feld "Los" soll vom Board gemerkt werden
	go{ &fields_on_board[0] };

	//Erstellen der entsprechenden Felder
	fields_on_board[0] = new NoAction("Los", &fields_on_board[1], &fields_on_board[39]);
	fields_on_board[1] = new Street("Badstraße", &fields_on_board[2], &fields_on_board[0]);
	fields_on_board[2] = new ActionField("Gemeinschaftsfeld", &fields_on_board[3], &fields_on_board[1]);
	fields_on_board[3] = new Street("Turmstraße", &fields_on_board[4], &fields_on_board[2]);
	fields_on_board[4] = new Tax("Einkommenssteuer", &fields_on_board[5], &fields_on_board[3]);
	fields_on_board[5] = new Railroad("Südbahnhof", &fields_on_board[6], &fields_on_board[4]);
	fields_on_board[6] = new Street("Chausseestraße", &fields_on_board[7], &fields_on_board[5]);
	fields_on_board[7] = new ActionField("Ereignisfeld", &fields_on_board[8], &fields_on_board[6]);
	fields_on_board[8] = new Street("Elisenstraße", &fields_on_board[9], &fields_on_board[7]);
	fields_on_board[9] = new NoAction("Nur zu Besuch (im Gefängnis)", &fields_on_board[10], &fields_on_board[8]);
	fields_on_board[10] = new Street("Seestraße", &fields_on_board[11], &fields_on_board[9]);
}

Board::~Board()
{
}


/*
void Board::Anfangsfeld(string _name, Field* _next, Field* _prev, Board* _board) { 
	Field* go = new Field("Los", next _next , prev _prev, board _board);
	
}
*/