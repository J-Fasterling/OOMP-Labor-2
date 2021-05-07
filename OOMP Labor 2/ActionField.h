#include "Field.h"

#pragma once
class ActionField :
    public Field
{
public:
    ActionField(std::string _name, Field* _next, Field* _prev);
    ActionField();
    ~ActionField();
};

