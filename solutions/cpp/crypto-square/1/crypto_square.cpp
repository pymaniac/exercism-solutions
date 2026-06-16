#include "crypto_square.h"

#include <cctype>
#include <cmath>

namespace crypto_square {

// TODO: add your solution here
cipher::cipher(const std::string &str) {
    int cnt;
    std::string compacted;
    for(auto c: str) {
        if (std::isalnum(c)) {
            cnt++;
            compacted.push_back(std::tolower(c));
        }
    }
    if (!cnt) return;
    int r = std::sqrt(cnt);
    int c = r;
    if (r*c < cnt) c++;
    if (r*c < cnt) r++;
    compacted.resize(r*c, ' ');
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            text.push_back(compacted[i+j*c]);
        }
        text.push_back(' ');
    }
    text.pop_back();
}
}  // namespace crypto_square
