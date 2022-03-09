#include "Enemy.h"

void Enemy::takeDamage(short)
{
}

short Enemy::getAttackDamage()
{
	return 0;
}

Enemy::Enemy()
{
	health = 0;
	name = "Null";
	attackStat = 0;
	damageMultipler = 0;
}