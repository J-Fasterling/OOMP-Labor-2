#include "Field.h"
#include <string>

#pragma once
class Player
{
private:
	int money;
	Field* field;
	std::string name;

public:
	Player();
	~Player();
};

