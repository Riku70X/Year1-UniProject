#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class Player
{
public:
	short health;
	short magic;
	string currentAction;
	void takeDamage(short damage); //reduces health by the value passed through "damage"
	short getAttackDamage(); //generates a random integer between 80 and 120
	Player();
};