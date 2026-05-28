#include "pangram.h"

namespace pangram {

// TODO: add your solution here
bool is_pangram(const std::string &inp) {
    int mask = charmask;
    for(auto c: inp) {
        int indx = 0;
        if (c >= 'a' && c <= 'z') indx = 1<<(c - 'a');
        else if (c >= 'A' && c <= 'Z')  indx = 1<<(c - 'A');
        mask &= ~(indx);
        if (!mask) return true;
    }
    return false;
}

}  // namespace pangram
