#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

// TODO: add your solution here
std::map<char, int> count(const std::string &seq) {
    std::map<char, int> ans = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (auto s: seq) {
        try {
            int &v = ans.at(s);
            v++;
        } catch (const std::out_of_range &ex) {
            throw std::invalid_argument(s + " is not valid"); 
        }
    }

    return ans;
}
}  // namespace nucleotide_count
