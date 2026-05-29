#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {

// TODO: add your solution here
int steps(int num) {
    if (num <= 0) {
        throw std::domain_error("yoo hoo");
    }

    int steps = 0;
    for(;num > 1; steps++) {
        if (num & 1) {
            num *= 3;
            num++;
        } else {
            num >>= 1;
        }
    }

    return steps;
}
}  // namespace collatz_conjecture
