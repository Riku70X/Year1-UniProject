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
	void runStatusCheck(string action); // Checks if the enemy has a status effect, and applies new status effects if conditions are met.
	void takeDamage(short damage, string action); // Reduces healthPoints by the value passed through "damage". This value is increased/decreased if the enemy is weak to/resists the current action.
	short getAttackDamage(); // Returns the enemy's attackStat, with an added random integer between 0 and 30 for variance.
	
protected: // Protected so that the Dragon class can still reach them.
	string name;
	short healthPoints; // Enemy health.
	short maxHealth; // A constant which stores the enemies' max health used for burning calculations.
	short attackStat; // Base attack of the enemy. getAttackDamage adds some variation.
	float weaknessDamageMultipler; // Amplifies the damage taken from attacks if the enemy is weak to the player's current attack.
	float resistanceDamageMultiplier; // Reduces the damage taken from attacks if the enemy resists the player's current attack.
	vector<string> weaknesses = {}; // List of attacks which the enemy is weak to.
	vector<string> resistances = {}; // List of attacks which the enemy resists.
	bool attackNormal; // True if the current attack is not resisted nor a weakness.
	bool burning; // True if the enemy has the burn status effect.
	bool frozen; // True if the enemy has the frozen status effect.
	bool paralysed; // True if the enemy has the paralysis status effect.
	short statusCounter; // Counter which determines how long a status effect will last.
};