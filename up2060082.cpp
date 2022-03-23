// up2060082.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
    string currentAction; // player's current action
    srand(time(NULL)); // sets a new random seed every time the game is loaded.
    Game theGame;
    theGame.spawnEnemy(0); // spawns first enemy, a slime
    while (theGame.inBattle)
    {
        cout << "Player health: " << theGame.player.getHealth() << "           Player Magic: " << theGame.player.getMagic() << endl
            << "Enemy health: " << theGame.enemy->getHealth() << endl << "Enter a command: "; // Displays player health, magic and enemy health
        cin >> currentAction;
        theGame.enemy->takeDamage(theGame.player.getAttackDamage(currentAction), currentAction); // Reduces enemy health
        theGame.player.takeDamage(theGame.enemy->getAttackDamage()); // Reduces player health
        cout << endl;
        if (theGame.player.getHealth() <= 0)
        {
            theGame.inBattle = false;
            break;
        } // Game ends if the player reaches 0 health
        if (theGame.enemy->getHealth() <= 0)
        {
            theGame.enemiesDefeated++;
            switch (theGame.enemiesDefeated)
            {
            case 1:
                theGame.spawnEnemy(1); // spawns a puppet
                break;
            case 2:
                theGame.spawnEnemy(rand() % 2); // spawns either a slime or a puppet
                break;
            case 3:
                theGame.spawnEnemy(2); // spawns a witch
                break;
            case 4:
            case 5:
                theGame.spawnEnemy(rand() % 3); // spawns either a slime, a puppet or a witch
                break;
            case 6:
                theGame.spawnEnemy(3); // spawns a mech
                break;
            case 7:
            case 8:
            case 9:
                theGame.spawnEnemy(rand() % 4); // spawns either a slime, a puppet, a witch or a mech
                break;
            case 10:
                // spawn Dragon (NOT YET IMPLEMENTED)
                break;
            case 11:
                theGame.inBattle = false;
                theGame.dragonDefeated = true;
                break; // Game ends if the dragon is defeated
            default:
                cout << "Spawning Error\n";
                break;
            }
        }
    }
    if (theGame.dragonDefeated)
    {
        cout << "\nVICTORY\n\n";
    }
    else
    {
        cout << "\nGAME OVER\n\n";
    }
}