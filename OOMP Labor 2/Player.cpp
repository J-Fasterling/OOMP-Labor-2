#include "Player.h"
#include <iostream>
//#include "Property.h"

Player::Player(Field* fField, std::string sName)
	: money{ 1500 }, field{ fField }, name{ sName } {}

Player::~Player() {}


std::string Player::get_Name()
{
	return name;
}


void Player::setField(Field* fField)
{
	field = fField;
}


Field* Player::getField()
{
	return field;
}

void Player::setMoney(int iMoney)
{
	money = iMoney;
}

int Player::getMoney()
{
	return money;
}

bool Player::want_to_buy(Property& property)
{
	char eingabe;
	std::cout << "Moechtest du dieses Grundstueck kaufen? (j/n): ";
	std::cin >> eingabe;

	while (std::cin.fail() || (eingabe != 'j' && eingabe != 'n'))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Fehlerhafte eingabe! " << std::endl;
		std::cout << "Moechtest du dieses Grundstueck kaufen? (j/n): ";
		std::cin >> eingabe;
	}

	if (eingabe == 'j')
	{
		return true;
	}
	else
	{
		return false;  
	}
}
