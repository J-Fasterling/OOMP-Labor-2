#include "Board.h"
#include "NoAction.h"
#include "Street.h"
#include "ActionField.h"
#include "Railroad.h"
#include "Tax.h"
#include "GoToJail.h"
#include "Utility.h"


Board::Board(int iPlayer)
{
	//Erstellen der Monopole
	Monopoly* mBraun = new Monopoly(50, "Braun");
	Monopoly* mOrange = new Monopoly(100, "Orange");
	Monopoly* mGelb = new Monopoly(150, "Gelb");
	Monopoly* mBlau = new Monopoly(200, "Blau");
	Monopoly* mBahn = new Monopoly(0,"Bahnhof");
	Monopoly* mVers = new Monopoly(0, "Versorgungswerk");

	//Fuellen des Spielbretts
	NoAction* Go = new NoAction(200, "Go");
	Board::vBoard.push_back(Go);
	Field* sBad = new Street("Badstrasse", 60, mBraun, 2, 10, 30, 90, 160, 250);
	Board::vBoard.push_back(sBad);
	Field* aGem1 = new ActionField("Gemeinschaftsfeld");
	Board::vBoard.push_back(aGem1);
	Field* sTurm = new Street("Turmstrasse", 60, mBraun, 4, 20, 60, 180, 320, 450);
	Board::vBoard.push_back(sTurm);
	Field* tTax1 = new Tax(200, "Einkommensteuer");
	Board::vBoard.push_back(tTax1);
	Field* rBahn1 = new Railroad("Suedbahnhof", mBahn);
	Board::vBoard.push_back(rBahn1);
	Field* gef1 = new GoToJail("Gefaengnis");
	Board::vBoard.push_back(gef1);
	Field* sMuen = new Street("Muenchenerstrasse", 180, mOrange, 14, 70, 200, 550, 750, 950);
	Board::vBoard.push_back(sMuen);
	Field* aGem2 = new ActionField("Ereignisfeld");
	Board::vBoard.push_back(aGem2);
	Field* sWien = new Street("Wiener Strasse", 180, mOrange, 14, 70, 200, 550, 750, 950);
	Board::vBoard.push_back(sWien);
	Field* sBerlin = new Street("Berliner Strasse", 200, mOrange, 16, 80, 220, 600, 800, 1000);
	Board::vBoard.push_back(sBerlin);
	Field* rBahn2 = new Railroad("Westbahnhof", mBahn);
	Board::vBoard.push_back(rBahn2);
	Field* uElek = new Utility("Elektrizitaetswerk", mVers);
	Board::vBoard.push_back(uElek);
	Field* naNoPark = new NoAction(0, "Frei Parken");
	Board::vBoard.push_back(naNoPark);



	std::vector <Player> vPlayer;
}


Board::~Board() {}