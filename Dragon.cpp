#include "Dragon.h"

Dragon::Dragon()
{
	name = "Dragon";
	healthPoints = 10000;
	attackStat = 1500;
	weaknessDamageMultipler = 2.5f;
	weaknesses.push_back("bottleRocket");
	hasHealed = false;
	currentTurn = 0;
}

short Dragon::getAttackDamage()
{
	currentTurn++;
	if (currentTurn > 5 && hasHealed == false && rand() % 10 == 9)
	{
		healthPoints += 1000;
		cout << "The Dragon has cauterised it's wounds!\nThe Dragon has healed 1000HP!\n";
		hasHealed = true;
		return 0;
	}
	else
	{
		return ((rand() % 30) + attackStat);
	}
}

void Dragon::takeDamage(short damage, string action)
{
	cout << "dragon called\n";
	attackNormal = true;
	for (string weakness : weaknesses)
	{
		if (weakness == action)
		{
			attackNormal = false;
			cout << "It's Super Effective!\n";
			damage *= weaknessDamageMultipler;
			healthPoints -= damage;
			cout << name << " took " << damage << " damage!\n";
			break;
		}
	}
	if (action == "fire")
	{
		attackNormal = false;
		cout << "The Dragon absorbed the attack!\n";
		healthPoints += damage;
		cout << name << " healed " << damage << "HP!\n";
	}
	if (attackNormal)
	{
		healthPoints -= damage;
		cout << name << " took " << damage << " damage!\n";
	}
}