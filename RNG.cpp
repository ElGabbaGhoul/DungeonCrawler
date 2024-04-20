//
// Created by Scooter on 4/18/2024.
//

#include "RNG.h"
#include <cstdlib>

void genRandCoords(char dungeon[][SIZE], int coords[2], int SIZE, char itemChar) {
    int x, y;
    do {
        x = randRange(0, SIZE - 1);
        y = randRange(0, SIZE - 1);
    } while (dungeon[x][y] != '_');

    dungeon[x][y] = itemChar;
    coords[0] = x;
    coords[1] = y;
}

int randRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}