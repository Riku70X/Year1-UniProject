#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std; // including libraries so that the class can generate random numbers and use strings and vectors

class Enemy
{
public:
	string getName();
	short getHealth();
	Enemy();
	Enemy(short type);
	void takeDamage(short damage, string action); // reduces healthPoints by the value passed through "damage"
	short getAttackDamage(); // returns a random integer between 1 and 30, added to the enemy's attackStat

private:
	string name;
	short healthPoints; // enemy health
	short attackStat; // base attack of the enemy. getAttackDamage adds some variation
	float weaknessDamageMultipler; // amplifies the damage taken from attacks if the enemy is weak to the player's current attack
	float resistanceDamageMultiplier; // reduces the damage taken from attacks if the enemy resists the player's current attack
	vector<string> weaknesses = {}; // list of attacks which the enemy is weak to
	vector<string> resistances = {}; // list of attacks which the enemy resists
	bool attackNormal; // true if the current attack is not resisted nor a weakness
};