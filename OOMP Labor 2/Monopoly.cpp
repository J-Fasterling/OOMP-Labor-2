#include "Monopoly.h"
#include "Property.h"

Monopoly::Monopoly(int _price_for_house, std::string _name, std::vector <Field*> _properties)
	: price_for_house{ _price_for_house }, vProperties {_properties}, name{ _name } {}

Monopoly::~Monopoly() {}


void Monopoly::set_Properties(Field* property) 
{

	vProperties.push_back(property);
}


std::string Monopoly::get_name()
{
	return name;
}


int Monopoly::count_owned_properties(Player& player)
{
	int iCnt = 0;

	//Alle Grundstuecke des Monopols durchgehen und auf Owner ueberpruefen
	for (unsigned int i = 0; i < vProperties.size(); i++)
	{
		if (vProperties.at(i)->get_Owner() == &player)
		{
			iCnt++;
		}
	}
	return iCnt;
}


bool Monopoly::has_all(Player& player)
{
	//Ueberpruefung ob gezaehlten Grundstuecke des Spielers alle vorhandenen sind
	if (count_owned_properties(player) == vProperties.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Monopoly::get_PriceforHouse()
{
	return price_for_house;
}
