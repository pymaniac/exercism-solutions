#include "parallel_letter_frequency.h"

#include <execution>
#include <algorithm>
#include <mutex>
#include <memory>
#include <iostream>

namespace parallel_letter_frequency {
    std::unordered_map<char, int> frequency(const std::vector<std::string_view> & txt) {
        auto count_chars = [&](const std::string_view s) -> std::unordered_map<char, int> {
            std::unordered_map<char, int> umap;
            for(const auto c: s) {
                if (std::isalpha(static_cast<unsigned int>(c))) umap[std::tolower(c)]++;
            }
            return umap;
        };
    
        auto merge_maps = [&](std::unordered_map<char, int> left, const std::unordered_map<char, int> &right) -> std::unordered_map<char, int> {
            for(const auto &[c, count]: right) {
                left[c] += count;
            }
            return left;
        };
    
        std::unordered_map<char, int> ans = std::transform_reduce(
            std::execution::par,
            txt.begin(), txt.end(),
            std::unordered_map<char, int>{},
            merge_maps,
            count_chars
        );

        return ans;
    }
}
