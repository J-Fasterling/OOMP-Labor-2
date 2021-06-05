#include "Field.h"

#pragma once
class ActionField :
    public Field
{
private:
    template<class T>
    T chooseAction(int card, Player& player);
public:
    ActionField(std::string _name = "Action Field");
    ~ActionField();

    //Ereignis wenn man das Feld betritt
    void enter(Player& player);
    //Gibt das zugehoerige Monopol zurueck
    Monopoly* get_Monopoly();
};

