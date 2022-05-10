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

void Dragon::takeDamage(short damage, string action)
{
	attackNormal = true;
	for (string weakness : weaknesses) // The for loop will run once for every item in the vector "weaknesses", with "weakness" iterating over the elements each loop.
	{
		if (weakness == action)
		{
			attackNormal = false;
			cout << "It's Super Effective!\n";
			damage *= weaknessDamageMultipler;
			healthPoints -= damage;
			cout << name << " took " << damage << " damage!\n";
			break;
		} // The Dragon takes more damage if the current action matches one of the Dragon's weaknesses.
	}
	if (action == "Fire")
	{
		attackNormal = false;
		cout << "The Dragon absorbed the attack!\n";
		healthPoints += damage;
		cout << name << " healed " << damage << "HP!\n";
	} // The Dragon will restore HP if attacked with Fire magic.
	if (attackNormal)
	{
		healthPoints -= damage;
		cout << name << " took " << damage << " damage!\n";
	}
	runStatusCheck(action);
}

short Dragon::getAttackDamage()
{
	currentTurn++;
	if (currentTurn > 15 && hasHealed == false && rand() % 10 == 9) // For the Dragon to heal, 15 turns must have passed. After this, the Dragon has a 10% chance every turn to heal itself. If successful, it will never heal again.
	{
		healthPoints += 1000;
		cout << "The Dragon has cauterised it's wounds!\nThe Dragon has healed 1000HP!\n";
		hasHealed = true;
		return 0;
	}
	else
	{
		if (frozen)
		{
			cout << name << " is frozen! Cannot attack!\n";
			return 0;
		}  // Dragon deals 0 damage if it is frozen.
		else if (paralysed && rand() % 2 == 1) // 50% chance to miss.
		{
			cout << name << " flinched due to paralysis! Attack failed!\n";
			return 0;
		} // Dragon has a 50% chance to deal 0 damage if it is paralysed.
		else
		{
			return ((rand() % 30) + attackStat); // If the Dragon chooses not to heal, then it will attack using its attackStat, and an additive value from 1-30 for variety.
		}
	}
}