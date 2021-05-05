#pragma once
#include "Field.h"
class ActionField :
    public Field
{
public:
    ActionField(std::string _name, Field* _next, Field* _prev);
    ~ActionField();

   // void enter(Player& player, int fields_to_go);
};

