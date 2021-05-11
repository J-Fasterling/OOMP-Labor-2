#include "Field.h"

#pragma once
class ActionField :
    public Field
{
public:
    ActionField(std::string _name = "Action Field");
    ~ActionField();

    //Ereignis wenn man das Feld betritt
    void enter(Player& player);
    //Gibt das zugehoerige Monopol zurueck
    Monopoly* getMonopoly();
};

