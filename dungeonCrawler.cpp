//
// Created by Scooter on 4/18/2024.
//

#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"



void createDungeon(char dungeon[][SIZE], int size, int bombs, int gold, int exit, int player){
//        parameters as a 2-element* array.
    //  * A 2-element array is a single dimension array example:
    //  loc[0] = x; loc[1] = y;
// Huh

    // clear the dungeon
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            dungeon[i][j] = '_';
        }
    }

    // Place bombs
    for (int b = 0; b < bombs; b++){
        int x = randomNumberGenerator(0, size-1);
        int y = randomNumberGenerator(0, size-1);

        if (dungeon[x][y] == '_'){
            dungeon[x][y] = 'B';
        } else {
            b--;
        }
    }

    // Place player randomly in top row
    for (int p = 0; p < PLAYER; p++){
        int x = randomNumberGenerator(0, size-1);

        if (dungeon[x][0] == '_'){
            dungeon[x][0] = 'P';
        } else {
            p--;
        }
    }

    // Place exit randomly in bottom row
    for (int e = 0; e < EXIT; e++){
        int x = randomNumberGenerator(0, size-1);

        if(dungeon[x][size-1] == '_'){
            dungeon[x][size-1] = 'E';
        } else {
            e--;
        }
    }

    // Place gold randomly
    for (int g = 0; g < GOLD; g++){
        int x = randomNumberGenerator(0, size-1);
        int y = randomNumberGenerator(0, size-1);

        if (dungeon[x][y] == '_'){
            dungeon[x][y] = 'G';
        } else {
            g--;
        }
    }
//        ◦ pass back player starting location via the player location parameter.
// Huh
}

void displayDungeon(char dungeon[][SIZE], int size){
//        ◦ pass in the dungeon.
//        ◦ display the dungeon.
for (int y = 0; y < size; y++){
    for (int x = 0; x < size; x++){
        std::cout << dungeon[x][y];
    }
    std::cout << std::endl;
}
//        ◦ no return values.
}


