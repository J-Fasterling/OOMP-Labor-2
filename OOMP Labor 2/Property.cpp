#include "Property.h"

Property::Property(std::string _name, int _value, Monopoly* _monopoly, Player* _owner) 
	: Field(_name), value{ _value }, monopoly{ _monopoly }, owner{ _owner } {}

Property::~Property() {}

int Property::get_Rent()
{
	return 0;
}

void Property::enter(Player& player) 
{
	Field::enter(player);

	if (owner)
	{
		player.setMoney(player.getMoney() - get_Rent());
		owner->setMoney(owner->getMoney() + get_Rent());
		std::cout << player.get_Name() << " bezahlt " << get_Rent() << "$ miete an " << owner->get_Name() << std::endl;
	}
	else
	{
		if (player.want_to_buy(*this))
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
