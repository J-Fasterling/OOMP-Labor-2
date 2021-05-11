#pragma once
#include "Property.h"

class Street :
    public Property {
private:
    //Array mit mieten/Haus auf dieser Strasse
    int rent[6];
    //Anzahl der Haeuser
    int houses;

public:
    Street(std::string _name, int _value, Monopoly* _monopoly, 
        int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0, int m5 = 0, int m6 = 0);
    ~Street();

    //Gibt die miete auf diesem Feld zurueck
    int get_rent();

    //Haeuser kaufen
    int build_houses();
};

