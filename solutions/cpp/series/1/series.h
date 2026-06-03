#pragma once

#include <string>
#include <vector>
#include <stdexcept>

namespace series {

// TODO: add your solution here
inline const std::vector<std::string> slice(const std::string str, size_t slice_sz) {
    if (!slice_sz || str.size() < slice_sz) 
        throw std::domain_error ("Invalid slice size");

    size_t left = 0, rt = slice_sz;
    std::vector<std::string> ans;
    while(rt <= str.size()) {
        ans.push_back({str.begin()+left, str.begin()+rt});
        left++;
        rt++;
    }
    return ans;
}
}  // namespace series
