#include "darts.h"

#include <cmath>

namespace darts {

// TODO: add your solution here
int score(float x, float y) {
    float r = std::sqrt(x*x + y*y);
    if (r > 10.0) return 0;
    if (r > 5.0) return 1;
    if (r > 1.0) return 5;
    return 10;
}
    
}  // namespace darts
