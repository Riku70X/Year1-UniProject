#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class Player
{
public:
	int health;
	int magic;
	string currentAction;
	void takeDamage(int damage); //reduces health by the value passed through "damage"
	int getAttackDamage(); //generates a random integer between 80 and 120
	Player();
};