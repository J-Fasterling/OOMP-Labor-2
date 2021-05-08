#include "Board.h"
#include "NoAction.h"
#include "Street.h"
#include "ActionField.h"
#include "Railroad.h"
#include "Tax.h"
#include "GoToJail.h"
#include "Utility.h"


Board::Board()
{
	std::cout << "           MONOPOLY              " << std::endl;
	std::cout << "---------------------------------" << std::endl << std::endl;

	//Erstellen der Monopole
	monopolies[0] = new Monopoly(50, "Braun");
	monopolies[1] = new Monopoly(100, "Orange");
	monopolies[2] = new Monopoly(150, "Gelb");
	monopolies[3] = new Monopoly(200, "Blau");
	monopolies[4] = new Monopoly(0,"Bahnhof");
	monopolies[5] = new Monopoly(0, "Versorgungswerk");


	//Fuellen des Spielbretts
	NoAction* Go = new NoAction(200, "Go");
	vBoard.push_back(Go);
	Field* sBad = new Street("Badstrasse", 60, monopolies[0], 2, 10, 30, 90, 160, 250);
	vBoard.push_back(sBad);
	Field* aGem1 = new ActionField("Gemeinschaftsfeld");
	vBoard.push_back(aGem1);
	Field* sTurm = new Street("Turmstrasse", 60, monopolies[0], 4, 20, 60, 180, 320, 450);
	vBoard.push_back(sTurm);
	Field* tTax1 = new Tax(200, "Einkommensteuer");
	vBoard.push_back(tTax1);
	Field* rBahn1 = new Railroad("Suedbahnhof", monopolies[4]);
	vBoard.push_back(rBahn1);
	Field* gef1 = new ActionField("Gefaengnis");
	vBoard.push_back(gef1);
	Field* sMuen = new Street("Muenchenerstrasse", 180, monopolies[1], 14, 70, 200, 550, 750, 950);
	vBoard.push_back(sMuen);
	Field* aGem2 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem2);
	Field* sWien = new Street("Wiener Strasse", 180, monopolies[1], 14, 70, 200, 550, 750, 950);
	vBoard.push_back(sWien);
	Field* sBerlin = new Street("Berliner Strasse", 200, monopolies[1], 16, 80, 220, 600, 800, 1000);
	vBoard.push_back(sBerlin);
	Field* rBahn2 = new Railroad("Westbahnhof", monopolies[4]);
	vBoard.push_back(rBahn2);
	Field* uElek = new Utility("Elektrizitaetswerk", monopolies[5]);
	vBoard.push_back(uElek);
	Field* naNoPark = new NoAction(0, "Frei Parken");
	vBoard.push_back(naNoPark);
	Field* aGem3 = new ActionField("Gemeinschaftsfeld");
	vBoard.push_back(aGem3);
	Field* sLess = new Street("Lessingstrasse", 260, monopolies[2], 22, 110, 330, 800, 975, 1150);
	vBoard.push_back(sLess);
	Field* sSchi = new Street("Schillerstrasse", 260, monopolies[2], 22, 110, 330, 800, 975, 1150);
	vBoard.push_back(sSchi);
	Field* uWass = new Utility("Wasserwerk", monopolies[5]);
	vBoard.push_back(uWass);
	Field* sGoet = new Street("Goethestrasse", 280, monopolies[2], 24, 120, 360, 850, 1025, 1200);
	vBoard.push_back(sGoet);
	Field* rBahn3 = new Railroad("Nordbahnhof", monopolies[4]);
	vBoard.push_back(rBahn3);
	Field* gGTJ = new GoToJail("Gehe ins Gefaengnis", gef1);
	vBoard.push_back(gGTJ);
	Field* sPark = new Street("Parkstrasse", 350, monopolies[3], 35, 175, 500, 1100, 1300, 1500);
	vBoard.push_back(sPark);
	Field* aGem4 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem4);
	Field* sSchl = new Street("Schlossallee", 400, monopolies[3], 50, 200, 600, 1400, 1700, 2000);
	vBoard.push_back(sSchl);
	Field* tTax2 = new Tax(100,"Zusatzsteuer");
	vBoard.push_back(tTax2);
	Field* rBahn4 = new Railroad("Haupbahnhof", monopolies[4]);
	vBoard.push_back(rBahn4);

	//Verknuepfung der Felder
	createPlayboard(vBoard);

	//Mitspieler bestimmen
	choosePlayers();
}


Board::~Board() 
{
	//Spielbrett freigeben
	for (unsigned int i = vBoard.size() - 1; i > 0; i--)
	{
		vBoard.at(i)->setNext(NULL);
		vBoard.at(i)->setNext(NULL);
		delete(vBoard.at(i));
	}

	//Monopole freigeben
	for (int i = 5; i > 0; i--)
	{
		delete(monopolies[i]);
	}

	//Spieler freigeben
	for (unsigned int i = vPlayer.size() - 1; i > 0; i--)
	{
		delete(vPlayer.at(i));
	}
}



void Board::createPlayboard(std::vector<Field*> vField)
{
	for (unsigned int i = 0; i < vField.size(); i++)
	{
		//Verknuepfung unter den Feldern herstellen
		if (i < vField.size() - 2)
		{
			vField.at(i)->setNext(vField.at(i + 1));
			vField.at(i + 1)->setPrev(vField.at(i));
		}
		//Letztes und erstes Feld miteinander verknuepfen
		else if (i == vField.size() - 1)
		{
			vField.at(vField.size() - 1)->setNext(vField.at(0));
			vField.at(0)->setPrev(vField.at(vField.size() - 1));
		}
	}
}


void Board::choosePlayers()
{
	std::cout << std::endl << std::endl;
	int playerCount;

	std::cout << "Bitte waehle eine Anzahl an Spielern aus (1-4): ";
	std::cin >> playerCount;

	//Fehlerhafte Eingabe abfangen
	while (std::cin.fail() || playerCount > 4 || playerCount < 1)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Fehlerhafte eingabe! " << std::endl;
		std::cout << "Bitte waehle eine Anzahl an Spielern aus (1-4): ";
		std::cin >> playerCount;
	}

	//Gefragte Anzahl an Spielern erzeugen
	for (int i = 1; i <= playerCount; i++)
	{
		std::cout << "Geben Sie den Namen des " << i << ". Spielers an: ";
		std::string sName;
		std::cin >> sName;

		vPlayer.push_back(new Player(vBoard.at(0), sName));
	}
}