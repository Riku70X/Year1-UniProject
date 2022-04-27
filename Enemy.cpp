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
	maxHealth = 0;
	attackStat = 0;
	weaknessDamageMultipler = 0;
	resistanceDamageMultiplier = 0;
	attackNormal = true;
	burning = false;
	frozen = false;
	paralysed = false;
	statusCounter = 0;
} // Ideally, a short should always be passed when creating an Enemy, so if an enemy spawns with the name "Null", then I know there is an issue with the code.

Enemy::Enemy(short type)
{
	switch (type)
	{
	case 0:
		name = "Slime";
		healthPoints = 300;
		maxHealth = 300;
		attackStat = 70;
		weaknessDamageMultipler = 1.5f;
		weaknesses.push_back("Blizzard");
		break;
	case 1:
		name = "Puppet";
		healthPoints = 500;
		maxHealth = 500;
		attackStat = 150;
		weaknessDamageMultipler = 2;
		weaknesses.push_back("Fire");
		break;
	case 2:
		name = "Witch";
		healthPoints = 1000;
		maxHealth = 1000;
		attackStat = 350;
		weaknessDamageMultipler = 1.2f;
		resistanceDamageMultiplier = .3f;
		weaknesses.push_back("Strike");
		resistances.push_back("Fire"); resistances.push_back("Blizzard"); resistances.push_back("Thunder");
		break;
	case 3:
		name = "Mech";
		healthPoints = 2000;
		maxHealth = 2000;
		attackStat = 500;
		weaknessDamageMultipler = 1.5f;
		resistanceDamageMultiplier = .8f;
		weaknesses.push_back("Thunder");
		resistances.push_back("Strike");
		break;
	default: // This should also never run. If a default enemy spawns, I know there is an issue in the code.
		name = "Default";
		healthPoints = 0;
		maxHealth = 0;
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
	if (statusCounter == 0) // When the counter reaches 0, current status effects will stop, and the enemy is now able to get a new status effect.
	{
		if (burning)
		{
			burning = false;
			cout << name << " stopped burning!\n";
		}
		else if (frozen)
		{
			frozen = false;
			cout << name << " thawed out!\n";
		}
		else if (paralysed)
		{
			paralysed = false;
			cout << name << " is no longer paralysed!\n";
		}
		else
		{
			if (action == "Fire" && (rand() % 100) < 40) // 40% chance to burn.
			{
				burning = true;
				statusCounter = (rand() % 4) + 1; // Burn lasts for 1-4 turns.
				cout << name << " started burning!\n";
			}
			else if (action == "Blizzard" && (rand() % 100) < 20) // 20% chance to freeze.
			{
				frozen = true;
				statusCounter = (rand() % 1) + 2; // Freeze lasts for 2-3 turns.
				cout << name << " was frozen solid!\n";
			}
			else if (action == "Thunder" && (rand() % 100) < 30) // 30% chance to paralyse.
			{
				paralysed = true;
				statusCounter = (rand() % 3) + 2; // Paralysis lasts for 2-4 turns.
				cout << name << " was paralysed!\n";
			}
		}
	}
	else // If statusCounter is not 0, then the enemy must have a status effect.
	{
		if (burning)
		{
			healthPoints -= (maxHealth * (rand() % 5 + 2) / 100); // Burn deals 2%-6% of the enemy's health.
			cout << name << " took burn damage!";
		}
		statusCounter--; // If it is not 0, then it decrements each turn until it is.
	}
	
}

short Enemy::getAttackDamage()
{
	return ((rand() % 31) + attackStat);
}