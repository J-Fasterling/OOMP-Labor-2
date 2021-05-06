#pragma once
#include <string>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"
using namespace std;

class Property :
    public Field {
private:
    Player* owner;
    int value;
    Monopoly* monopoly;

public:
    int get_Rent(std::string _name, Field* _next, Field* _prev);
    void enter(player:Player&, int fields_to_go);

    Property();
    ~Property();

};
