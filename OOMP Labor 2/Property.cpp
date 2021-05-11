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

			player.setMoney(player.get_Money() - get_rent());
			owner->setMoney(owner->get_Money() + get_rent());
			std::cout << player.get_Name() << " bezahlt ";
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << get_rent() << "$ ";
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "Miete an " << owner->get_Name() << std::endl;
			std::cout << owner->get_Name() << " bekommt ";
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << get_rent() << "$ ";
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "an Miete von " << player.get_Name() << std::endl;
			std::cout << owner->get_Name() << " hat jetzt " << owner->get_Money() << " $."<< std::endl;
		}
		else{
		}
	}
	else
	{
		if (player.want_to_buy(this, &player))
		{
			if (player.get_Money() >= value)
			{
				player.setMoney(player.get_Money() - value);
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
