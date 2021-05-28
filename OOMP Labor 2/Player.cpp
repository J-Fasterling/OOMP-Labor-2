#include "Player.h"
#include <iostream>
#include "Property.h"

Player::Player(Field* fField, std::string sName)
	: money{ 1500 }, field{ fField }, name{ sName }, is_in_jail{false} {}

Player::~Player() {}


std::string Player::get_Name()
{
	return name;
}


void Player::set_Field(Field* fField)
{
	field = fField;
}


Field* Player::get_Field()
{
	return field;
}

void Player::set_Money(int iMoney)
{
	money = iMoney;
}


int Player::get_Money()
{
	return money;
}


bool Player::want_to_buy_Property(Property& property, Player& player)
{
	//Eingabechar
	char eingabe;
	std::cout << player.get_Name() << " hat noch " << player.get_Money() << " $." << std::endl;
	std::cout << "Moechtest du dieses Grundstueck fuer "<< property.get_Value() << "$ kaufen? (j/n): ";
	std::cin >> eingabe;

	//Fehlerhafte Eingabe !(j/n) abfangen
	while (std::cin.fail() || (eingabe != 'j' && eingabe != 'n'))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Fehlerhafte eingabe! " << std::endl << std::endl;
		std::cout << "Moechtest du dieses Grundstueck fuer " << property.get_Value() << "$ kaufen? (j/n): ";
		std::cin >> eingabe;
	}

	//j = true / n = false
	if (eingabe == 'j')
	{
		return true;
	}
	else
	{
		return false;  
	}
}

bool Player::want_to_buy_Houses(Property& property, Player& player)
{
	//Eingabechar
	char eingabe;
	std::cout << player.get_Name() << " hat noch " << player.get_Money() << " $." << std::endl;
	std::cout << "Moechtest du auf diesem Grundstuek Haueser kaufen? (j/n): ";
	std::cin >> eingabe;

	//Fehlerhafte Eingabe !(j/n) abfangen
	while (std::cin.fail() || (eingabe != 'j' && eingabe != 'n'))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Fehlerhafte eingabe! " << std::endl;
		std::cout << "Moechtest du auf diesem Grundstuek Haueser kaufen? (j/n): ";
		std::cin >> eingabe;
	}

	//j = true / n = false
	if (eingabe == 'j')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::is_inmate(Player& player) 
{
	is_in_jail = true;

}

void Player::prison_break(Player& player)
{
	is_in_jail = false;
}