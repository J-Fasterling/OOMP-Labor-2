#pragma once
#include "Property.h"

class Street :
    public Property {
private:
    int rent[6];
    int houses;

public:
    int get_rent(int _type);
    Street(std::string _name, int _value, Monopoly* _monopoly, 
        int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0, int m5 = 0, int m6 = 0);
    ~Street();
    //void enter(Player& player);

};

