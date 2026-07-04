#include "isbn_verifier.h"

namespace isbn_verifier {

// TODO: add your solution here
bool is_valid(const std::string &isbn) {
    int cnt = 10;
    int sum = 0;
    for(const auto &c: isbn) {
        if (!cnt) return false;
        if (c == '-') continue;
        int v = c - '0';
        if (v < 0 || v > 9) {
            if (c != 'X' || cnt != 1) return false;
            v = 10;
        }
        sum += v * cnt--;
    }
    return (cnt == 0) && (sum % 11 == 0);
}
}  // namespace isbn_verifier
