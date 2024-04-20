//
// Created by Scooter on 4/18/2024.
//

#ifndef DUNGEONCRAWLER_RNG_H
#define DUNGEONCRAWLER_RNG_H

#include "dungeonCrawler.h"
extern const int SIZE;

void genRandCoords(char dungeon[][SIZE], int coords[2], int SIZE, char itemChar);
int randRange(int low, int high);


#endif //DUNGEONCRAWLER_RNG_H
