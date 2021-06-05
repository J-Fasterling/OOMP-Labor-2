#include "Property.h"

Property::Property(std::string _name, int _value, Monopoly* _monopol, int price_for_house, Player* _owner) 
	: Field(_name), value{ _value }, monopoly{ _monopol }, owner{ _owner }, price_for_house{ _monopol->get_PriceforHouse() }{}

Property::Property(int _value, std::string _name, Monopoly* _monopol, Board* _board)
	: Field(_name, _board), value{ _value }, monopoly{ _monopol }, price_for_house{ _monopol->get_PriceforHouse() }{}


Property::~Property() {}

int Property::get_rent()
{
	return 0;
}

void Property::enter(Player& player) 
{
	Field::enter(player);

	if (owner)
	{
		if (&player != owner)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			if (player.get_Money() >= get_rent())
			{
				//Abziehen und zuschreiben der Miete vom Mieter an der Vermieter
				player.set_Money(player.get_Money() - get_rent());
				owner->set_Money(owner->get_Money() + get_rent());

				std::cout << player.get_Name() << " bezahlt ";
				//Konsolentextfarbe auf rot setzen
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << get_rent() << "$ ";
				//Konsolentextfarbe zuruecksetzen
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << "Miete an " << owner->get_Name() << std::endl;
				std::cout << owner->get_Name() << " bekommt ";
				//Konsolentextfarbe auf gruen setzen
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << get_rent() << "$ ";
				//Konsolentextfarbe zuruecksetzen
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << "an Miete von " << player.get_Name() << std::endl;
				std::cout << owner->get_Name() << " hat jetzt " << owner->get_Money() << " $." << std::endl;
			}
			else
			{
				//Abziehen und zuschreiben der Miete vom Mieter an der Vermieter
				owner->set_Money(owner->get_Money() + player.get_Money());

				std::cout << player.get_Name() << " bezahlt ";
				//Konsolentextfarbe auf rot setzen
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << player.get_Money() << "$ ";
				//Konsolentextfarbe zuruecksetzen
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << "Miete an " << owner->get_Name() << std::endl;
				std::cout << owner->get_Name() << " bekommt ";
				//Konsolentextfarbe auf gruen setzen
				SetConsoleTextAttribute(hConsole, 10);
				std::cout << player.get_Money() << "$ ";
				//Konsolentextfarbe zuruecksetzen
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << "an Miete von " << player.get_Name() << std::endl;
				std::cout << owner->get_Name() << " hat jetzt " << owner->get_Money() << " $." << std::endl;

				player.set_Money(0);
			}
		}
		else
		{
			//Wenn Feld einen Besitzer habt, pruefen, ob dieser ein Haus kaufen kann und will
			if (this->get_Monopoly()->has_all(*this->get_Owner())) 
			{
				if (this->get_Monopoly()->get_name() == "Braun" && "Hellblau" && "Pink" && "Orange" && "Rot" && "Gelb" && "Gruen" && "Blau")
				{
					if (possible_to_build_houses(player, get_House()) == 1)
					{
						if (player.want_to_buy_Houses(*this, player))
						{

							if (player.get_Money() >= player.get_Field()->get_Monopoly()->get_PriceforHouse())
							{
									this->set_House(this, get_House());
									player.set_Money(player.get_Money() - player.get_Field()->get_Monopoly()->get_PriceforHouse());

									std::cout << player.get_Name() << " hat jetzt noch " << player.get_Money() << " $." << std::endl;
							}
							else {
								std::cout << player.get_Name() << " hat nicht genuegend Geld, um sich ein Haus zu leisten." << std::endl;
							}
						}
					}
				}
			}

		}
	}
	else
	{
		if (player.want_to_buy_Property(*this, player))
		{
			if (player.get_Money() >= value)
			{
				player.set_Money(player.get_Money() - value);
				owner = &player;

				std::cout << player.get_Name() << " ist nun Inhaber von " << this->get_Name() << std::endl;
				int i = 0;
				while (player.imperium[i] != NULL)
				{
					i++;
				}
				//Schreibt Grundstueck ins Array des Spielers
				player.imperium[i] = this;
				int cntprop = player.get_Field()->get_Monopoly()->count_owned_properties(player);
				std::cout << "Monopole: " << cntprop << std::endl;
			}
			else 
			{
				std::cout << "Du kannst dir " << this->get_Name() << " nicht leisten." << std::endl;
			}
		}
	}
}
//Test

Monopoly* Property::get_Monopoly() 
{
	return monopoly;
}

/*Monopoly* Property::get_House_price()
{
	return price_for_house;
}*/

Player* Property::get_Owner()
{
	return owner;
}

//Property owner loeschen sodass Grundstuekc wieder gekauft werden kann
Player* Property::set_owner_bank()
{
	return owner = NULL;
}

//Grundstuekcseigentuemer festlegen
Player* Property::set_owner_player(Player &player)
{
	return owner = &player;
}

int Property::get_Value()
{
	return value;
}


int Property::possible_to_build_houses(Player& player, int iHouses)
{
	return 0;
}


void Property::set_House(Field* fField, int iHouses)
{
	
}

int Property::get_House()
{
	return 0;
}

void Property::new_property_owner(Player& deadplayer, Player& killerplayer)
{
	int i = 0;
	int j = 0;
	
	//Geht neue Grundstuecke durch und schreibt sie ins Besitzarray des Killerplayer
	while (deadplayer.imperium[i] != NULL)
	{
		while (killerplayer.imperium[j] != NULL)
		{
			j++;
		}
		killerplayer.imperium[j] = deadplayer.imperium[i];
		killerplayer.imperium[j]->set_owner_player(killerplayer);
		i++;
	}
}