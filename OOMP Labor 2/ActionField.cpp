#include "ActionField.h"

ActionField::ActionField(std::string _name) : Field(_name) {

	std::cout << "Feldname: " << _name << std::endl;
}

ActionField::~ActionField() {}


void ActionField::enter(Player& player)
{
	Field::enter(player);

	if(player.get_Field()->get_Name() != "Gefaengnis")
	{ 

		int action = (rand() % ((3 + 1) - 1)) + 1;

		switch (action)
		{
			case 1:
				std::cout << "Du hast Geburtstag! Du bekommst 200$" << std::endl;
				player.set_Money(player.get_Money() + 200);
				break;
			case 2:
				std::cout << "Du wurdest bestohlen! Du verlierst 100$" << std::endl;
				player.set_Money(player.get_Money() - 100);
				break;
			case 3:
				std::cout << "Heute ist ein schoener Tag. Ruhe dich etwas aus."<< std::endl << "Es passiert nichts." << std::endl;
				break;
		}
	}
	
}


Monopoly* ActionField::get_Monopoly() 
{
	return NULL;
}