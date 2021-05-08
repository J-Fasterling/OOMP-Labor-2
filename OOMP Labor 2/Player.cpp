#include "Player.h"

Player::Player(Field* fField, std::string sName)
	: money{ 1500 }, field{ fField }, name{ sName } {}

Player::~Player() {}


std::string Player::get_Name()
{
	return name;
}
