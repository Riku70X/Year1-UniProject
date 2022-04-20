// up2060082.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"
#include <windows.h>

void ClearScreen(); // ClearScreen function prototype. Function taken from https://www.cplusplus.com/articles/4z18T05o/
bool isValid(string action);

int main()
{
    srand(time(NULL)); // sets a new random seed every time the game is loaded.
    string currentAction; // player's current action
    Game theGame;
    theGame.createEnemy(0); // spawns first enemy, a slime
    while (theGame.inBattle)
    {
        cout << "Player health: " << theGame.player.getHealth() << "           Player Magic: " << theGame.player.getMagic() << endl
            << "Enemy health: " << theGame.enemy->getHealth() << endl << "Enter a command: "; // Displays player health, magic and enemy health
        cin >> currentAction;
        ClearScreen(); // clears all text from the screen
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
        cout << "Player health: " << theGame.player.getHealth() << "           Player Magic: " << theGame.player.getMagic() << endl
            << "Dragon health: " << theGame.dragon.getHealth() << endl << "Enter a command: "; // Displays player health, magic and dragon health
        cin >> currentAction;
        ClearScreen(); // clears all text from the screen
        theGame.dragon.takeDamage(theGame.player.getAttackDamage(currentAction), currentAction); // Reduces dragon health
        theGame.player.takeDamage(theGame.dragon.getAttackDamage()); // Reduces player health
        cout << endl;
        if (theGame.player.getHealth() <= 0)
        {
            theGame.inDragonBattle = false;
            break;
        } // Game ends if the player reaches 0 health
        if (theGame.enemy->getHealth() <= 0)
        {
            theGame.spawnEnemy();
        } // Spawns a new enemy if the current enemy reaches 0 health
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

bool isValid(string action)
{
    string validActions[8] = { "strike", "fire", "blizzard", "thunder", "potion", "ether", "bottlerocket", "quit" };
    for (int x = 0; x < 8; x++)
    {
        if (action == validActions[x])
        {
            return true;
            break;
        }
    }
    return false;
}