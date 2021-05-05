#pragma once
#include "Field.h"
class Tax : public Field
{
private:
	int amount;

public:
	Tax(int _amount, std::string _name, Field* _next, Field* _prev);
	~Tax();

	//void enter(Player& player, int fields_to_go);
};

