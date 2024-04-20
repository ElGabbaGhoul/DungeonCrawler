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
            dungeon[i][j] = '_';
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
    for (int i=0; i < 1; i++){
        genRandCoords(dungeon, eLoc, size, 'E');
    }
    // Place player
    for (int i=0; i < 1; i++){
        genRandCoords(dungeon, pLoc, size, 'P');
    }
}

void displayDungeon(char dungeon[][SIZE], int size){

    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            std::cout << dungeon[x][y];
        }
        std::cout << std::endl;
    }
}

//void getMove(char dungeon[][SIZE], int size, int bombs, int gold, int exit, int player){
//    //        ◦ pass in the current player location and empty new player location, both as 2-element arrays.
//        // Not sure how to do this?
//    //        ◦ get a move from the user and validate it.
//    char playerMove;
//
//    std::cout << "Player, where would you like to move? (W, A, S, D for up, left, down, right): " << std::endl;
//    std::cin >> playerMove;
//
//    if (!std::cin.fail()){
//        if (playerMove == 'W' || playerMove == 'w'){
//            // update so player moves up a square
//        } else if (playerMove == 'A' || playerMove == 'a'){
//            // update so player moves left a square
//        } else if (playerMove == 'S' || playerMove == 's'){
//            // update down square
//        } else if (playerMove == 'D' || playerMove == 'd'){
//            // update right square
//        } else {
//            // invalid input, choose correct character
//        }
//    } else {
//        std::cin.ignore(500, '\n');
//        std::cin.clear();
//        std::cout << "Invalid input, where would you like to move? (W, A, S, D for up, left, down, right): "
//                  << std::endl;
//    }
//    //            ▪ legal move.
//    //            ▪ valid location inside the dungeon.
//    //        ◦ does not update the dungeon.
//    //        ◦ pass back the new player location using the parameter.
//    //        ◦ no return values.
//}

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