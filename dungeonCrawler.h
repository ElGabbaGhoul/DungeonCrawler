//
// Created by Scooter on 4/18/2024.
//

#ifndef DUNGEONCRAWLER_DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_DUNGEONCRAWLER_H

const int SIZE = 5;
const int BOMBS = 5;
const int GOLD = 2;
const int EXIT = 1;


void createDungeon(char dungeon[][SIZE], int SIZE, int BOMBS, int GOLD, int EXIT);
void displayDungeon(char dungeon[][SIZE], int SIZE);

#endif //DUNGEONCRAWLER_DUNGEONCRAWLER_H
