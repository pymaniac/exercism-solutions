#include "etl.h"

#include <cctype>

namespace etl {

// TODO: add your solution here
std::map<char, int> transform(const std::map<int, std::vector<char>> & old) {
    std::map<char, int> ans;
    for(const auto &[v, chars]: old) {
        for(const auto c: chars) {
            ans.emplace(std::tolower(c), v);  
        }
    }

    return ans;
}
}  // namespace etl
