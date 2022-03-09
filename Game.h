#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	Player player;
	Enemy* enemy;
	bool inBattle;
	short enemiesDefeated;
	bool dragonDefeated;
	Game();
	~Game();
	void spawnEnemy(short type);
};