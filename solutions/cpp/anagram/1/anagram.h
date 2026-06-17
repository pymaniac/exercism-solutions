#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include <utility>
#include <array>

namespace anagram {

// TODO: add your solution here
class anagram {
    private:
    std::string _original_string;
    std::array<int, 26> _cnt = {};
    
    public:
    anagram(std::string str) : _original_string(std::move(str)) {
        for(auto c: _original_string) {
            _cnt[std::tolower(c)-'a']++;
        }
    }
    std::unordered_set<std::string> matches(std::vector<std::string> possible_matches);
};
    
}  // namespace anagram
