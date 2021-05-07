#include "Player.h"

Player::Player(int iMoney, Field* fField, std::string sName)
	: money{ iMoney }, field{ fField }, name{ sName } {}

Player::Player() {}

Player::~Player() {}
