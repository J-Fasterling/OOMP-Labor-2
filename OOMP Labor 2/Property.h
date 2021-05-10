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
    Monopoly* monopoly;

public:
    int get_Rent();
    Property(std::string _name, int _value = 0, Monopoly* _monopoly = NULL, Player* _owner = NULL);
    ~Property();
    void enter(Player& player);
    Monopoly* getMonopoly();
    Player* getOwner();
};
