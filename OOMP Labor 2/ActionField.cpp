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
			std::cout << "Ab mit dir ins Gefaengnis!" << std::endl;
			player.is_inmate();
			player.set_Field(Field::board->get_Playboard().at(10));
			player.get_Field()->enter(player);
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