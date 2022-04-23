#include "Game.h"

Game::Game()
{
	enemy = new Enemy; // Gives the pointer a default enemy object, "null". This line is technically redundant, as the code should always replace this with a real enemy as soon as the game begins.
	inBattle = true;
    inDragonBattle = false;
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
	enemy = new Enemy(type); // The Enemy class has an overloaded constructor with a switch case for spawning different enemies based on the integer passed through "type".
	cout << "A " << enemy->getName() << " has appeared!\n"; // Text to tell the player what type of enemy has spawned when an enemy spawns.
}

void Game::spawnEnemy()
{
    enemiesDefeated++; // Enemies spawn only when the previous enemy is killed, so the counter should be incremented.
    switch (enemiesDefeated)
    {
    case 1:
        createEnemy(1); // Spawns a Puppet.
        break;
    case 2:
        createEnemy(rand() % 2); // Spawns either a Slime or a Puppet.
        break;
    case 3:
        createEnemy(2); // Spawns a Witch.
        break;
    case 4:
    case 5:
        createEnemy(rand() % 3); // Spawns either a Slime, a Puppet or a Witch.
        break;
    case 6:
        createEnemy(3); // Spawns a Mech.
        break;
    case 7:
    case 8:
    case 9:
        createEnemy(rand() % 4); // Spawns either a Slime, a Puppet, a Witch or a Mech.
        break;
    case 10:
        inBattle = false; 
        inDragonBattle = true; // Allows the game to move on to the secondary gameplay loop, where the Dragon is fought.
        cout << "The Great Dragon has appeared!!!\n";
        break;
    default:
        cout << "Spawning Error\n"; //Should ideally never run.
        break;
    }
}