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

    char dungeon[SIZE][SIZE];
    int bLoc[2];
    int gLoc[2];
    int eLoc[2];
    int pLoc[2];

    createDungeon(dungeon, SIZE, BOMBS, GOLD, EXIT, PLAYER);
    displayDungeon(dungeon, SIZE);

    // Create Dungeon -- Initialize a new dungeon
    // Display Dungeon -- Displays the dungeon

    // Get move -- Gets and validates move, WASD = W L D R
    // Update Dungeon -- updates dungeon for the next cycle

    // CheckMove -- Sees if the move is onto bomb, gold, or exit
    // PlayAgain -- Ask if you want to play again


    return 0;
}
