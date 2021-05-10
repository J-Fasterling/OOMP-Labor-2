#pragma once
#include "Field.h"
class GoToJail :
    public Field
{
private:
    Field* jail;

public:
    GoToJail(std::string _name = "Neues Feld", Field* _jail = NULL);
    ~GoToJail();
    void enter(Player& player);
    Monopoly* getMonopoly();
};

