#include "Game.h"

Game::Game()
{
	inBattle = true;
	enemiesDefeated = 0;
	dragonDefeated = false;
}

Game::~Game()
{
	delete enemy;
	enemy = NULL;
}

void Game::spawnEnemy(short type)
{
	enemy = new Enemy(type);
	cout << "A " << enemy->getName() << " has appeared!\n";
}