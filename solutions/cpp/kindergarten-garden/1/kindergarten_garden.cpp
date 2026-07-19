#include "kindergarten_garden.h"

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace kindergarten_garden {

static const std::vector<std::string> students = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};

static std::unordered_map<char, Plants> lkup = {
    {'G', Plants::grass},
    {'C', Plants::clover},
    {'R', Plants::radishes},
    {'V', Plants::violets},
};
    
// TODO: add your solution here
std::array<Plants, 4> plants(const std::string &pl, const std::string &student) {
    auto it = std::find(students.begin(), students.end(), student);
    if (it == students.end()) return {};
    int d = std::distance(students.begin(), it);
    std::array<Plants, 4> ans = {};
    ans[0] = lkup[pl[d*2]];
    ans[1] = lkup[pl[d*2+1]];
    auto it2 = std::find(pl.begin(), pl.end(), '\n');
    int d2 = std::distance(pl.begin(), it2);
    d2++;
    ans[2] = lkup[pl[d2+ d*2]];
    ans[3] = lkup[pl[d2 + d*2+1]];
    return ans;
}
}  // namespace kindergarten_garden
