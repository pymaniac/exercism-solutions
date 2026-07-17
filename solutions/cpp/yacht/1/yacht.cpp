#include "yacht.h"

#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

namespace yacht {

// TODO: add your solution here
int score(const std::vector<int> &sl, const std::string &category) {
    std::array<int, 6> cnts = {};

    for(const auto &v: sl) {
        cnts[v-1]++;
    }

    if (category == "ones") return cnts[0];
    if (category == "twos") return cnts[1]*2;
    if (category == "threes") return cnts[2]*3;
    if (category == "fours") return cnts[3]*4;
    if (category == "fives") return cnts[4]*5;
    if (category == "sixes") return cnts[5]*6;

    if (category == "full house") {
        auto it1 = std::find(cnts.begin(), cnts.end(), 3);
        if (it1 == cnts.end()) return 0;
        auto it2 = std::find(cnts.begin(), cnts.end(), 2);
        if (it2 == cnts.end()) return 0;
        return *it1 *(std::distance(cnts.begin(), it1)+1) + *it2 * (std::distance(cnts.begin(), it2)+1);
    }

    if (category == "four of a kind") {
        auto it = std::find_if(cnts.begin(), cnts.end(), [](int cnt) { return cnt > 3; });
        if (it == cnts.end()) return 0;
        //std::cout << *it << " distance = " << std::distance(cnts.begin(), it) << std::endl;
        return 4 * (std::distance(cnts.begin(), it)+1);
    }

    if (category == "little straight") {
        for(int i = 0; i < 5; i++) {
            if (cnts[i] != 1) return 0;
        }
        return 30;
    }

    if (category == "big straight") {
        for(int i = 1; i < 6; i++) {
            if (cnts[i] != 1) return 0;
        }
        return 30;
    }

    if (category == "choice") {
        int ans = 0;
        for(int i = 0; i < 6; i++) ans += cnts[i]*(i+1);
        return ans;
    }

    if (category == "yacht") {
        for(int i = 0; i < 6; i++) {
            if (cnts[i] == 5) return 50;
        }
        return 0;
    }

    return 0;
}
}  // namespace yacht
