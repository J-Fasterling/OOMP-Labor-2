#include "ActionField.h"
#include "Board.h"

ActionField::ActionField(std::string _name) : Field(_name) {

	std::cout << "Feldname: " << _name << std::endl;
}

ActionField::~ActionField() {}


void ActionField::enter(Player& player)
{
	Field::enter(player);

	int action = (rand() % ((3 + 1) - 1)) + 1;
	player.set_Money(player.get_Money() +  chooseAction <double> (action, player));
}

template<class T>
T ActionField::chooseAction(int card, Player& player)
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
			player.set_Money(player.get_Money() - 100);
			break;
		case 3:
			std::cout << "Heute ist ein schoener Tag. Ruhe dich etwas aus." << std::endl << "Es passiert nichts." << std::endl;
			break;
		case 4:
			std::cout << "Ab mit dir ins Gefängnis!";
			player.is_inmate();
			player.set_Field(Field::board->get_Playboard().at(10));
			player.get_Field()->enter(player);
			break;
		}
	}
}

Monopoly* ActionField::get_Monopoly() 
{
	return NULL;
}