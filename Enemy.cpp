#include "Enemy.h"

string Enemy::getName()
{
	return name;
}

short Enemy::getHealth()
{
	return healthPoints;
}

Enemy::Enemy()
{
	name = "Null";
	healthPoints = 0;
	attackStat = 0;
	weaknessDamageMultipler = 0;
	resistanceDamageMultiplier = 0;
} // Ideally, a short should always be passed when creating an Enemy, so if an enemy spawns with the name "Null", then I know there is an issue with the code.

Enemy::Enemy(short type)
{
	switch (type)
	{
	case 0:
		name = "Slime";
		healthPoints = 300;
		attackStat = 70;
		weaknessDamageMultipler = 1.5f;
		weaknesses.push_back("Blizzard");
		break;
	case 1:
		name = "Puppet";
		healthPoints = 500;
		attackStat = 150;
		weaknessDamageMultipler = 2;
		weaknesses.push_back("Fire");
		break;
	case 2:
		name = "Witch";
		healthPoints = 1000;
		attackStat = 350;
		weaknessDamageMultipler = 1.2f;
		resistanceDamageMultiplier = .3f;
		weaknesses.push_back("Strike");
		resistances.push_back("Fire"); resistances.push_back("Blizzard"); resistances.push_back("Thunder");
		break;
	case 3:
		name = "Mech";
		healthPoints = 2000;
		attackStat = 500;
		weaknessDamageMultipler = 1.5f;
		resistanceDamageMultiplier = .8f;
		weaknesses.push_back("Thunder");
		resistances.push_back("Strike");
		break;
	default: // This should also never run. If a default enemy spawns, I know there is an issue in the code.
		name = "Default";
		healthPoints = 0;
		attackStat = 0;
		weaknessDamageMultipler = 0;
		resistanceDamageMultiplier = 0;
		break;
	}
}



void Enemy::takeDamage(short damage, string action)
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
		} // Enemy takes more damage if the current action matches one of the enemy's weaknesses.
	}
	for (string resistance : resistances) // The for loop will run once for every item in the vector "resistances", with "resistance" iterating over the elements each loop.
	{
		if (resistance == action)
		{
			attackNormal = false;
			cout << "It's not very effective...\n";
			damage *= resistanceDamageMultiplier;
			healthPoints -= damage;
			cout << name << " took " << damage << " damage!\n";
			break;
		} // Enemy takes less damage if the current action matches one of the enemy's resistance.
	}
	if (attackNormal)
	{
		healthPoints -= damage;
		cout << name << " took " << damage << " damage!\n";
	}
}

short Enemy::getAttackDamage()
{
	return ((rand() % 30) + attackStat);
}