#pragma once
#include "Field.h"
class ActionField :
    public Field
{
public:
    void enter(Player& player, int fields_to_go);
};

