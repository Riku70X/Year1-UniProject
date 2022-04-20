#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std; // including libraries so that the class can generate random numbers and use strings

class Player
{
public:
	short getHealth();
	short getMagic();
	Player();
	void takeDamage(short damage); // reduces healthPoints by the value passed through "damage"
	short getAttackDamage(string action); // returns the attack damage of the player for that turn

private:
	short healthPoints; // player health
	short magicPoints; // player magic
	short numberOfPotions; // limited healing item
	short numberOfEthers; // limited mp recovering item
	short numberOfBottleRockets; // limited damage dealing item
};