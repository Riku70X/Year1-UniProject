#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std; // including libraries so that the class can generate random numbers and use strings

class Enemy
{
public:
	short healthPoints;
	string name;
	float attackStat;
	float damageMultipler;
	string weaknesses[4];
	string resistances[4];
	Enemy();
	void takeDamage(short damage); // reduces health by the value passed through "damage"
	short getAttackDamage(); // returns a random integer between 1 and 30
};