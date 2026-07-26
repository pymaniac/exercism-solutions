#include "affine_cipher.h"

#include <stdexcept>
#include <iostream>

namespace affine_cipher {

constexpr int m = 26;
// TODO: add your solution here
bool validate_a(int a) {
    int end = std::min(a, m);
    for(int st = 2; st <= end; st++) {
        if (a %st == 0 && m % st == 0) return false;
    }
    return true;
}
    
std::string encode(const std::string &plaintext, int a, int b){
    if (!validate_a(a)) {
        throw std::invalid_argument("a is not coprime with m");
    }

    std::string ans;
    int cnt = 0;
    for(const auto c: plaintext) {
        if (!std::isalnum(c)) continue;
        if (cnt && cnt == 5) { ans += ' '; cnt = 0; }
        cnt++;
        if (std::isdigit(c)) {
            ans += c;
            continue;
        }
        char st = std::isupper(c) ? 'A' : 'a';
        int i = c - st;
        int ex = (a*i + b) % m;
        ans += ex + 'a';
    }

    return ans;
}

std::string decode(const std::string &ciphertext, int a, int b) {
    if (!validate_a(a)) {
        throw std::invalid_argument("a is not coprime with m");
    }

    int mmi = 2;
    while(((a*mmi) % m) != 1) mmi++;

    std::string ans;
    for(const auto c: ciphertext) {
        if (c == ' ') continue;
        if (std::isdigit(c)) {
            ans += c;
            continue;
        }
        int y = c - 'a';
        int dy = ((mmi)*(y - b)) % m;
        if (dy < 0) dy += m;
        //std::cout << "c = " << c << " y = " << y << " dy = " << dy << std::endl;
        ans += dy + 'a';
    }
    return ans;
}

}  // namespace affine_cipher
