//
// Created by Scooter on 4/18/2024.
//

#include "RNG.h"
#include <ctime>
#include <cstdlib>

int randomNumberGenerator(int low, int high){
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    return rand() % (high - low + 1) + low;
}
