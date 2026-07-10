#include "resistor_color.h"

#include <algorithm>

namespace resistor_color {

// TODO: add your solution here
static const std::vector<std::string> bands = {
    "black", "brown", "red", "orange", "yellow", "green", "blue",
        "violet", "grey", "white" };

int color_code(const std::string &clr) {
    auto it = std::find(bands.begin(), bands.end(), clr);

    if (it == bands.end()) return -1;
    return std::distance(bands.begin(), it);
}

std::vector<std::string> colors() {
    return bands;
}

}  // namespace resistor_color
