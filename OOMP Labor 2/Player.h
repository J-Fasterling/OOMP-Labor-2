#include "Field.h"
#include <stdio.h>

#pragma once
class Player
{
private:
	int money;
	Field* field;
	std::string name;

public:
	Player();
	Player(int iMoney, Field* fField, std::string sName);
	~Player();
};
