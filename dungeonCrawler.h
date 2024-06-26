//
// Created by Scooter on 4/18/2024.
//

#ifndef DUNGEONCRAWLER_DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_DUNGEONCRAWLER_H
#import <iostream>


const int SIZE = 5;
const int BOMBS = 3;
const int GOLD = 2;

void createDungeon(char dungeon[][SIZE], int bLoc[2], int gLoc[2], int eLoc[2], int pLoc[2], int SIZE, int bombs, int gold, char itemChar);
void displayDungeon(char dungeon[][SIZE], int size);
void printPlayerLocation(int pLoc[], std::string charName);
void getMove(int pLoc[2], int pLocNew[2], int size, std::string charName);
void updateDungeon(char dungeon[][SIZE], int pLoc[2], int pLocNew[2]);
bool checkMove(char dungeon[][SIZE], int pLocNew[2], int& goldSum, bool& playing, std::string charName);
bool playAgain();

#endif //DUNGEONCRAWLER_DUNGEONCRAWLER_H
