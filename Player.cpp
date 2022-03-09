#include "Player.h"

void Player::takeDamage(short damage)
{
	health -= damage;
}

short Player::getAttackDamage()
{
	return ((rand() % 41) + 80);
}

Player::Player()
{
	health = 100;
	magic = 100;
	currentAction = "Null";
}