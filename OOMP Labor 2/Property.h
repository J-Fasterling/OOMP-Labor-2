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
