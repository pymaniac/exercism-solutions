#pragma once

namespace chicken_coop {

// TODO: add your solution here
inline int positions_to_quantity(unsigned int num) {
    int ans = 0;
    while(num) {
        ans++;
        num &= num-1;
    }
    return ans;
}
}  // namespace chicken_coop
