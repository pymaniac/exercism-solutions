#include "triangle.h"
#include <stdexcept>

namespace triangle {

flavor kind(float a, float b, float c) {
    if (a && a == b && b == c) {
        return flavor::equilateral;
    }

    if (((a == b) && (2*a > c)) ||
        ((a == c) && 2*a > b) ||
        ((b == c) && 2*b > a)) {
        return flavor::isosceles;    
    }

    if (a == b || a == c || b == c) {
        throw std::domain_error("isosceles triangle - inequality violation");
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::domain_error("invalid triangle");
    }

    return flavor::scalene;
}
        
}  // namespace triangle
