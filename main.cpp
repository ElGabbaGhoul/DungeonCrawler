#include <iostream>
#include "dungeonCrawler.h"
#include "RNG.h"


int main() {

    char dungeon[SIZE][SIZE];

    createDungeon(dungeon, SIZE, BOMBS, GOLD, EXIT, PLAYER);
    displayDungeon(dungeon, SIZE);

    // Create Dungeon -- Initialize a new dungeon
    // Display Dungeon -- Displays the dungeon

    // Get move -- Gets and validates move, WASD = W L D R
    // Update Dungeon -- updates dungeon for the next cycle

    // CheckMove -- Sees if the move is onto bomb, gold, or exit
    // PlayAgain -- Ask if you want to play again


    return 0;
}
