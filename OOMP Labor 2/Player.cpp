#include "Player.h"

Player::Player(Field* fField, std::string sName)
	: money{ 1500 }, field{ fField }, name{ sName } {}

Player::~Player() {}
