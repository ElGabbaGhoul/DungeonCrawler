//
// Created by Scooter on 4/18/2024.
//

#include "RNG.h"
#include <ctime>
#include <cstdlib>

int randomNumberGenerator(){
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
}
