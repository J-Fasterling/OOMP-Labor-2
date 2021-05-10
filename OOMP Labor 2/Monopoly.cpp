#include "Monopoly.h"
#include "Property.h"

Monopoly::Monopoly(int _price_for_house, std::string _name, std::vector <Field*> _properties)
	: price_for_house{ _price_for_house }, vProperties {_properties}, name{ _name } {}

Monopoly::Monopoly() {}

Monopoly::~Monopoly() {}

void Monopoly::setProperties(Field* property) 
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

	for (int i = 0; i < vProperties.size(); i++)
	{
		if (vProperties.at(i)->getOwner() == &player)
		{
			std::string test = vProperties.at(i)->getOwner()->get_Name();
			iCnt++;
		}
	}
	return iCnt;
}

bool Monopoly::has_all(Player& player)
{
	return true;
}

