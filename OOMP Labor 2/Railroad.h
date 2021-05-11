#pragma once
#include "Property.h"

 class Railroad :
    public Property 
 {
private:
    //Array mit allen Mieten
    int rent[4];

public:
    Railroad(std::string _name, Monopoly* _monopoly);
    ~Railroad();

    //Gibt die Miete auf diesem Feld zurueck
    int get_rent();
};

