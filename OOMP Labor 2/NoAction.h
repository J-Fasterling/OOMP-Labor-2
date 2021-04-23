#pragma once
#include "Field.h"
class NoAction :
    public Field
{
private:
    int get_money;

public:
    NoAction();
    ~NoAction();

    void enter(Player& player, int fields_to_go);
};

