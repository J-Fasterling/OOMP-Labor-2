#pragma once
#include "Field.h"
class NoAction :
    public Field
{
private:
    int get_money;

public:
    NoAction(int _get_money, std::string _name = "No Action");
    ~NoAction();
    void enter(Player& player);
    Monopoly* getMonopoly();
};

