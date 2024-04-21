//
// Created by Scooter on 4/18/2024.
//

#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"


void createDungeon(char dungeon[][SIZE], int bLoc[2], int gLoc[2], int eLoc[2], int pLoc[2], int SIZE, int bombs, int gold, char itemChar) {
    // Create empty dungeon
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dungeon[i][j] = itemChar;
        }
    }
    // Place bombs
    for (int i=0; i < bombs; i++){
        genRandCoords(dungeon, bLoc, SIZE, 'B');
    }
    // Place gold
    for (int i=0; i < gold; i++){
        genRandCoords(dungeon, gLoc, SIZE, 'G');
    }
    // Place exit
    genRandCoords(dungeon, eLoc, SIZE, 'E');
    // Place player
    genRandCoords(dungeon, pLoc, SIZE, 'P');

    std::cout << "Dungeon Created! Entering..." << std::endl;
}

void displayDungeon(char dungeon[][SIZE], int size){

    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            std::cout << dungeon[x][y];
        }
        std::cout << std::endl;
    }
}

void printPlayerLocation(int pLoc[]){
    std::cout << "Player is currently at: Col " << pLoc[0] + 1 << ", Row " << pLoc[1] + 1 << "." << std::endl;
}

void getMove(int pLoc[2], int pLocNew[2], int SIZE){
    char playerMove;
    // prompt player for wasd move
    std::cout << "Player, where would you like to move? (W, A, S, D for up, left, down, right): " << std::endl;
    std::cin >> playerMove;

    if (!std::cin.fail()){
        // move up
        if (playerMove == 'W' || playerMove == 'w'){
            if (pLoc[1] - 1 >= 0 || pLoc[1] + 1 <= SIZE - 1){
                pLocNew[0] = pLoc[0];
                pLocNew[1] = pLoc[1] - 1;
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        // move left
        } else if (playerMove == 'A' || playerMove == 'a'){
            if (pLoc[0] - 1 >= 0 || pLoc[0] + 1 >= SIZE - 1){
                pLocNew[0] = pLoc[0] - 1;
                pLocNew[1] = pLoc[1];
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        // move down
        } else if (playerMove == 'S' || playerMove == 's'){
            if (pLoc[1] - 1 >=0 || pLoc[1] + 1  <= SIZE - 1){
                pLocNew[0] = pLoc[0];
                pLocNew[1] = pLoc[1] + 1;
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        // move right
        } else if (playerMove == 'D' || playerMove == 'd'){
            if (pLoc[0] - 1 >= 0 || pLoc[0] + 1 <= SIZE - 1){
                pLocNew[0] = pLoc[0] + 1;
                pLocNew[1] = pLoc[1];
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        // wrong input
        } else {
            std::cin.ignore(500, '\n');
            std::cin.clear();
            std::cout << "Invalid move, where would you like to move? (W, A, S, D for up, left, down, right): "
                      << std::endl;
        }
    // not a char
    } else {
        std::cin.ignore(500, '\n');
        std::cin.clear();
        std::cout << "Invalid input, where would you like to move? (W, A, S, D for up, left, down, right): "
                  << std::endl;
    }
// move is output to console
std::cout << "Player move: " << (char)toupper(playerMove) << " successfully recorded." << std::endl;
}

void updateDungeon(char dungeon[][SIZE], int pLoc[2], int pLocNew[2], int& goldSum, bool& isAlive, bool& notExit){
    // pass dungeon, pLoc, pLocNew
    // place new marker at new location, delete old player marker
    int xOld = pLoc[0];
    int yOld = pLoc[1];

    int x = pLocNew[0];
    int y = pLocNew[1];
    // check if new move is empty
    // Something like this, I need to make sure that P can't leave the bounds of the array
    // I think the problem is HERE but it could be somewhere else.
    if ((dungeon[x][y] != '_') && (x - 1 >=0 && x-1 < dungeon.size() && y >=0 && y < dungeon[0].size()) ){
        char itemChar = dungeon[x][y];
        // check if bomb exit or gold
        checkMove(dungeon, pLocNew, itemChar, goldSum, isAlive, notExit);
        // replace old character
        dungeon[x][y] = 'P';
        dungeon[xOld][yOld] = '_';
        pLoc[0] = x;
        pLoc[1] = y;
    } else {
        // replace old character
        dungeon[x][y] = 'P';
        dungeon[xOld][yOld] = '_';
        pLoc[0] = x;
        pLoc[1] = y;
    }
}

bool checkMove(char dungeon[][SIZE], int pLocNew[2], char itemChar, int& goldSum, bool& isAlive, bool& notExit){
    // If pLocNew is onto space that is B, G, or E
    // Return true and update accordingly
    int x = pLocNew[0];
    int y = pLocNew[1];

    // new move is bomb, lose
    if (dungeon[x][y] == itemChar && itemChar == 'B'){
        std::cout << "You hit a bomb. Game over." << std::endl;
        isAlive = false;
        return isAlive;
    // new move is gold
    } else if (dungeon[x][y] == itemChar && itemChar == 'G'){
        // add gold
        goldSum += 5;
        std::cout << "You picked up a pile of gold! +5 gold." << std::endl;
        std::cout << "Total gold: " << goldSum << "." << std::endl;
        return true;
    // new move is exit, win
    } else if (dungeon[x][y] == itemChar && itemChar == 'E'){
        std::cout << "You reached the exit!" << std::endl;
        std::cout << "You win!" << std::endl;
        std::cout << "Total gold found: " << goldSum << "g!" << std::endl;
        notExit = false;
        return notExit;
    }
    return true;
}

bool playAgain() {
    char playAgain;
    std::cout << "Would you like to play again? (Y/N)" << std::endl;
    std::cin >> playAgain;
    if (!std::cin.fail()) {
        if (playAgain == 'Y' || playAgain == 'y') {
            return true;
        } else if (playAgain == 'N' || playAgain == 'n') {
            std::cout << "Thank you for playing!" << std::endl;
            return false;
        } else {
            std::cout << "Invalid input, please enter Y or N" << std::endl;
        };
    } else {
        std::cin.clear();
        std::cin.ignore(500, '\n');
        std::cout << "Invalid input, please enter a single character, Y or N"
                  << std::endl;
    }
    return false;
}