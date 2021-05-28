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

	//gibt an welcher Modus
	bool demo_Mode;

	//Array der Wuerfel Augenzahlen
	int dice[2];
	//Alle Felder des Spielbrettes
	std::vector <Field*> vBoard;

	//Verknuepft die einzelnen Spielfelder
	void create_Playboard();

	//bestimmt die Anzahl der Spieler und weist ihnen Namen zu
	void choose_Players();

	//erzeugt den allgemeine Spielablauf
	void game_Engine();

	//wuerfelt eine Zufallszahl
	int throw_Dice();

	//Bewegt den Spieler auf dem Feld X Schritte vorwaerts
	void go_X_Steps(int iDice, Player* player);

	//Setzt die Monopole
	void set_Monopolies();


public:
	Board();
	~Board();

	//gibt den Spielmodus zurueck
	bool get_Playmode();

	//gibt Wuerfelzahl zurueck
	int get_Dice();

	//Setzt den Spielmodus
	void set_Playmode(bool playmode);

	//Abfrage ob aus Gefaengnis freikaufen
	bool want_to_leave_Jail(Player& player);

	//Spieler pleite seine Grundstuecke abgeben
	void give_properties_to_owner();
};

