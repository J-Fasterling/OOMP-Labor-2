#pragma once
#include "Property.h"
class Utility :
    public Property {
private:
    int dice_factor_single;
    int dice_factor_monopoly;

public:
    int get_rent();
    Utility(std::string _name, Monopoly* _monopoly);
    ~Utility();
    //void enter(Player& player);

};


