#pragma once
#include "Field.h"
class Tax : public Field
{
private:
	int amount;

public:
	Tax(int _amount, std::string _name = "Neues Feld");
	~Tax();
	void enter(Player& player);

};

