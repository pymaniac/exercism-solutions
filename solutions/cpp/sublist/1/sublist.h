#pragma once

#include <cstdint>
#include <vector>

namespace sublist {

// TODO: add your solution here
enum class List_comparison : uint8_t {
    sublist,
    equal,
    superlist,
    unequal
};

List_comparison sublist(const std::vector<int> &l1, const std::vector<int> &l2);
}  // namespace sublist
