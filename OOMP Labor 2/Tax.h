#pragma once
#include "Field.h"
class Tax : public Field
{
private:
	//Hoehe des Steuersatz
	int amount;

public:
	Tax(int _amount, std::string _name = "Neues Feld");
	~Tax();
	//Ereignis wenn man das Feld betritt
	void enter(Player& player);
	//Gibt das zugehoeriege Monopol aus
	Monopoly* get_Monopoly();
};

