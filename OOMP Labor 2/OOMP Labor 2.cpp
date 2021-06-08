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
#       70467565                      70468878                            70470990     #
#                                                                                      #
######################################################################################*/


void checkPlayerInput(int& playerCount)
{
	cout << "Bitte waehle eine Anzahl an Spielern aus (2-4): ";
	cin >> playerCount;

	if (std::cin.fail() || playerCount > 4 || playerCount < 2)
	{
		cin.clear();
		cin.ignore();
		throw invalid_argument("Fehlerhafte Eingabe!");
	}
}

void checkModeInput(char& cPlayMode)
{
	cout << "Moechtest du automatisch oder manuell wuerfeln (a/m)? ";
	cin >> cPlayMode;

	if (std::cin.fail() || cPlayMode != 'a' && cPlayMode != 'm')
	{
		cin.clear();
		cin.ignore();
		throw invalid_argument("Fehlerhafte Eingabe!");
	}
}


int main()
{
	vector<string> names;
	bool correctInput = true;

	cout << "=====================================================";
	cout << endl << endl;
	cout << "                 SPIELERAUSWAHL" << endl;
	cout << "                ----------------" << endl << endl;
	int playerCount;

	do
	{
		try
		{
			checkPlayerInput(playerCount);
			correctInput = true;
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
			correctInput = false;
		}
	} 	while (!correctInput);


	for (int i = 1; i <= playerCount; i++)
	{
		cout << endl << "Geben Sie den Namen des " << i << ". Spielers an: ";
		string sName;
		cin >> sName;

		names.push_back(sName);
	}

	cout << endl;

	//Auswahl des Spielmodus freies Spiel oder Testversion
	char cPlaymode;

	//Fehlerhafte Eingabe
	do
	{
		try
		{
			checkModeInput(cPlaymode);
			correctInput = true;
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
			correctInput = false;
		}
	} while (!correctInput);

	cout << endl << endl;

    Board* bBoard = new Board(playerCount, names, cPlaymode);
    delete bBoard;
}
