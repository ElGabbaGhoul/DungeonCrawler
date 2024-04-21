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


int main() {
    // seed random number generator
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    char dungeon[SIZE][SIZE];
    int bLoc[2], gLoc[2], eLoc[2], pLoc[2], pLocNew[2];
    char itemChar = '_';

    int goldSum = 0;
    bool isPlaying = true;
    bool replay;

    // initialize and display starter dungeon
    do {
        createDungeon(dungeon, bLoc, gLoc, eLoc, pLoc, SIZE, BOMBS, GOLD, itemChar);
        displayDungeon(dungeon, SIZE);
        do {
            // Show player location in console
            printPlayerLocation(pLoc);
            // cin valid move from user
            getMove(pLoc, pLocNew, SIZE);
            // check if move was to a bomb square
            isPlaying = checkMove(dungeon, pLocNew, goldSum, isPlaying);
            // update dungeon
            updateDungeon(dungeon, pLoc, pLocNew);
            // show updated dungeon
            displayDungeon(dungeon, SIZE);
        // if bomb or exit reached, stop
        } while (isPlaying);
        // check if want to replay
        replay = playAgain();
    } while (replay);
return 0;
}
