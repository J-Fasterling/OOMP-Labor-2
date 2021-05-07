#pragma once

#include "Field.h"
#include <stdio.h>

class Player
{
private:
	int money;
	Field* field;
	std::string name;

public:
	Player(Field* fField, std::string sName);
	~Player();
};
