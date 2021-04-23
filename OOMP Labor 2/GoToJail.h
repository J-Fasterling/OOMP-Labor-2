#pragma once
#include "Field.h"
class GoToJail :
    public Field
{
private:
    Field* jail;

public:
    GoToJail();
    ~GoToJail();

    void enter(Player& player, int fields_to_go);
};

