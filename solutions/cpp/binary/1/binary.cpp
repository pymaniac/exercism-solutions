#include "binary.h"

namespace binary {

// TODO: add your solution here
unsigned int convert(const std::string &inp) {
    unsigned int ans = 0;
    unsigned int cnt = 1;
    for(auto it = inp.rbegin(); it != inp.rend(); it++, cnt *= 2) {
        int v = *it - '0';
        if (v < 0 || v > 1) return 0;
        ans += static_cast<unsigned int>(v) * cnt;
    }
    return ans;
}

}  // namespace binary
