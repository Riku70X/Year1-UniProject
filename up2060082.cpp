// up2060082.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"

int main()
{
    srand(time(NULL));
    Player player;
    cout << player.getAttackDamage();
}