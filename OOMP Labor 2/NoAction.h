#pragma once
#include "Field.h"
class NoAction :
    public Field
{
private:
    int get_money;

public:
    NoAction(int _get_money, std::string _name, Field* _next, Field* _prev);
    ~NoAction();

    //void enter(Player& player, int fields_to_go);
};

