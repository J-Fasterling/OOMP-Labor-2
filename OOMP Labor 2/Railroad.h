#pragma once
#include "Property.h"
 class Railroad :
    public Property {
private:
    int rent[4];

public:
    int get_rent();
    Railroad();
    ~Railroad();
};

