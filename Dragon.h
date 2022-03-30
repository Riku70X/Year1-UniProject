#pragma once
#include "Enemy.h"

class Dragon : public Enemy
{
public:
	bool hasHealed;
	int currentTurn;
	Dragon();
	void takeDamage(short damage, string action);
	short getAttackDamage();
};

