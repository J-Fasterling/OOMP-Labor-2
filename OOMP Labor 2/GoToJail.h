#pragma once
#include "Field.h"
class GoToJail :
    public Field
{
private:
    //Das Gefaengnis welches es zu betreten gillt
    Field* jail;

public:
    GoToJail(std::string _name = "Neues Feld", Field* _jail = NULL);
    ~GoToJail();

    //Ereignis wenn man das Feld betritt
    void enter(Player& player);
    //Gibt das zugehoreiege Monopol zurueck
    Monopoly* get_Monopoly();
};

