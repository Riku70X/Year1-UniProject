#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Player player; // Class where all the player's stats are stored
	Enemy* enemy; // Pointer which points to the current enemy. Points to a new enemy when the current enemy is defeated.
	bool inBattle; // boolean which sets up the gameplay loop. Game continues until this is set to false.
	short enemiesDefeated; // increases with every defeated enemy. Dragon will spawn after 10 enemies have been defeated.
	bool dragonDefeated; // becomes true when the dragon is defeated. Determines whether a Victory or Game Over screen loads when the gameplay loop is exited.
	Game();
	~Game();
	void spawnEnemy(short type); // spawns a new Enemy based on the short passed through.
};