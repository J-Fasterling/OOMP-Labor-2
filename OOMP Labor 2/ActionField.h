#include "Field.h"

#pragma once
class ActionField :
    public Field
{
public:
    ActionField(std::string _name = "Action Field");
    ~ActionField();
    void enter(Player &player);

};

