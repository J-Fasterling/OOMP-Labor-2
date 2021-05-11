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
		player.setMoney(player.getMoney() - get_rent());
		owner->setMoney(owner->getMoney() + get_rent());
		std::cout << player.get_Name() << " bezahlt " << get_rent() << "$ Miete an " << owner->get_Name() << std::endl;
		std::cout << owner->get_Name() << " hat jetzt " << owner->getMoney() << " $." << std::endl;
	}
	else
	{
		if (player.want_to_buy(*this, player))
		{
			if (player.getMoney() >= value)
			{
				player.setMoney(player.getMoney() - value);
				owner = &player;

				std::cout << player.get_Name() << " ist nun Inhaber von " << this->getName() << std::endl;
				int test = player.getField()->getMonopoly()->count_owned_properties(player);
				std::cout << "Monopole: " << test << std::endl;
			}
			else 
			{
				std::cout << "Du kannst dir " << this->getName() << " nicht leisten." << std::endl;
			}
		}
	}
}


Monopoly* Property::getMonopoly() 
{

	return monopoly;
}

Player* Property::getOwner()
{
	return owner;
}
