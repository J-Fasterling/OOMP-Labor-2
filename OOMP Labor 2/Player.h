#pragma once

//#include "Field.h"
#include <stdio.h>
#include <string>

class Field;
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
