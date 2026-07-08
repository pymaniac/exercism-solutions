#include "run_length_encoding.h"
#include <iostream>

namespace run_length_encoding {

// TODO: add your solution here
std::string encode(const std::string &str) {
    std::string ans;
    std::size_t n = str.size();
    for(std::size_t r = 0, l = 0; r < n; r++) {
        if (str[l] != str[r]) {
            int diff = r - l;
            if (diff > 1) ans += std::to_string(diff);
            ans += str[l];
            l = r;
        } 
        if (r == n-1) {
            int diff = r - l + 1;
            if (diff > 1) ans += std::to_string(diff);
            ans += str[r];
        }
    }

    //if (!str.empty()) ans += str.back();

    return ans;
}

std::string decode(const std::string &str) {
    std::string ans;
    for(std::size_t i = 0; i < str.size(); i++) {
        std::size_t l = i;
        while(std::isdigit(str[i])) {
            i++;
        }
         //std::cout << "s[" << l << "] = " << str[l] << " s[" << i << "] = " << str[i] << std::endl;
        if (l != i) {
            std::string num_s(str.begin()+l, str.begin()+i);
            int num = std::stoi(num_s);
            std::string repeats(num, str[i]);
            //std::cout << "num_s " << num_s << " num " << num << " repeats " << repeats << std::endl;
            ans += repeats;
        } else {
            ans += str[i];
        }
    }
    return ans;
}
}  // namespace run_length_encoding
