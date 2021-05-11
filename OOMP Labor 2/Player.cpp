#include "Player.h"
#include <iostream>

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


bool Player::want_to_buy_Property(Property& property, Player& player)
{
	//Eingabechar
	char eingabe;
	std::cout << player.get_Name() << " hat noch " << player.getMoney() << " $."<< std::endl;
	std::cout << "Moechtest du dieses Grundstueck kaufen? (j/n): ";
	std::cin >> eingabe;

	//Fehlerhafte Eingabe !(j/n) abfangen
	while (std::cin.fail() || (eingabe != 'j' && eingabe != 'n'))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Fehlerhafte eingabe! " << std::endl;
		std::cout << "Moechtest du dieses Grundstueck kaufen? (j/n): ";
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

bool Player::want_to_buy_Houses(Property& property, Player& player, Monopoly& _price_for_house)
{
	//Eingabechar
	char eingabe;
	std::cout << player.get_Name() << " hat noch " << player.getMoney() << " $." << std::endl;
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
