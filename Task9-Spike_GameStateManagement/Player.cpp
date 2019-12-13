#include "pch.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

Player* Player::Instance()
{
	if (_instance == NULL) {
		_instance = new Player;
	}
	return _instance;
}

Player* Player::_instance;

void Player::setHP(int HP)
{
	Player::hp = HP;
}

void Player::setLocation(string loc)
{
	Player::current_location = loc;
}

string Player::getLocation()
{
	return Player::current_location;
}

int Player::getHP()
{
	return Player::hp;
}
