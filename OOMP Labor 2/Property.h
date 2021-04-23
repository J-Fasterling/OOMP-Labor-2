#pragma once
#include <string>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"

class Property :
    public Field {
private:
    Player* owner;
    int value;
    Monopoly* monopoly;

public:
    int get_Rent();
    void enter(player:Player&, int fields_to_go);

    Property();
    ~Property();

};

class Railroad :
       public Property {
private:
    int rent[4];

public:
    int get_rent();
};

class Street :
    public Property {
private:
    int rent[6];
    int houses;

public:
    int get_rent();
};

class Utility :
    public Property {
private: 
    int dice_factor_single;
    int dice_factor_monopoly;

public:
    int get_rent();
};

