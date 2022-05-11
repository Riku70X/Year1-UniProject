#include "Player.h"

short Player::getHealth()
{
	return healthPoints;
}

short Player::getMagic()
{
	return magicPoints;
}

short Player::getPotionCount()
{
	return numberOfPotions;
}

short Player::getEtherCount()
{
	return numberOfEthers;
}

short Player::getBottleRocketCount()
{
	return numberOfBottleRockets;
}

Player::Player()
{
	healthPoints = 10000;
	magicPoints = 50;
	numberOfPotions = 10;
	numberOfEthers = 5;
	numberOfBottleRockets = 2;
} // Player stats when the game begins.

void Player::takeDamage(short damage)
{
	healthPoints -= damage;
	cout << "Player took " << damage << " damage!\n";
}

short Player::getAttackDamage(string action)
{
	if (action == "Strike")
	{
		cout << "You struck the enemy!\n";
		return ((rand() % 41) + 80); // Returns a random value from 80-120.
	}
	else if (action == "Fire")
	{
		cout << "You cast Fire!\n";
		magicPoints -= 3;
		return ((rand() % 101) + 250); // Returns a random value from 250-350.
	}
	else if (action == "Blizzard")
	{
		cout << "You cast Blizzard!\n";
		magicPoints -= 4;
		return ((rand() % 51) + 200); // Returns a random value from 200-250.
	}
	else if (action == "Thunder")
	{
		cout << "You cast Thunder!\n";
		magicPoints -= 5;
		return ((rand() % 151) + 350); // Returns a random value from 350-500.
	}
	else if (action == "Potion")
	{
		cout << "You used a potion!\n5000HP restored!\n";
		healthPoints += 5000;
		if (healthPoints > 10000)
		{
			healthPoints = 10000;
		} // Health cannot be greater than 10,000.
		numberOfPotions--;
		return 0;
	}
	else if (action == "Ether")
	{
		cout << "You used a ether!\n25MP restored!\n";
		magicPoints += 25;
		if (magicPoints > 50)
		{
			magicPoints = 50;
		} // Magic cannot be greater than 50.
		numberOfEthers--;
		return 0;
	}
	else if (action == "BottleRocket")
	{
		cout << "You set off the Bottle Rocket!\nEnemy took massive damage!\n";
		numberOfBottleRockets--;
		return 1000; // Bottle Rockets deal a flat 1000 damage, more than most attacks.
	}
	else
	{
		cout << "Action Error\n"; // Code should ideally never run.
		return 0;
	}
}