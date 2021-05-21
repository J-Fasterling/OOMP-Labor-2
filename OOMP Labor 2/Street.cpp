#include "Street.h"

Street::Street(std::string _name, int _value, Monopoly* _monopoly, int price_for_house,
	int m1, int m2, int m3, int m4, int m5, int m6)
	: Property(_name, _value, _monopoly), houses {0}
{
	rent[0] = m1;
	rent[1] = m2;
	rent[2] = m3;
	rent[3] = m4;
	rent[4] = m5;
	rent[5] = m6;
	std::cout << "Feldname " << _name << std::endl;
}

Street::~Street() {}


int Street::get_rent() 
{
	//ueberpruefen, ob Spieler das Monopol und Haeuser hat
	if (this->get_Monopoly()->has_all(*this->get_Owner()) && houses == 0)
	{
		//Grundmiete multipliziert mit zwei zurueckgeben
		return rent[0] * 2;
	}
	else
	{
		//Haeuser spezifische Miete zurueckgeben 
		return rent[houses];
	}
}

int Street::possible_to_build_houses(int iHouses)
{
	if (iHouses < 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Street::set_House(Field* fField, int iHouses)
{
	houses = iHouses + 1;
}

int Street::get_House()
{
	return houses;
}