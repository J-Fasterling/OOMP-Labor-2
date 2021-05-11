#pragma once
#include "Field.h"
class NoAction :
    public Field
{
private:
    //Integer wie viel Geld man auf dem Feld bekommt
    int get_money;

public:
    NoAction(int _get_money, std::string _name = "No Action");
    ~NoAction();

    //Ereignis wenn man das Feld betritt
    void enter(Player& player);
    //GIbt das zugehoreige Monopol aus
    Monopoly* getMonopoly();
};

