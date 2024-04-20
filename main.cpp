/*
Lab 3
Name: Scott "Marble" Nideffer
Date: 04/19/2024
IDE: Clion
Version: 1.0
Description: A single-player dungeon crawler game. Pick up gold, avoid bombs, find the exit!
*/

#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"


int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    char dungeon[SIZE][SIZE];
    char itemChar = '_';
    int bLoc[2], gLoc[2], eLoc[2], pLoc[2], pLocNew[2];




    createDungeon(dungeon, bLoc, gLoc, eLoc, pLoc, SIZE, BOMBS, GOLD, itemChar);
    displayDungeon(dungeon, SIZE);
    printPlayerLocation(pLoc);
    getMove(dungeon, pLoc, pLocNew);

//    getMove();

    // Create Dungeon -- Initialize a new dungeon
    // Display Dungeon -- Displays the dungeon

    // Get move -- Gets and validates move, WASD = W L D R
    // Update Dungeon -- updates dungeon for the next cycle

    // CheckMove -- Sees if the move is onto bomb, gold, or exit
    // PlayAgain -- Ask if you want to play again


    return 0;
}
