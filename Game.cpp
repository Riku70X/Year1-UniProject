#include "Game.h"

Game::Game()
{
	enemy = new Enemy;
	inBattle = true;
	enemiesDefeated = 0;
	dragonDefeated = false;
}

Game::~Game()
{
	delete enemy;
	enemy = NULL;
}

void Game::createEnemy(short type)
{
	if (type == 4)
	{
		enemy = new Dragon();
		cout << "The Great Dragon has appeared!!!\n";
	}
	else
	{
		enemy = new Enemy(type);
		cout << "A " << enemy->getName() << " has appeared!\n";
	}
}

void Game::spawnEnemy()
{
    enemiesDefeated = 10;//theGame.enemiesDefeated++;
    switch (enemiesDefeated)
    {
    case 1:
        createEnemy(1); // spawns a puppet
        break;
    case 2:
        createEnemy(rand() % 2); // spawns either a slime or a puppet
        break;
    case 3:
        createEnemy(2); // spawns a witch
        break;
    case 4:
    case 5:
        createEnemy(rand() % 3); // spawns either a slime, a puppet or a witch
        break;
    case 6:
        createEnemy(3); // spawns a mech
        break;
    case 7:
    case 8:
    case 9:
        createEnemy(rand() % 4); // spawns either a slime, a puppet, a witch or a mech
        break;
    case 10:
        createEnemy(4); // spawns the Dragon 
        break;
    case 11:
        inBattle = false;
        dragonDefeated = true;
        break; // Game ends if the dragon is defeated
    default:
        cout << "Spawning Error\n";
        break;
    }
}