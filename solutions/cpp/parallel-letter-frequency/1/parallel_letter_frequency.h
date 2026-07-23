#pragma once

#include <string_view>
#include <vector>
#include <unordered_map>

namespace parallel_letter_frequency {
    std::unordered_map<char, int> frequency(const std::vector<std::string_view> &txt);
}
