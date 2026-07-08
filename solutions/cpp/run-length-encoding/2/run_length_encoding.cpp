#include "run_length_encoding.h"
#include <charconv>
#include <iostream>

namespace run_length_encoding {

// TODO: add your solution here
std::string encode(const std::string &str) {
    if (str.empty()) return "";
    
    std::string ans;
    std::size_t n = str.size();
    ans.reserve(n);
    std::size_t count = 1;
    char buf[24];
    for(std::size_t i = 1; i < n; i++) {
        if (str[i] == str[i-1])
            count++;
        else {
            if (count > 1) {
                auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), count);
                ans.append(buf, ptr - buf);
            }
            ans.push_back(str[i-1]);
            count = 1;
        } 
    }

    if (count > 1) {
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), count);
        ans.append(buf, ptr - buf);
    }
    ans.push_back(str.back());

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
