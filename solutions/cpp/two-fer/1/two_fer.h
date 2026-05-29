#pragma once
#include <string>

namespace two_fer {

// TODO: add your solution here
inline const std::string two_fer(const std::string &name={}) {
    if (name.size()) {
        return "One for " + name +", one for me.";
    }

    return "One for you, one for me.";
}
}  // namespace two_fer
