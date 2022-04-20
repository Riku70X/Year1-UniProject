#include "Player.h"

short Player::getHealth()
{
	return healthPoints;
}

short Player::getMagic()
{
	return magicPoints;
}

Player::Player()
{
	healthPoints = 10000;
	magicPoints = 50;
	numberOfPotions = 10;
	numberOfEthers = 5;
	numberOfBottleRockets = 2;
} // Player stats when the game begins

void Player::takeDamage(short damage)
{
	healthPoints -= damage;
	cout << "Player took " << damage << " damage!\n";
}

short Player::getAttackDamage(string action)
{
	if (action == "strike")
	{
		return ((rand() % 41) + 80); // returns a random value from 80-120
	}
	else if (action == "fire")
	{
		magicPoints -= 3;
		return ((rand() % 101) + 250); // returns a random value from 250-350
	}
	else if (action == "blizzard")
	{
		magicPoints -= 4;
		return ((rand() % 51) + 200); // returns a random value from 200-250
	}
	else if (action == "thunder")
	{
		magicPoints -= 5;
		return ((rand() % 151) + 350); // returns a random value from 350-500
	}
	else if (action == "potion")
	{
		return 0;
	}
	else
	{
		cout << "Action Error\n"; // code should ideally never run
		return 0;
	}
}