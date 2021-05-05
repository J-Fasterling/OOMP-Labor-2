#pragma once
#include "Field.h"
class GoToJail :
    public Field
{
private:
    Field* jail;

public:
    GoToJail(Field* _jail, std::string _name, Field* _next, Field* _prev);
    ~GoToJail();

   // void enter(Player& player, int fields_to_go);
};

