#include "hexadecimal.h"

namespace hexadecimal {

// TODO: add your solution here
unsigned int convert(const std::string &hexi) {
    unsigned int m = 1;
    unsigned int ans = 0;
    for(auto it = hexi.rbegin(); it != hexi.rend(); it++, m *= 16) {
        int v = *it - '0';
        if (v < 0 || v > 9) {
            v = 10 + *it - 'a';
            if (v < 10 || v > 15) return 0;
        }
        ans += v * m;
    }
    return ans;
}
}  // namespace hexadecimal
