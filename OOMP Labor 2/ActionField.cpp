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
		if (action_cnt == 10)
		{
			action_cnt = 0;
		}

		player.set_Money(player.get_Money() + chooseActioncard <double>(board->get_Index_Action().at(action_cnt), player));
		action_cnt++;
	}
	else
	{
		if (community_cnt == 10)
		{
			community_cnt = 0;
		}

		player.set_Money(player.get_Money() + chooseCommunitycard <double>(board->get_Index_Community().at(community_cnt), player));
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
			std::cout << "Du hast Geburtstag! Du bekommst 200$" << std::endl;
			return 200;
			break;
		case 2:
			std::cout << "Du wurdest bestohlen! Du verlierst 100$" << std::endl;
			return -100;
			break;
		case 3:
			std::cout << "Heute ist ein schoener Tag. Ruhe dich etwas aus." << std::endl << "Es passiert nichts." << std::endl;
			return 0;
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
			std::cout << "Du bist zum Vorstand gewaehlt worden." << std::endl << "Zahle jedem Spieler 50$." << std::endl;

			for (unsigned int i = 0; i <= (board->get_Player().size() - 1); i++)
			{
				board->get_Player().at(i)->set_Money(board->get_Player().at(i)->get_Money() + 50);
				amount_to_pay += 50;
			}
			return amount_to_pay;
			break;
		case 7:
			std::cout << "Die Bank zahlt dir eine Dividende: 500$" << std::endl;
			return 500;
			break;
		case 8:
			std::cout << "Ruecke vor bis zur Schlossallee." << std::endl;
			player.set_Field(board->get_Playboard().at(40));
			player.get_Field()->enter(player);
			return 0;
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
					money_on_GO = 400;
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
			std::cout << "Rücke vor bis zum Times Square." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein.";

			while (player.get_Field()->get_Name() != "Times Square")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 400;
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
				T ActionField::chooseCommunitycard(card, player);
				return 0;
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
			return 0;
			break;
		case 16:
			std::cout << "Rücke vor bis zur HeinrichNordhoff Strasse." << std::endl << "Wenn du ueber LOS kommst ziehe 400$ ein.";

			while (player.get_Field()->get_Name() != "HeinrichNordhoff Strasse")
			{
				player.set_Field(player.get_Field()->get_Next());

				if (player.get_Field()->get_Name() == "Go")
				{
					money_on_GO = 400;
				}
			}
			player.get_Field()->enter(player);
			return money_on_GO;
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
	if (player.get_Field()->get_Name() != "Gefaengnis")
	{
		switch (card)
		{
		case 1:

			return 0;
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