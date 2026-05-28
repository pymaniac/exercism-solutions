#include "raindrops.h"

namespace raindrops {

// TODO: add your solution here
std::string convert(int a) {
    std::string ans;
    if (a%3 == 0) ans += "Pling";
    if (a%5 == 0) ans += "Plang";
    if (a%7 == 0) ans += "Plong";

    return ans.size() ? ans : std::to_string(a);
}

}  // namespace raindrops
