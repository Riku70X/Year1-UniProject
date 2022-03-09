#include "Enemy.h"

Enemy::Enemy()
{
	healthPoints = 0;
	name = "Null";
	attackStat = 0;
	damageMultipler = 0;
}

void Enemy::takeDamage(short damage)
{
	healthPoints -= damage;
}

short Enemy::getAttackDamage()
{
	return ((rand() % 30) + 1);
}