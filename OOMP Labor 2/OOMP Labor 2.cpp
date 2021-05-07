
#include <string>
#include <iostream>
#include "Field.h"
#include "GoToJail.h"
#include "NoAction.h"
#include "Tax.h"

int main()
{
    /*
    GoToJail test_field = GoToJail("Gehe ins Gefaengnis");
    GoToJail test_field_2 = GoToJail("Gehe nochmal nochmal ins Gefaengis", &test_field);
    Tax test_field_3 = Tax(200, "Einkommensteuer", &test_field, &test_field_2);
    */
    //Field* Spielfeld[4];
    /*
    Spielfeld[0] = new GoToJail("Gehe ins Gefaengnis", Spielfeld[1], Spielfeld[3]);
    Spielfeld[1] = new Tax(200, "Einkommensteuer", Spielfeld[2], Spielfeld[0]);
    Spielfeld[2] = new NoAction(500, "Frei Parken", Spielfeld[3], Spielfeld[1]);
    Spielfeld[3] = new Tax(100, "Vermoegenssteuer", Spielfeld[0], Spielfeld[2]);
    */
    /*int iCntBahnhof = 0;

    for (int i = 1; i <= 30; i++)
    {
        if (i % 1 == 0)
        {
            Spielfeld[i] = new NoAction(0, "Go");
        }
        else if (i % 6 == 0)
        {
            //Spielfeld[i] = Board.Bahnhofarray[iCntBahnhof];
            iCntBahnhof++;
        }
    }
    */
    }
