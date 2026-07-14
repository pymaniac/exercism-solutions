#include "list_ops.h"

#include <algorithm>

namespace list_ops {

// TODO: add your solution here
void append(std::vector<int> &left, const std::vector<int> &right) {
    for(const auto &r: right) {
        left.push_back(r);
    }
}

size_t length(const std::vector<int> &input) {
    return std::distance(input.begin(), input.end());
}
    
}  // namespace list_ops
