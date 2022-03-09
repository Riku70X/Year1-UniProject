#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class Enemy
{
public:
	short health;
	void takeDamage(short);
	short getAttackDamage();
	Enemy();

private:
	string name;
	float attackStat;
	float damageMultipler;
	string weaknesses[4];
	string resistances[4];
};