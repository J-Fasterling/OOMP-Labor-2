#pragma once
#include <string>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"
#include <iostream>

class Property :
    public Field {

private:
    Player* owner;
    int value;
    Monopoly* mMonopoly;

public:
    int get_Rent(std::string _name, Field* _next, Field* _prev);
    void enter(Player player, int fields_to_go);

    Property();
    ~Property();
};
