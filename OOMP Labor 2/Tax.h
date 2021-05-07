#pragma once
#include "Field.h"
class Tax : public Field
{
private:
	int amount;

public:
	Tax(int _amount, std::string _name = "Neues Feld", Field* _next = NULL, Field* _prev = NULL);
	//~Tax();

	//void enter(Player& player, int fields_to_go);
};

