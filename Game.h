#pragma once
#include "Player.h"
#include "Dragon.h"

class Game
{
public:
	Player player; // Class where all the player's stats are stored.
	Enemy* enemy; // Pointer which points to the current enemy. Points to a new enemy when the current enemy is defeated.
	Dragon dragon; // Class where the dragon's stats are stored.
	bool inBattle; // boolean which sets up the gameplay loop. Game continues until this is set to false.
	bool inDragonBattle; // boolean which sets up the second gameplay loop. If this is false, the fight ends.
	short enemiesDefeated; // increases with every defeated enemy. Dragon will spawn after 10 enemies have been defeated.
	bool dragonDefeated; // becomes true when the dragon is defeated. Determines whether a Victory or Game Over screen loads when the gameplay loop is exited.
	Game();
	~Game();
	void createEnemy(short type); // spawns a new Enemy based on the short passed through.
	void spawnEnemy();
};