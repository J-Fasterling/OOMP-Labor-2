#include <vector>
#include "Field.h"

#pragma once
class ActionField :
    public Field
{
private:
    template<class T>
    T chooseActioncard(int card, Player& player);
    template<class T>
    T chooseCommunitycard(int card, Player& player);

    int action_cnt = 0;

    int community_cnt = 0;

public:
    ActionField(Board* _board, std::string _name = "Action Field");
    ~ActionField();

    //Ereignis wenn man das Feld betritt
    void enter(Player& player);
    //Gibt das zugehoerige Monopol zurueck
    Monopoly* get_Monopoly();
};

