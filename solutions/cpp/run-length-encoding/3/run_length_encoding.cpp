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
    std::size_t n = str.size();
    ans.reserve(n<<1);

    std::size_t i = 0;
    while(i < n) {
        if (std::isdigit(static_cast<unsigned char>(str[i]))) {
            int count = 0;

            auto [ptr, ec] = std::from_chars(str.data() + i, str.data() + (n - i), count);
            i = ptr - str.data();
            if (i < n) {
                ans.append(count, str[i++]);
            }
        } else {
            ans.push_back(str[i++]);
        }
    }
    return ans;
}
    
}  // namespace run_length_encoding
