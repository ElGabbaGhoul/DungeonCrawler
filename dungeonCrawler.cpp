//
// Created by Scooter on 4/18/2024.
//

#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"



void createDungeon(char dungeon[][SIZE], int size, int bombs, int gold, int exit){
//        ◦ pass in the dungeon,
    //        the number of bombs spaces,
    //        number of gold spaces
    //        empty player location as a 2-element* array.
        //  * A 2-element array is a single dimension array example:
        //  loc[0] = x; loc[1] = y;

    // clear the dungeon
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            dungeon[i][j] = '_';
        }
    }
//        ◦ randomly place that many bombs and gold in the dungeon in empty locations
//        ◦ randomly place the player and exit, each in an empty location.
//        ◦ make sure that each item placed is in a separate location.
//        ◦ pass back player starting location via the player location parameter.
//        ◦ no return values.
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

