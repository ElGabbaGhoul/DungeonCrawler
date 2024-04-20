//
// Created by Scooter on 4/18/2024.
//

#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"

void createDungeon(char dungeon[][SIZE], int bLoc[2], int gLoc[2], int eLoc[2], int pLoc[2], int size, int bombs, int gold, char itemChar) {
    // Create empty dungeon
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dungeon[i][j] = itemChar;
        }
    }
    // Place bombs
    for (int i=0; i < bombs; i++){
        genRandCoords(dungeon, bLoc, size, 'B');
    }
    // Place gold
    for (int i=0; i < gold; i++){
        genRandCoords(dungeon, gLoc, size, 'G');
    }
    // Place exit
    genRandCoords(dungeon, eLoc, size, 'E');
    // Place player
    genRandCoords(dungeon, pLoc, size, 'P');

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

void getMove(char dungeon[][SIZE], int pLoc[2], int pLocNew[2], int size){
    //        ◦ get a move from the user and validate it.
    char playerMove;

    std::cout << "Player, where would you like to move? (W, A, S, D for up, left, down, right): " << std::endl;
    std::cin >> playerMove;

    if (!std::cin.fail()){
        if (playerMove == 'W' || playerMove == 'w'){
            if (pLoc[1] - 1 >= 0 || pLoc[1] - 1 <= size - 1){
                pLocNew[0] = pLoc[0];
                pLocNew[1] = pLoc[1] - 1;
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        } else if (playerMove == 'A' || playerMove == 'a'){
            if (pLoc[0] - 1 >= 0 || pLoc[0] - 1 <= size - 1){
                pLocNew[0] = pLoc[0] - 1;
                pLocNew[1] = pLoc[1];
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        } else if (playerMove == 'S' || playerMove == 's'){
            if (pLoc[1] + 1 >= 0 || pLoc[1] + 1 <= size - 1){
                pLocNew[0] = pLoc[0];
                pLocNew[1] = pLoc[1] + 1;
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        } else if (playerMove == 'D' || playerMove == 'd'){
            if (pLoc[0] + 1 >= 0 || pLoc[0] + 1 <= size - 1){
                pLocNew[0] = pLoc[0] + 1;
                pLocNew[1] = pLoc[1];
                std::cout << "New position: " << pLocNew[0] + 1 << ", " << pLocNew[1] + 1 << "." << std::endl;
            } else {
                std::cout << "Sorry, out of bounds." << std::endl;
            }
        } else {
            std::cin.ignore(500, '\n');
            std::cin.clear();
            std::cout << "Invalid move, where would you like to move? (W, A, S, D for up, left, down, right): "
                      << std::endl;
        }
    } else {
        std::cin.ignore(500, '\n');
        std::cin.clear();
        std::cout << "Invalid input, where would you like to move? (W, A, S, D for up, left, down, right): "
                  << std::endl;
    }
std::cout << "Player move: " << (char)toupper(playerMove) << " successfully recorded." << std::endl;
}

void updateDungeon(char dungeon[][SIZE], int pLoc[2], int pLocNew[2]){
    // pass dungeon, pLoc, pLocNew
    // place new marker at new location, delete old player marker
    int xOld = pLoc[0];
    int yOld = pLoc[1];

    int x = pLocNew[0];
    int y = pLocNew[1];

    if (dungeon[x][y] == '_'){
        dungeon[x][y] = 'P';
        dungeon[xOld][yOld] = '_';

    }
}


//bool playAgain() {
//    char playAgain;
//    std::cout << "Would you like to play again? (Y/N)" << std::endl;
//    std::cin >> playAgain;
//    if (!std::cin.fail()) {
//        if (playAgain == 'Y' || playAgain == 'y') {
////            currentPlayer = 1;
////            moveLetter = 'X';
//            return true;
//        } else if (playAgain == 'N' || playAgain == 'n') {
//            std::cout << "Thank you for playing!" << std::endl;
//            return false;
//        } else {
//            std::cout << "Invalid input, please enter Y or N" << std::endl;
//        };
//    } else {
//        std::cin.clear();
//        std::cin.ignore(500, '\n');
//        std::cout << "Invalid input, please enter a single character, Y or N"
//                  << std::endl;
//    }
//    return false;
//}