#include "Player.h"

Player::Player()
{
	healthPoints = 100;
	magicPoints = 100;
	currentAction = "Null";
}

void Player::takeDamage(short damage)
{
	healthPoints -= damage;
}

short Player::getAttackDamage()
{
	return ((rand() % 41) + 80);
}