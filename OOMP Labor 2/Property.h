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
    //Kaufpreis Haus
    int price_for_house;
    //zugehoreiges Monopol
    Monopoly* monopoly;

public:
    Property(std::string _name, int _value = 0, Monopoly* _monopol = NULL, int price_for_house = 0, Player* _owner = NULL);
    ~Property();

    //virtuelle Funktio, die die Miete zurueckgibt
    virtual int get_rent();
    //loest Ereigniss beim betreten des Felds aus
    void enter(Player& player);
    //gibt das zugehoreige Monopol aus
    Monopoly* get_Monopoly();
    //gibt den zugehoreigen Besitzer aus
    Player* get_Owner();
    Player* set_owner_bank();
    Player* set_owner_player(Player& player);
    //Preis des Grunstuecks zurueckgeben
    int get_Value();
    //Haeuser bauen
    virtual int possible_to_build_houses(int iHouses);
        //Haeuser zaehlen
    //int count_houses_on_properties(Field *fField, Player& player);
        //Haeuser setzen
    virtual void set_House(Field* fField, int iHouses);
        //Haeseranzahl auf Feld
    virtual int get_House();
    // Grundstuecke an neuen Besitzer geben
    void new_property_owner(Player &deadplayer, Player &killerplayer);
};
