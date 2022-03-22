#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std; // including libraries so that the class can generate random numbers and use strings

class Enemy
{
public:
	string name;
	short healthPoints; // enemy health
	float attackStat; // base attack of the enemy. getAttackDamage adds some variation
	float damageMultipler; // amplifies the damage taken from attacks if the enemy is weak to or resists the player's current attack
	string weaknesses[4]; // list of attacks which the enemy is weak to
	string resistances[4]; // listof attacks which the enemy resists
	Enemy();
	Enemy(short type);
	void takeDamage(short damage); // reduces healthPoints by the value passed through "damage"
	short getAttackDamage(); // returns a random integer between 1 and 30
};