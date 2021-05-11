#include "Property.h"

Property::Property(std::string _name, int _value, Monopoly* _monopoly, Player* _owner) 
	: Field(_name), value{ _value }, monopoly{ _monopoly }, owner{ _owner } {}

Property::~Property() {}

int Property::get_rent()
{
	return 0;
}

void Property::enter(Player& player) 
{
	Field::enter(player);

	if (owner)
	{
		if (&player != owner)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			int rent = get_rent();
			//Abziehen und zuschreiben der Miete vom Mieter an der Vermieter
			player.set_Money(player.get_Money() - rent);
			owner->set_Money(owner->get_Money() + rent);

			std::cout << player.get_Name() << " bezahlt ";
			//Konsolentextfarbe auf rot setzen
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << rent << "$ ";
			//Konsolentextfarbe zuruecksetzen
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "Miete an " << owner->get_Name() << std::endl;
			std::cout << owner->get_Name() << " bekommt ";
			//Konsolentextfarbe auf gruen setzen
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << rent << "$ ";
			//Konsolentextfarbe zuruecksetzen
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "an Miete von " << player.get_Name() << std::endl;
			std::cout << owner->get_Name() << " hat jetzt " << owner->get_Money() << " $."<< std::endl;
		}
		else
		{
			//Wenn Feld einen Besitzer habt, pruefen, ob dieser ein Haus kaufen kann und will
			/*if (this->getMonopoly()->has_all(*this->getOwner())) 
			{
				if (player.want_to_buy_Houses(*this, player, _price_for_house))
				{
					if (player.getMoney() >= _price_for_house )
					{
						build_houses();
						player.getMoney() - _price_for_house;
						std::cout << player.get_Name() << " hat jetzt noch " << player.getMoney() << " $." << std::endl;
					}
					else{}
				}
				else{}
			}
			else {}*/
		}
	}
	else
	{
		if (player.want_to_buy_Property(*this, player))
		{
			if (player.get_Money() >= value)
			{
				player.set_Money(player.get_Money() - value);
				owner = &player;

				std::cout << player.get_Name() << " ist nun Inhaber von " << this->get_Name() << std::endl;
				int test = player.get_Field()->get_Monopoly()->count_owned_properties(player);
				std::cout << "Monopole: " << test << std::endl;
			}
			else 
			{
				std::cout << "Du kannst dir " << this->get_Name() << " nicht leisten." << std::endl;
			}
		}
	}
}


Monopoly* Property::get_Monopoly() 
{

	return monopoly;
}


Player* Property::get_Owner()
{
	return owner;
}


int Property::get_Value()
{
	return value;
}


int Property::build_houses()
{
	return 0;
}