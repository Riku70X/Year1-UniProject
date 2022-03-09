#include "Player.h"

void Player::takeDamage(int damage)
{
	health -= damage;
}

int Player::getAttackDamage()
{
	return ((rand() % 41) + 80);
}

Player::Player()
{
	health = 100;
	magic = 100;
	currentAction = "Null";
}