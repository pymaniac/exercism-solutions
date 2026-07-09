#include "rotational_cipher.h"

#include <iostream>

namespace rotational_cipher {

// TODO: add your solution here
std::string rotate(const std::string &str, int num) {
    constexpr int spread = 'z' - 'a' + 1;
    std::string ans;
    ans.reserve(str.size());
    num = (num % spread + spread) % spread;
    for(const auto s: str) {
        unsigned char c = static_cast<unsigned char>(s); 
        if (std::isupper(c)) {
            ans.push_back(static_cast<char>('A' + (c - 'A' + num) % spread));
        }
        else if (std::islower(c)) {
            ans.push_back(static_cast<char>('a' + (c - 'a' + num) % spread));
        }
        else {
            ans.push_back(s);
        }
            //std::cout << "s = " << s << " num = " << num << " res = " << res << std::endl;
        
    }
    return ans;
}

}  // namespace rotational_cipher
