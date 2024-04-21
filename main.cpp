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
// #include "RNG.h"


int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    int goldSum = 0;
    bool isAlive;
    bool notExit;
    char dungeon[SIZE][SIZE];
    char itemChar = '_';
    int bLoc[2], gLoc[2], eLoc[2], pLoc[2], pLocNew[2];
    bool replay;

    do {
        createDungeon(dungeon, bLoc, gLoc, eLoc, pLoc, SIZE, BOMBS, GOLD, itemChar);
        displayDungeon(dungeon, SIZE);
        do {
            printPlayerLocation(pLoc);
            getMove(pLoc, pLocNew, SIZE);
            isAlive = checkMove(dungeon, pLocNew, itemChar, goldSum, isAlive, notExit);
            updateDungeon(dungeon, pLoc, pLocNew, goldSum, isAlive, notExit);
            displayDungeon(dungeon, SIZE);
        } while (isAlive && notExit);
        replay = playAgain();
    } while (replay);
return 0;
}
