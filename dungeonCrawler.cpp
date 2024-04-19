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
    for (int p = 0; p < player; p++){
        int x = randomNumberGenerator(0, size-1);

        if (dungeon[x][0] == '_'){
            dungeon[x][0] = 'P';
        } else {
            p--;
        }
    }
    // pass back player starting location via the player location parameter.
        // does this do that?

    // Place exit randomly in bottom row
    for (int e = 0; e < exit; e++){
        int x = randomNumberGenerator(0, size-1);

        if(dungeon[x][size-1] == '_'){
            dungeon[x][size-1] = 'E';
        } else {
            e--;
        }
    }

    // Place gold randomly
    for (int g = 0; g < gold; g++){
        int x = randomNumberGenerator(0, size-1);
        int y = randomNumberGenerator(0, size-1);

        if (dungeon[x][y] == '_'){
            dungeon[x][y] = 'G';
        } else {
            g--;
        }
    }
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