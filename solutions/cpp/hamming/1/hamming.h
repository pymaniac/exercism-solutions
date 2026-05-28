#pragma once

#include <string>
#include <cmath>
#include <stdexcept>

namespace hamming {

// TODO: add your solution here
inline int compute(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) {
        throw (std::domain_error("Mismatched strand sizes"));
    }
    int diffs = 0;
    for(size_t i = 0; i < a.size(); i++) {
        diffs += (a[i] != b[i]) ? 1 : 0;
    }
    return diffs;
}

}  // namespace hamming
