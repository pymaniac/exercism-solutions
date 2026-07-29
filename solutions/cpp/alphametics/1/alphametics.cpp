#include "alphametics.h"

#include <array>
#include <algorithm>
#include <vector>
#include <iostream>

namespace alphametics {
static inline void remove_spaces(std::string &s) {
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
}
    
static inline bool split_string(const std::string &input, const std::string &delim, std::string &lhs, std::string &rhs) {
    auto pos = input.find(delim);
    if (pos == std::string::npos) return false;
    
    rhs = input.substr(pos + delim.length());
    lhs = input.substr(0, pos);

    remove_spaces(rhs);
    remove_spaces(lhs);
    return true;
}

static inline long long word_to_int(const std::string &word, [[maybe_unused]] std::array<int, 26> &char_to_int1) {
    long long ans = 0;
    for(const auto &w: word) {
        ans = 10*ans + char_to_int1[w - 'A'];
        //ans++;
    }
    return ans;
}
// TODO: add your solution here
std::optional<std::unordered_map<char, int>> solve(const std::string &input) {
    std::string rhs;
    std::string lhs_u;
    if (!split_string(input, "==", lhs_u, rhs)) return std::nullopt;

    std::string l1, l2;
    std::vector<std::string> lv;

    std::cout << std::endl << "input = " << input << " " << lhs_u << " " << l2 << std::endl;

    while(split_string(lhs_u, "+", l1, l2)) {
        lv.push_back(l1);
        lhs_u = l2;
    }
    if (l1.size()) {
        lv.push_back(lhs_u);
    }

    for(auto l : lv) std::cout << l << " ";
    std::cout << std::endl;

    int noZeroMask = 0;
    int seenCharMask = 0;
    std::string unique_chars;

    auto processWord = [&](const std::string &word) -> void {
        for(const auto &c: word) {
            if (word.empty()) { std::cout << "EMOTRY WORD" << std::endl; continue; }
            int indx = c - 'A';
            if (!(seenCharMask & (1<<indx))) {
                seenCharMask |= 1<<indx;
                unique_chars += c;
            }
        }
        noZeroMask |= 1 << (word[0] - 'A');
    };
    
    for(const auto &lhs: lv) {
        processWord(lhs);
    }

    processWord(rhs);
    
    if (unique_chars.size() > 10) return std::nullopt;

    std::array<int, 26> char_to_int = {};

    auto backtrack = [&](auto &self, size_t char_idx, size_t used_char_mask) ->bool {
        
        if (char_idx == unique_chars.size()) {
            long long lhs_sum = 0;
            for(const auto &lhs: lv) {
                lhs_sum += word_to_int(lhs, char_to_int);
            }
            return lhs_sum == word_to_int(rhs, char_to_int);
            return false;
        }

        char unique_char = unique_chars[char_idx];
        size_t char_bit = 1 << (unique_char - 'A');

        for(int i = 0; i < 10; i++) {
            if (used_char_mask & (1<<i)) continue;
            if (i == 0 && (noZeroMask & char_bit)) continue;
            char_to_int[unique_char - 'A'] = i;
            if (self(self, char_idx+1, used_char_mask | (1<<i))) {
                return true;
            }
        }

        return false;
    };

    if (!backtrack(backtrack, 0, 0)) return std::nullopt;
    
    std::unordered_map<char, int> ans;
    for(const auto &c: unique_chars) {
        ans[c] = char_to_int[c-'A'];
    }
    
    return ans;
}
    
}  // namespace alphametics
