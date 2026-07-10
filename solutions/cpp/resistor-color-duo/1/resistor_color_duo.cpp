#include "resistor_color_duo.h"

#include <unordered_map>
#include <iostream>

namespace resistor_color_duo {

std::unordered_map<std::string, int> band_map = {
    { "black", 0},
    { "brown", 1},
    { "red", 2},
    { "orange", 3},
    { "yellow", 4},
    { "green", 5},
    { "blue", 6},
    { "violet", 7},
    { "grey", 8},
    { "white", 9},
};
    
// TODO: add your solution here
int value(const std::vector<std::string> &stripes) {
    int ans = 0;
    for(int i = 0; i < 2; i++) {
        ans = ans*10 + band_map[stripes[i]];
    }
    return ans;
}
}  // namespace resistor_color_duo
