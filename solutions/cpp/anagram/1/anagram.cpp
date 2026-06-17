#include "anagram.h"

namespace anagram {

// TODO: add your solution here
std::unordered_set<std::string> anagram::matches(std::vector<std::string> possible_matches) {
    std::unordered_set<std::string> ans;
    for(const auto &word: possible_matches) {
        if (word.size() != _original_string.size()) continue;
        std::array<int, 26> cnt = {};
        for(auto c: word) {
            cnt[std::tolower(c) - 'a']++;
        }
        if (cnt != _cnt) continue;
        auto isEqual = std::equal(word.begin(), word.end(), _original_string.begin(), [](unsigned char c1, unsigned char c2) {return std::tolower(c1) == std::tolower(c2);});
        if (!isEqual) ans.emplace(word);
    }
    return ans;
}
}  // namespace anagram
