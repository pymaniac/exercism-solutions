#include "grains.h"
#include <stdexcept>
#include <cmath>

namespace grains {

// TODO: add your solution here
long double square(uint8_t s) {
    if (s > 64) { throw std::domain_error("Invalid");}
    return std::pow(2LL, s-1);
}
    
long double total(void) {
    return square(64)*2 - 1;
}
    
}  // namespace grains
