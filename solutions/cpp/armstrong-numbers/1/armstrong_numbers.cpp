#include "armstrong_numbers.h"

#include <string>
#include <cmath>

namespace armstrong_numbers {

// TODO: add your solution here
bool is_armstrong_number(int x) {
    std::string x_str = std::to_string(x);
    int x_len = static_cast<int>(x_str.size());

    int v = 0;
    for(const auto &c: x_str) {
        v += std::pow((c-'0'), x_len);
    }
    return v == x;
}
    
}  // namespace armstrong_numbers
