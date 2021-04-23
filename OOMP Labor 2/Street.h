#pragma once
#include "Property.h"
class Street :
    public Property {
private:
    int rent[6];
    int houses;

public:
    int get_rent();
};

