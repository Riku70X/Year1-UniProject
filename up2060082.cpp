// up2060082.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include <windows.h>
const int NUM_OF_VALID_INPUTS = 38;

void ClearScreen(); // ClearScreen function prototype. Function taken from https://www.cplusplus.com/articles/4z18T05o/
bool isValid(string &action, short mp, short potions, short ethers, short bottlerockets, string &message); // Takes a string and several limited resources as input, and returns true if it is a valid command.

int main()
{
    srand(time(NULL)); // sets a new random seed every time the game is loaded.
    string currentAction; // player's current action
    string message = ""; // 
    Game theGame;
    theGame.createEnemy(0); // spawns first enemy, a slime
    while (theGame.inBattle)
    {
        do {
            cout << "Player health: " << theGame.player.getHealth() << "           Player Magic: " << theGame.player.getMagic() << endl
                << "Enemy health: " << theGame.enemy->getHealth() << endl << message << endl << "Enter a command: "; // Displays player health, magic and enemy health
            cin >> currentAction;
            ClearScreen(); // clears all text from the screen
        } while (!isValid(currentAction, theGame.player.getMagic(), theGame.player.getPotionCount(), theGame.player.getEtherCount(), theGame.player.getBottleRocketCount(), message));
        // The enemy will not attack until the player enters a valid command
        if (currentAction == "Quit")
        {
            theGame.inBattle = false;
            ClearScreen();
            break; // The game immediately closes if the player wants to quit
        }
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
            theGame.spawnEnemy();
        } // Spawns a new enemy if the current enemy reaches 0 health
    }
    while (theGame.inDragonBattle)
    {
        do {
            cout << "Player health: " << theGame.player.getHealth() << "           Player Magic: " << theGame.player.getMagic() << endl
                << "Dragon health: " << theGame.dragon.getHealth() << endl << message << endl << "Enter a command: "; // Displays player health, magic and dragon health
            cin >> currentAction;
            ClearScreen(); // clears all text from the screen
        } while (!isValid(currentAction, theGame.player.getMagic(), theGame.player.getPotionCount(), theGame.player.getEtherCount(), theGame.player.getBottleRocketCount(), message));
        // The dragon will not attack until the player enters a valid command
        if (currentAction == "Quit")
        {
            theGame.inDragonBattle = false;
            ClearScreen();
            break; // The game immediately closes if the player wants to quit
        }
        theGame.dragon.takeDamage(theGame.player.getAttackDamage(currentAction), currentAction); // Reduces dragon health
        theGame.player.takeDamage(theGame.dragon.getAttackDamage()); // Reduces player health
        cout << endl;
        if (theGame.player.getHealth() <= 0)
        {
            theGame.inDragonBattle = false;
            break;
        } // Game ends if the player reaches 0 health
        if (theGame.dragon.getHealth() <= 0)
        { 
            theGame.inDragonBattle = false;
            theGame.dragonDefeated = true;
        } // Ends the game if the dragon reaches 0 health
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

void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

bool isValid(string &action, short mp, short potions, short ethers, short bottlerockets, string &message)
{
    string validActions[NUM_OF_VALID_INPUTS] = {"Quit", "strike", "Strike", "STRIKE", "s", "S", "fire", "Fire", "FIRE", "f", "F", "blizzard", "Blizzard", "b", "B", "BLIZZARD", "thunder", "Thunder", 
        "THUNDER", "t", "T", "potion", "Potion", "POTION", "p", "P", "ether", "Ether", "ETHER", "e", "E", "bottlerocket", "Bottlerocket", "BottleRocket", "bottleRocket", "BOTTLEROCKET", "b", "B", };
    for (int x = 0; x < NUM_OF_VALID_INPUTS; x++)
    {
        if (action == validActions[x])
        {
            switch (x)
            {
            case 0:
                return true;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                action = "Strike"; // These lines of code generalise the functions. So, if the player enters "s", "S", "strike" or "STRIKE", the game reads it as "Strike"
                return true;
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                if (mp < 3)
                {
                    message = "Not enough mp";
                    return false;
                    break;
                }
                else
                {
                    action = "Fire";
                    return true;
                    break;
                }
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                if (mp < 4)
                {
                    message = "Not enough mp";
                    return false;
                    break;
                }
                else
                {
                    action = "Blizzard";
                    return true;
                    break;
                }
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                if (mp < 5)
                {
                    message = "Not enough mp";
                    return false;
                    break;
                }
                else
                {
                    action = "Thunder";
                    return true;
                    break;
                }
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
                if (potions == 0)
                {
                    message = "No potions remaining";
                    return false;
                    break;
                }
                else
                {
                    action = "Potion";
                    return true;
                    break;
                }
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
                if (ethers == 0)
                {
                    message = "No ethers remaining";
                    return false;
                    break;
                }
                else
                {
                    action = "Ether";
                    return true;
                    break;
                }
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
                if (bottlerockets == 0)
                {
                    message = "No bottle rockets remaining";
                    return false;
                    break;
                }
                else
                {
                    action = "BottleRocket";
                    return true;
                    break;
                }
            default:
                cout << "VALIDATION ERROR"; // Code should never run ideally
                return false;
                break;
            }
        }
    }
    message = "Invalid Action";
    return false;
}