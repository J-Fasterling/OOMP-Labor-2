#pragma once
#include "Field.h"
class Tax : public Field
{
private:
	int amount;

public:
	Tax();
	~Tax();

	void enter(Player& player, int fields_to_go);
};

