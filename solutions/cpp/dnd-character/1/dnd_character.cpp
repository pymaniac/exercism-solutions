#include "dnd_character.h"

#include <cmath>
#include <random>

namespace dnd_character {

// TODO: add your solution here
int modifier(int constitution) {
    return std::floor((constitution - 10)/2.0);
}

int ability() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 6);

    int sum = 0;
    int m = 7;
    for(int i = 0; i < 4; i++) {
        int roll = distrib(gen);
        m = std::min(roll, m);
        sum += roll;
    }
    sum -= m;
    return sum;
}
}  // namespace dnd_character
