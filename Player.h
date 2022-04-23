#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std; // Including libraries so that the class can generate random numbers and use strings.

class Player
{
public:
	short getHealth();
	short getMagic();
	short getPotionCount();
	short getEtherCount();
	short getBottleRocketCount(); // Accessors for the private variables.
	Player();
	void takeDamage(short damage); // Reduces healthPoints by the value passed through "damage".
	short getAttackDamage(string action); // Returns the attack damage of the player for that turn.

private:
	short healthPoints; // Player health.
	short magicPoints; // Player magic.
	short numberOfPotions; // Limited healing item.
	short numberOfEthers; // Limited mp recovering item.
	short numberOfBottleRockets; // Limited damage dealing item.
};