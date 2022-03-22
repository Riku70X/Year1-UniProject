#include "Enemy.h"

Enemy::Enemy()
{
	healthPoints = 0;
	name = "Null";
	attackStat = 0;
	damageMultipler = 0;
} // Ideally, a short should always be passed when creating an Enemy, so if an enemy spawns with the name "Null", then I know there is an issue with the code.

Enemy::Enemy(short type)
{
	switch(type)
		case 0:
		case 1:
		case 2:
		case 3:
		default: // This should also never run. If a default enemy spawns, I know there is an issue in the code.
			healthPoints = 0;
			name = "Default"; 
			attackStat = 0;
			damageMultipler = 0;
}

void Enemy::takeDamage(short damage)
{
	healthPoints -= damage;
}

short Enemy::getAttackDamage()
{
	return ((rand() % 30) + attackStat);
}