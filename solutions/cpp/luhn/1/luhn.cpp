#include "luhn.h"

#include <iostream>

namespace luhn {

// TODO: add your solution here
bool valid(const std::string &txt) {
    if (txt.size() < 2) return false;
    int cnt = 0;
    int num = 0;
    for(auto it = txt.rbegin(); it != txt.rend(); it++) {
        if (std::isspace(*it)) continue;
        cnt++;
        if (!std::isdigit(*it)) return false;
        int digit = *it - '0';
        int dbl = digit<<1;
        if (dbl > 9) dbl -= 9;
        num += ((cnt & 1) == 0) ? dbl : digit;
    }
    std::cout << num << std::endl;
    return (cnt > 1) && (num % 10) == 0;
}
}  // namespace luhn
