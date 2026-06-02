#pragma once

#include <string>
//#include <iostream>

namespace trinary {

// TODO: add your solution here
inline int to_decimal(const std::string trinary) {
    int ans = 0, v = 1;
    for(auto it = trinary.rbegin(); it != trinary.rend(); it++, v *= 3) {
        if (*it >'2' || *it < '0') return 0;
        ans += (*it - '0') * v;
        //std::cout << *it << " v=" << v << " ans=" << ans << std::endl;
    }
    return ans;
}
}  // namespace trinary
