#include <random>
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
	cout << "           MONOPOLY              " << endl;
	cout << "---------------------------------" << endl << endl;

	//Erstellen der Monopole
	monopolies[0] = new Monopoly(50, "Braun");
	monopolies[1] = new Monopoly(50, "Hellblau");
	monopolies[2] = new Monopoly(100, "Pink");
	monopolies[3] = new Monopoly(100, "Orange");
	monopolies[4] = new Monopoly(150, "Rot");
	monopolies[5] = new Monopoly(150, "Gelb");
	monopolies[6] = new Monopoly(200, "Gruen");
	monopolies[7] = new Monopoly(200, "Blau");
	monopolies[8] = new Monopoly(0, "Bahnhof");
	monopolies[9] = new Monopoly(0, "Versorgungswerk");


	//Fuellen des Spielbretts
	Field* Go = new NoAction(200, "Go");
	vBoard.push_back(Go);
	Field* sBad = new Street("Badstrasse", 60, monopolies[0], 2, 10, 30, 90, 160, 250);
	vBoard.push_back(sBad);
	Field* aGem1 = new ActionField("Gemeinschaftsfeld");
	vBoard.push_back(aGem1);
	Field* sTurm = new Street("Turmstrasse", 60, monopolies[0], 4, 20, 60, 180, 320, 450);
	vBoard.push_back(sTurm);
	Field* tTax1 = new Tax(200, "Einkommensteuer");
	vBoard.push_back(tTax1);
	Field* rBahn1 = new Railroad("Suedbahnhof", monopolies[8]);
	vBoard.push_back(rBahn1);
	Field* sRing = new Street("Bohlweg", 100, monopolies[1], 6, 30, 90, 270, 400, 550);
	vBoard.push_back(sRing);
	Field* aGem2 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem2);
	Field* sCel = new Street("Celler Strasse", 100, monopolies[1], 6, 30, 90, 270, 400, 550);
	vBoard.push_back(sCel);
	Field* sHanse = new Street("Hansestrasse", 120, monopolies[1], 8, 40, 100, 400, 450, 600);
	vBoard.push_back(sHanse);
	Field* gef1 = new ActionField("Gefaengnis");
	vBoard.push_back(gef1);
	Field* sHein = new Street("HeinrichNordhoff Strasse", 140, monopolies[2], 10, 50, 150, 450, 625, 750);
	vBoard.push_back(sHein);
	Field* uElek = new Utility("Elektrizitaetswerk", monopolies[9]);
	vBoard.push_back(uElek);
	Field* sFried = new Street("Friedrich Ebert Strasse", 140, monopolies[2], 10, 50, 150, 450, 625, 750);
	vBoard.push_back(sFried);
	Field* sPorsch = new Street("Porsche Strasse", 160, monopolies[2], 12, 60, 180, 500, 700, 900);
	vBoard.push_back(sPorsch);
	Field* rBahn2 = new Railroad("Westbahnhof", monopolies[8]);
	vBoard.push_back(rBahn2);
	Field* sMuen = new Street("Muenchenerstrasse", 180, monopolies[3], 14, 70, 200, 550, 750, 950);
	vBoard.push_back(sMuen);
	Field* aGem3 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem3);
	Field* sWien = new Street("Wiener Strasse", 180, monopolies[3], 14, 70, 200, 550, 750, 950);
	vBoard.push_back(sWien);
	Field* sBerlin = new Street("Berliner Strasse", 200, monopolies[3], 16, 80, 220, 600, 800, 1000);
	vBoard.push_back(sBerlin);
	Field* naNoPark = new NoAction(0, "Frei Parken");
	vBoard.push_back(naNoPark);
	Field* sFifth = new Street("Fifth Avenue", 220, monopolies[4], 18, 90, 250, 700, 875, 1050);
	vBoard.push_back(sFifth);
	Field* aGem4 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem4);
	Field* sBroad = new Street("Broadway", 220, monopolies[4], 18, 90, 250, 700, 875, 1050);
	vBoard.push_back(sBroad);
	Field* sTime = new Street("Times Square", 200, monopolies[4], 20, 100, 300, 750, 925, 1100);
	vBoard.push_back(sTime);
	Field* rBahn3 = new Railroad("Nordbahnhof", monopolies[8]);
	vBoard.push_back(rBahn3);
	Field* sLess = new Street("Lessingstrasse", 260, monopolies[5], 22, 110, 330, 800, 975, 1150);
	vBoard.push_back(sLess);
	Field* sSchi = new Street("Schillerstrasse", 260, monopolies[5], 22, 110, 330, 800, 975, 1150);
	vBoard.push_back(sSchi);
	Field* uWass = new Utility("Wasserwerk", monopolies[9]);
	vBoard.push_back(uWass);
	Field* sGoet = new Street("Goethestrasse", 280, monopolies[5], 24, 120, 360, 850, 1025, 1200);
	vBoard.push_back(sGoet);
	Field* gGTJ = new GoToJail("Gehe ins Gefaengnis", gef1);
	vBoard.push_back(gGTJ);
	Field* sBoule = new Street("Boulevard South", 300, monopolies[6], 26, 130, 390, 900, 1100, 1275);
	vBoard.push_back(sBoule);
	Field* aGem5 = new ActionField("Gemeinschaftsfeld");
	vBoard.push_back(aGem5);
	Field* sHigh = new Street("Highway 1", 300, monopolies[6], 26, 130, 390, 900, 1100, 1275);
	vBoard.push_back(sHigh);
	Field* sRoute = new Street("Route 66", 320, monopolies[6], 28, 150, 450, 1000, 1200, 1400);
	vBoard.push_back(sRoute);
	Field* rBahn4 = new Railroad("Hauptbahnhof", monopolies[8]);
	vBoard.push_back(rBahn4);
	Field* aGem6 = new ActionField("Ereignisfeld");
	vBoard.push_back(aGem6);
	Field* sPark = new Street("Parkstrasse", 350, monopolies[7], 35, 175, 500, 1100, 1300, 1500);
	vBoard.push_back(sPark);
	Field* tTax2 = new Tax(100, "Zusatzsteuer");
	vBoard.push_back(tTax2);
	Field* sSchl = new Street("Schlossallee", 400, monopolies[7], 50, 200, 600, 1400, 1700, 2000);
	vBoard.push_back(sSchl);

	//Verknuepfung der Felder
	createPlayboard();

	//Weist den Monopolen die Objekte zu
	setMonopolies();

	//Mitspieler bestimmen
	choosePlayers();

	//vBoard.at(2)->enter(*vPlayer.at(0));
	gameEngine();
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



void Board::createPlayboard()
{
	for (unsigned int i = 0; i < vBoard.size(); i++)
	{
		//Verknuepfung unter den Feldern herstellen
		if (i < vBoard.size() - 1)
		{
			vBoard.at(i)->setNext(vBoard.at(i + 1));
			vBoard.at(i + 1)->setPrev(vBoard.at(i));
		}
		//Letztes und erstes Feld miteinander verknuepfen
		else if (i == vBoard.size() - 1)
		{
			vBoard.at(vBoard.size() - 1)->setNext(vBoard.at(0));
			vBoard.at(0)->setPrev(vBoard.at(vBoard.size() - 1));
		}
	}
}


void Board::choosePlayers()
{
	cout <<"=====================================================";
	cout << endl << endl;
	cout << "                 SPIELERAUSWAHL" << endl;
	cout << "                ----------------" << endl << endl;
	int playerCount;

	cout << "Bitte waehle eine Anzahl an Spielern aus (1-4): ";
	cin >> playerCount;

	//Fehlerhafte Eingabe abfangen
	while (std::cin.fail() || playerCount > 4 || playerCount < 1)
	{
		cin.clear();
		cin.ignore();
		cout << "Fehlerhafte eingabe! " << endl;
		cout << "Bitte waehle eine Anzahl an Spielern aus (1-4): ";
		cin >> playerCount;
	}

	//Gefragte Anzahl an Spielern erzeugen
	for (int i = 1; i <= playerCount; i++)
	{
		cout << endl << "Geben Sie den Namen des " << i << ". Spielers an: ";
		string sName;
		cin >> sName;

		vPlayer.push_back(new Player(vBoard.at(0), sName));
	}

	cout << "=====================================================" << endl << endl;
}


void Board::gameEngine()
{
	cout << "                 LOS GEHTS!" << endl;
	cout << "                ------------" << endl << endl;
	bool gameBreak = false;
	int cnt = 0;

	//Timer Seed zuruecksetzen
	srand((unsigned int)time(NULL));
	while (1)
	{
		cnt++;
		//Spielzug fuer jeden Spieler
		for (unsigned int i = 0; i <= vPlayer.size() - 1; i++)
		{
			//Spieler bewegt sich auf dem Feld X Schritte vorwaerts
			go_X_Steps(throwDice(), vPlayer.at(i));
			
			cout << vPlayer.at(i)->get_Name() << " hat noch " << vPlayer.at(i)->getMoney() << "$." << endl << endl;

			//vPlayer.at(vPlayer.size() - 1)->setMoney(0);

			//Spiel wird beendet sobald ein Spieler pleite ist
			if (vPlayer.at(i)->getMoney() <= 0) 
			{
				std::cout << vPlayer.at(i)->get_Name() << " ist pleite und hat verloren :(" << endl;
				//Festlegen, dass das Programm beendet werden soll
				gameBreak = true;
				break; 
			}
		}
		cout << cnt << endl;

		//Spiel wird beendet
		if (gameBreak)
		{
			break;
		}
	}
}


int Board::throwDice()
{
	//Zufaellig beide Wuerfel wuerfeln
	//dice[0] = (rand() % ((6 + 1) - 1)) + 1;
	//dice[1] = (rand() % ((6 + 1) - 1)) + 1;

	dice[0] = 1;
	dice[1] = 1;

	return dice[0] + dice[1];
	// return 1;
}


void Board::go_X_Steps(int iDice, Player* player)
{
	bool Pasch = false;

	cout << player->get_Name() << " hat eine " << dice[0] << " und eine " << dice[1] << " gewuerfelt" << endl;

	if (dice[0] == dice[1])
	{
		Pasch = true;
		for (int i = 0; i <= iDice - 1; i++)
		{
			player->setField(player->getField()->getNext());
			if (player->getField()->getName() == "Go")
			{
				player->setMoney(player->getMoney() + 200);
			}
		}
		player->getField()->enter(*player);
		throwDice();
		cout << player->get_Name() << " hat eine " << dice[0] << " und eine " << dice[1] << " gewuerfelt" << endl;


		if (dice[0] == dice[1])
		{
			for (int i = 0; i <= iDice - 1; i++)
			{
				player->setField(player->getField()->getNext());
				if (player->getField()->getName() == "Go")
				{
					player->setMoney(player->getMoney() + 200);
				}
			}
			player->getField()->enter(*player);
			throwDice();
			cout << player->get_Name() << " hat eine " << dice[0] << " und eine " << dice[1] << " gewuerfelt" << endl;


			if (dice[0] == dice[1])
			{
				player->setField(vBoard.at(10));
				player->getField()->enter(*player);
			}
		}
	}


	if (!Pasch)
	{
		//so viele Felder wie gewuerfelt fortbewegen
		for (int i = 0; i <= iDice - 1; i++)
		{
			//Aktuelles Feld auf das nachfolgende setzen
			player->setField(player->getField()->getNext());
			if (player->getField()->getName() == "Go")
			{
				player->setMoney(player->getMoney() + 200);
			}
		}
		//Ausgabe des aktuellen Felds
		player->getField()->enter(*player);
	}

	
}


void Board::setMonopolies() {

	for (unsigned int i = 0; i <= vBoard.size() - 1; i++)
	{
		if (vBoard.at(i)->getMonopoly() != NULL) {
			if (vBoard.at(i)->getMonopoly() == monopolies[0]) {
				monopolies[0]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[1]) {
				monopolies[1]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[2]) {
				monopolies[2]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[3]) {
				monopolies[3]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[4]) {
				monopolies[4]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[5]) {
				monopolies[5]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[6]) {
				monopolies[6]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[7]) {
				monopolies[7]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[8]) {
				monopolies[8]->setProperties(vBoard.at(i));
			}
			else if (vBoard.at(i)->getMonopoly() == monopolies[9]) {
				monopolies[9]->setProperties(vBoard.at(i));
			}			
		}
	}
}