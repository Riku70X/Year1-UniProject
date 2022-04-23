#pragma once
#include "Player.h"
#include "Dragon.h"

class Game
{
public:
	Player player; // Class where all the player's stats are stored.
	Enemy* enemy; // Pointer which points to the current enemy. Points to a new enemy when the current enemy is defeated.
	Dragon dragon; // Class where the dragon's stats are stored.
	bool inBattle; // Boolean which sets up the gameplay loop. Game continues until this is set to false.
	bool inDragonBattle; // Boolean which sets up the secondary gameplay loop. If this is false, the fight ends.
	bool dragonDefeated; // Becomes true when the dragon is defeated. Determines whether a Victory or Game Over screen loads when the gameplay loop is exited.
	Game();
	~Game();
	void createEnemy(short type); // spawns a new Enemy based on the short passed through.
	void spawnEnemy(); // Uses enemiesDefeated to determine what kind of enemy should spawn, then runs createEnemy with an appropriate short passed through. Randomisation occurs here.

private:
	short enemiesDefeated; // Increases with every defeated enemy. Dragon will spawn after 10 enemies have been defeated.
};