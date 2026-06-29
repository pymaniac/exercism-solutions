#include "isogram.h"

#include <array>

namespace isogram {

// TODO: add your solution here
bool is_isogram(const std::string &inp) {
    std::array<int, 26> cnt = {};
    for(const auto &c: inp) {
        if (c == '-' || c == ' ') continue;
        
        auto v = c - 'a';
        if (v < 0) v = c - 'A';
        
        cnt[v]++;
        if (cnt[v] > 1) return false;
    }
    return true;
}
    
}  // namespace isogram
