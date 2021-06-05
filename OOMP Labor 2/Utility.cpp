#include "Utility.h"

Utility::Utility(std::string _name, Monopoly* _monopoly)
	: Property(_name, 150, _monopoly), dice_factor_single{ 4 },
	dice_factor_monopoly {10} {
	std::cout << "Feldname " << _name << std::endl; 
}

Utility::~Utility() {}


int Utility::get_rent()
{	
	//ueberpruefen, ob Spieler Monopol besitzt
	if (this->get_Monopoly()->has_all(*this->get_Owner()))
	{
		//Wuerfelzahl mit Monopolfaktor multiplizieren
		return dice_factor_monopoly * (board->get_Dice());
	}
	else
	{
		//Wuerfelzahl mit normalem Faktor multiplizieren
		return dice_factor_single * (board->get_Dice());
	}
}

