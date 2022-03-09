#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class Enemy
{
public:
	short health;

private:
	string name;
	float attackStat;
	float damageMultipler;
};