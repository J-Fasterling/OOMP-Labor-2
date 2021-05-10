#pragma once
#include "Property.h"

 class Railroad :
    public Property 
 {
private:
    int rent[4];

public:
    int get_rent();
    Railroad(std::string _name, Monopoly* _monopoly);
    ~Railroad();
    //void enter(Player& player);

};

