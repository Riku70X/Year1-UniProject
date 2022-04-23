#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std; // Including libraries so that the class can generate random numbers and use strings and vectors.

class Enemy
{
public:
	string getName();
	short getHealth(); // Accessors for protected variables.
	Enemy();
	Enemy(short type); // Overloaded constructor used to set up unique enemies.
	void takeDamage(short damage, string action); // Reduces healthPoints by the value passed through "damage". This value is increased/decreased if the enemy is weak to/resists the current action.
	short getAttackDamage(); // Returns a random integer between 1 and 30, added to the enemy's attackStat.

protected: // Protected so that the Dragon class can still reach them.
	string name;
	short healthPoints; // Enemy health.
	short attackStat; // Base attack of the enemy. getAttackDamage adds some variation.
	float weaknessDamageMultipler; // Amplifies the damage taken from attacks if the enemy is weak to the player's current attack.
	float resistanceDamageMultiplier; // Reduces the damage taken from attacks if the enemy resists the player's current attack.
	vector<string> weaknesses = {}; // List of attacks which the enemy is weak to.
	vector<string> resistances = {}; // List of attacks which the enemy resists.
	bool attackNormal; // True if the current attack is not resisted nor a weakness.
};