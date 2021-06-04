#include <iostream>
#include <vector> 
#include "Board.h"



/*######################################################################################
#                                                                                      #
#                      OOMP Labor 2 - MONOPOLY - (Gruppe 3)                            #
#                                                                                      #
#______________________________________________________________________________________#
#                                                                                      #
#   Jeremias Diekamp              Jonas Fasterling                     Marius Grubel   #
#                                     70468878                                         #
#                                                                                      #
######################################################################################*/


int main()
{
	vector<string> names;

	cout << "=====================================================";
	cout << endl << endl;
	cout << "                 SPIELERAUSWAHL" << endl;
	cout << "                ----------------" << endl << endl;
	int playerCount;

	cout << "Bitte waehle eine Anzahl an Spielern aus (2-4): ";
	cin >> playerCount;

	//Fehlerhafte Eingabe abfangen
	while (std::cin.fail() || playerCount > 4 || playerCount < 2)
	{
		cin.clear();
		cin.ignore();
		cout << "Fehlerhafte eingabe! " << endl;
		cout << "Bitte waehle eine Anzahl an Spielern aus (2-4): ";
		cin >> playerCount;


	}

	for (int i = 1; i <= playerCount; i++)
	{
		cout << endl << "Geben Sie den Namen des " << i << ". Spielers an: ";
		string sName;
		cin >> sName;

		names.push_back(sName);
	}

	//Auswahl des Spielmodus freies Spiel oder Testversion
	char cPlaymode;
	cout << endl << "Moechtest du automatisch oder manuell wuerfeln (a/m)? ";
	cin >> cPlaymode;

	//Fehlerhafte Eingabe
	while (std::cin.fail() || cPlaymode != 'a' && cPlaymode != 'm')
	{
		cin.clear();
		cin.ignore();
		cout << "Fehlerhafte eingabe! " << endl;
		cout << "Moechtest du automatisch oder manuell wuerfeln (a/m)? ";
		cin >> cPlaymode;
	}

	cout << endl << endl;

    Board* bBoard = new Board(playerCount, names, cPlaymode);
    delete bBoard;
}
