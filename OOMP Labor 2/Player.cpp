#include "Player.h"

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
