#pragma once
#include "Enemy.h"

class Dragon : public Enemy
{
public:
	Dragon();
	void takeDamage(short damage, string action); // Replaces the enemy function of the same name, since the Dragon has a special ability where it heals from fire attacks.
	short getAttackDamage(); // Replaces the enemy function of the same name, since the Dragon will sometimes use an attack turn to instead heal itself. It will do this up to once per fight.

private:
	bool hasHealed; // Becomes true after the Dragon heals, so it cannot heal again.
	int currentTurn; // The Dragon counts how many turns 
};