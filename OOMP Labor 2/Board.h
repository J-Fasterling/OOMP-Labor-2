#pragma once
#include <vector>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"

using namespace std;

class Board
{
private:
	//Container mit allen spielenden Spielern
	std::vector <Player*> vPlayer;
	//Array aller Monopole
	Monopoly* monopolies[10];
	//Array der Wuerfel Augenzahlen
	int dice[2];
	//Alle Felder des Spielbrettes
	std::vector <Field*> vBoard;

	//Verknuepft die einzelnen Spielfelder
	void createPlayboard();

	//bestimmt die Anzahl der Spieler und weist ihnen Namen zu
	void choosePlayers();

	//erzeugt den allgemeine Spielablauf
	void gameEngine();

	//wuerfelt eine Zufallszahl
	int throwDice();

	//Bewegt den Spieler auf dem Feld X Schritte vorwaerts
	void go_X_Steps(int iDice, Player* player);

	void setMonopolies();


public:
	Board();
	~Board();
};

