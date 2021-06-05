#pragma once
#include "Property.h"

class Street :
    public Property {
private:
    //Array mit Mieten/Haeusern auf dieser Strasse
    int rent[6];
    //Anzahl der Haeuser
    int houses;

public:
    Street(std::string _name, int _value, Monopoly* _monopoly, int price_for_house,
        int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0, int m5 = 0, int m6 = 0);
    ~Street();

    //Gibt die Miete auf diesem Feld zurueck
    int get_rent();

    //Haeuser kaufen
    int possible_to_build_houses(Player& player, int iHouses);

    //Haeuser bauen
    void set_House(Field* fField, int iHouses);

    //get Haeuser
    int get_House();
};

