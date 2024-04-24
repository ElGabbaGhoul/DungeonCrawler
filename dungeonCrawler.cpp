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
    std::cout << "Player is currently at: Col " << pLoc[0] << ", Row " << pLoc[1] << "." << std::endl;
}

void getMove(int pLoc[2], int pLocNew[2], int SIZE){
    char playerMove;
    std::cout << "Player, where would you like to move? (W, A, S, D for up, left, down, right): " << std::endl;
    std::cin >> playerMove;

    if (std::cin.fail()) {
            std::cin.ignore(50000, '\n');
            std::cin.clear();
            std::cout << "Invalid move, where would you like to move? (W, A, S, D for up, left, down, right): "
                      << std::endl;
        } else {
            playerMove = (char)toupper(playerMove);
            if (playerMove == 'W') {
                if (pLoc[1] - 1 >= 0){
                        pLocNew[0] = pLoc[0];
                        pLocNew[1] = pLoc[1] - 1;
                    } else {
                        std::cout << "Out of bounds. Try again." << std::endl;
                    }
            } else if (playerMove == 'A') {
                if (pLoc[0] - 1 >= 0){
                        pLocNew[0] = pLoc[0] - 1;
                        pLocNew[1] = pLoc[1];
                } else {
                    std::cout << "Out of bounds. Try again." << std::endl;
                }
            } else if (playerMove == 'S') {
                if (pLoc[1] + 1 <= SIZE - 1){
                    pLocNew[0] = pLoc[0];
                    pLocNew[1] = pLoc[1] + 1;
                } else {
                    std::cout << "Out of bounds. Try again." << std::endl;
                }
            } else if (playerMove == 'D') {
                if (pLoc[0] + 1 <= SIZE - 1){
                    pLocNew[0] = pLoc[0] + 1;
                    pLocNew[1] = pLoc[1];
                } else {
                    std::cout << "Out of bounds. Try again." << std::endl;
                }
            } else {
                std::cin.ignore(50000, '\n');
                std::cin.clear();
                std::cout << "Invalid move, where would you like to move? (W, A, S, D for up, left, down, right): "
                      << std::endl;
                pLocNew[0] = pLoc[0];
                pLocNew[1] = pLoc[1];
            }
        }
}

void updateDungeon(char dungeon[][SIZE], int pLoc[2], int pLocNew[2]){
    // pass dungeon, pLoc, pLocNew
    // place new marker at new location, delete old player marker
    if (pLoc[0] == pLocNew[0] && pLoc[1] == pLocNew[1]) {
        int x = pLoc[0];
        int y = pLoc[1];

        dungeon[x][y] = 'P';
    } else {
        int xOld = pLoc[0];
        int yOld = pLoc[1];

        int x = pLocNew[0];
        int y = pLocNew[1];

        dungeon[x][y] = 'P';
        dungeon[xOld][yOld] = '_';
        pLoc[0] = x;
        pLoc[1] = y;
    }
}

bool checkMove(char dungeon[][SIZE], int pLocNew[2], int& goldSum, bool& playing){
    // If pLocNew is onto space that is B, G, or E
    // Return true and update accordingly
    int x = pLocNew[0];
    int y = pLocNew[1];
    playing = true;

    // new move is bomb, lose
    if (dungeon[x][y] == 'B'){
        std::cout << "You hit a bomb. Game over." << std::endl;
        goldSum = 0;
        playing = false;
        return playing;
    }

    // new move is gold
    if (dungeon[x][y] == 'G'){
        // add gold
        goldSum += 5;
        std::cout << "You picked up a pile of gold! +5 gold." << std::endl;
        std::cout << "Total gold: " << goldSum << "." << std::endl;
        return playing;
    }

    // new move is exit, win
    if (dungeon[x][y] == 'E'){
        std::cout << "You reached the exit!" << std::endl;
        std::cout << "You win!" << std::endl;
        std::cout << "Total gold found: " << goldSum << "g!" << std::endl;
        playing = false;
        return playing;
    }
    return playing;
}

bool playAgain() {
    char playAgain;

    while (true) {
        std::cout << "Would you like to play again? (Y/N)" << std::endl;
        std::cin >> playAgain;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(500, '\n');
            std::cerr << "Invalid input, please enter a single character, Y or N."
                      << std::endl;
        } else {
            playAgain = char(toupper(playAgain));
            if (playAgain == 'Y' || playAgain == 'N') {
                std::cout << "Thank you for playing!" << std::endl;
                return playAgain == 'Y';
            }
        }
    }
}