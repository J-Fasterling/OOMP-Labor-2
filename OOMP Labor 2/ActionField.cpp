#include <random>
#include "ActionField.h"
#include "Board.h"

ActionField::ActionField(Board* _board, std::string _name) : Field(_name, _board) {

	std::cout << "Feldname: " << _name << std::endl;
}

ActionField::~ActionField() {}


void ActionField::enter(Player& player)
{
	Field::enter(player);

	if (player.get_Field()->get_Name() == "Ereignisfeld")
	{
		if (action_cnt == 15)
		{
			action_cnt = 0;
		}

		double moneyToGet = chooseActioncard <double>(board->get_Index_Action().at(action_cnt), player);

		if (board->get_Index_Action().at(action_cnt) == 14 && moneyToGet != -200)
		{
			community_cnt++;
		}

		player.set_Money(player.get_Money() + moneyToGet);
		action_cnt++;
	}
	else
	{
		if (community_cnt == 15)
		{
			community_cnt = 0;
		}

		double moneyToGet = chooseCommunitycard <double>(board->get_Index_Community().at(community_cnt), player);
		player.set_Money(player.get_Money() + moneyToGet);
		community_cnt++;
	}
}


template<class T>
T ActionField::chooseActioncard(int card, Player& player)
{
	int money_on_GO{ 0 };
	int amount_to_pay{ 0 };

	if (player.get_Field()->get_Name() != "Gefaengnis")
	{
		switch (card)
		{
		case 1:
			std::cout << "Rücke vor bis zur HeinrichNordhoff Strasse." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein.";

			while (player.get_Field()->get_Name() != "HeinrichNordhoff Strasse")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 200;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
			break;

		case 2:
			std::cout << "Du wurdest bestohlen! Du verlierst 100$" << std::endl;
			return -100;
			break;

		case 3:
			std::cout << "Ruecke vor bis zum naechsten Bahnhof." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein." << std::endl;

			while (player.get_Field()->get_Name() != "Nordbahnhof"  && player.get_Field()->get_Name() != "Westbahnhof" && player.get_Field()->get_Name() != "Hauptbahnhof" && player.get_Field()->get_Name() != "Suedbahnhof")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 200;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
			break;

		case 4:
			std::cout << "Gehe in das Gefaengnis!" << std::endl << "Begib dich direkt dorthin." << std::endl << "Ziehe keine 400$ ein." << std::endl;
			player.is_inmate();
			player.set_Field(Field::board->get_Playboard().at(10));
			player.get_Field()->enter(player);
			return 0;
			break;

		case 5:
			std::cout << "Gehe 3 Felder zurueck." << std::endl;
			for (int i = 0; i < 3; i++)
			{
				player.set_Field(player.get_Field()->get_Prev());
			}
			player.get_Field()->enter(player);
			return 0;
			break;

		case 6:
			std::cout << "Du bist zum Vorstand gewaehlt worden." << std::endl << "Zahle jedem Spieler 20$." << std::endl;

			for (unsigned int i = 0; i <= (board->get_Player().size() - 1); i++)
			{
				board->get_Player().at(i)->set_Money(board->get_Player().at(i)->get_Money() + 20);
			}
			amount_to_pay = (board->get_Player().size()) * -20;
			return amount_to_pay;
			break;

		case 7:
			std::cout << "Die Bank zahlt dir eine Dividende: 500$" << std::endl;
			return 500;
			break;

		case 8:
			std::cout << "Ruecke vor bis zur Schlossallee." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein." << std:endl;

			while (player.get_Field()->get_Name() != "Schlossallee")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 200;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
			break;

		case 9:
			std::cout << "Strafe fuer zu schnelles Fahren: 300$" << std::endl;
			return -300;
			break;

		case 10:
			std::cout << "Gehe zurueck zur Badstrasse." << std::endl;
			player.set_Field(board->get_Playboard().at(1));
			player.get_Field()->enter(player);
			return 0;
			break;

		case 11:
			std::cout << "Mache einen Ausflug zum Suedbahnhof." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein.";
			
			while (player.get_Field()->get_Name() != "Suedbahnhof")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 200;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
			break;

		case 12:
			std::cout << "Miete- und Anleihezinsen werden faellig. Die Bank zahlt dir 300$." << std::endl;
			return 300;
			break;

		case 13:
			std::cout << "Ruecke vor bis zum Times Square." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein.";

			while (player.get_Field()->get_Name() != "Times Square")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 200;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
			break;

		case 14:
			std::cout << "Zahle eine Strafe von 200$ oder nimm eine Gemeinschaftskarte." << std::endl;

			//Eingabechar
			char eingabe;
			std::cout << player.get_Name() << " hat noch " << player.get_Money() << " $." << std::endl;
			std::cout << "Moechtest du eine Gemeinschaftskarte ziehen? (j/n): ";
			std::cin >> eingabe;

			//Fehlerhafte Eingabe !(j/n) abfangen
			while (std::cin.fail() || (eingabe != 'j' && eingabe != 'n'))
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Fehlerhafte eingabe! " << std::endl;
				std::cout << "Moechtest du eine Gemeinschaftskarte ziehen?  (j/n): ";
				std::cin >> eingabe;
			}

			if (eingabe == 'j')
			{
				return chooseCommunitycard <double> (board->get_Index_Community().at(community_cnt), player);
				break;
			}
			else
			{
				return -200;
				break;
			}

		case 15:
			std::cout << "Ruecke vor bis auf LOS." << std::endl;
			player.set_Field(board->get_Playboard().at(0));
			player.get_Field()->enter(player);
			return 200;
			break;			

		default:
			return 0;
			break;
		}
	}
	else
	{
		return 0;
	}
}


template<class T>
T ActionField::chooseCommunitycard(int card, Player& player)
{
	int amount_to_get{ 0 };

	if (player.get_Field()->get_Name() != "Gefaengnis")
	{
		switch (card)
		{
		case 1:
			std::cout << "Bank-Irrtum zu deinen Gunsten." << std::endl << "Ziehe 400$ ein." << std::endl;
			return 400;
			break;
		case 2:
			std::cout << "Aus Lagerverkaeufen erhaelst du: 500$" << std::endl;
			return 500;
			break;
		case 3:
			std::cout << "Dein Auto muss in die Werkstatt. Zahle 100$." << std::endl;
			return -100;
			break;
		case 4:
			std::cout << "Arzt-Kosten. Zahle 100$." << std::endl;
			return -100;
			break;
		case 5:
			std::cout << "Zahle Schulgeld: 150$" << std::endl;
			return -150;
			break;
		case 6:
			std::cout << "Gehe in das Gefaengnis!" << std::endl << "Begib dich direkt dorthin." << std::endl << "Ziehe keine 400$ ein." << std::endl;
			player.is_inmate();
			player.set_Field(Field::board->get_Playboard().at(10));
			player.get_Field()->enter(player);
			return 0;
			break;
		case 7:
			std::cout << "Ruecke vor bis auf LOS." << std::endl;
			player.set_Field(board->get_Playboard().at(0));
			player.get_Field()->enter(player);
			return 200;
			break;
		case 8:
			std::cout << "Du erbst 500$." << std::endl;
			return 500;
			break;
		case 9:
			std::cout << "Du hast einem Kreuzwortraetsel-Wettbewerb gewonnen." << std::endl << "Ziehe 200$ ein." << std::endl;
			return 200;
			break;
		case 10:
			std::cout << "Du erhaelst den Corona-Bonus vom Staat: 350$." << std::endl;
			return 350;
			break;
		case 11:
			std::cout << "Du erhaelst auf Vorzugs-Aktion 7 Prozent Dividende: 600$" << std::endl;
			return 600;
			break;
		case 12:
			std::cout << "Es ist dein Geburtstag." << std::endl << "Ziehe von jedem Spieler 50$ ein" << std::endl;

			for (unsigned int i = 0; i <= (board->get_Player().size() - 1); i++)
			{
				board->get_Player().at(i)->set_Money(board->get_Player().at(i)->get_Money() - 50);
			}
			amount_to_get = (board->get_Player().size()) * 50;
			return amount_to_get;
			break;
		case 13:
			std::cout << "Du hast den 2.Preis in einem Schoenheitswettbewerb gewonnen." << std::endl << "Ziehe 200$ ein." << std::endl;
			return 200;
			break;
		case 14:
			std::cout << "Einkommenssteuer-Rueckzahlung: 500$" << std::endl;
			return 500;
			break;
		case 15:
			std::cout << "Zahle an das Krankenhaus: 150" << std::endl;
			return -150;
			break;

		default:
			return 0;
			break;
		}
	}
	else
	{
		return 0;
	}
}


Monopoly* ActionField::get_Monopoly() 
{
	return NULL;
}