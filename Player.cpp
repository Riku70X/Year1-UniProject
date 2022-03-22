#include "Player.h"

Player::Player()
{
	healthPoints = 10000;
	magicPoints = 200;
	currentAction = "Null";
} // Player stats when the game begins

void Player::takeDamage(short damage)
{
	healthPoints -= damage;
}

short Player::getAttackDamage()
{
	return ((rand() % 41) + 80);
}