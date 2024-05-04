//
// Created by Scott Nideffer on 5/4/24.
//

#include "namingThings.h"
#include "RNG.h"

std::string getCharacterName() {
    std::string player;
    bool validIn = false;
    std::cout << "Greetings traveler, what is your name?" << std::endl;
    std::cin >> player;

    while (!validIn) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(40000, '\n');
            std::cout << "Please enter a name with at least 3 characters." << std::endl;
        } else {
            std::cout << "Greetings, " << player << "." << std::endl;
            validIn = true;
        }
    }
    return player;
}
void displayDungeonName() {

    std::string prefixes[] = {"Howling", "Abandoned", "Treacherous"};

    std::string nouns[] = {"Prison", "Market", "Hospital"};

    std::string suffixes[] = {"Crazed", "Undead", "Bloodthirsty"};

    std::string enemies[] = {"Gourds", "Zombies", "Penguins"};

    std::cout << prefixes[randRange(0,2)] << " " << nouns[randRange(0,2)]
    << " of the " << suffixes[randRange(0,2)] << " " << enemies[randRange(0,2)] << "!"
    << std::endl;
}
