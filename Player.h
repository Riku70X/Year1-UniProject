#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std; // including libraries so that the class can generate random numbers and use strings

class Player
{
public:
	short healthPoints; // player health
	short magicPoints; // player magic
	string currentAction; 
	Player();
	void takeDamage(short damage); // reduces healthPoints by the value passed through "damage"
	short getAttackDamage(); // returns a random integer between 80 and 120
};