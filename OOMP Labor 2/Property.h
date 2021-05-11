#pragma once
#include <string>
#include "Field.h"
#include "Player.h"
#include "Monopoly.h"
#include <iostream>

class Property :
    public Field {

private:
    //Besitzer des Grundstuecks
    Player* owner;
    //Kaufpreis Grundstuecks
    int value;
    //zugehoreiges Monopol
    Monopoly* monopoly;

public:
    Property(std::string _name, int _value = 0, Monopoly* _monopoly = NULL, Player* _owner = NULL);
    ~Property();

    //virtuelle Funktio, die die Miete zurueckgibt
    virtual int get_rent();
    //loest Ereigniss beim betreten des Felds aus
    void enter(Player& player);
    //gibt das zugehoreige Monopol aus
    Monopoly* getMonopoly();
    //gibt den zugehoreigen Besitzer aus
    Player* getOwner();
    //Gibt den Preis des Grundstuecks zurueck
    int GetValue();
};
