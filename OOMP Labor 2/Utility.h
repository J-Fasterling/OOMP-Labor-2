#pragma once
#include "Property.h"
class Board;
class Utility :
    public Property {
private:
    //Multiplikator der Wuerfelzahl ohne Monopol
    int dice_factor_single;
    //Multiplikator der Wuerfelzahl mit Monopol
    int dice_factor_monopoly;

public:
    Utility(std::string _name, Monopoly* _monopoly, Board* _board);
    ~Utility();

    //gibt die Miete auf diesem Feld zurueck
    int get_rent();
};


