#include "pig_latin.h"

#include <unordered_set>
#include <iostream>

namespace pig_latin {

// TODO: add your solution here
std::string translate_helper(const std::string_view str) {
    if (str.empty()) return "";

    const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    const std::unordered_set<std::string> rule1 = {"xr", "yt"};

    auto create_ans = [&](const size_t pos) -> std::string {
        size_t cnt = str.size() - pos;
        std::string ans{str.substr(pos, cnt)};
        //std::cout << ans << " pos = " << pos;
        ans += str.substr(0, pos);
        //std::cout << " ::: " << ans << std::endl;
        return ans + "ay";
    };
        
    const std::string first_two = std::string(str.data(), 2);
    if (vowels.find(str[0]) != vowels.end() || rule1.find(first_two) != rule1.end()) {
        return create_ans(0);
    }
       
    int cnt = 0;
    for (const auto c: str) {
        if (vowels.find(c) != vowels.end()) {
            if ((cnt > 0) && (str[cnt-1] == 'q' && str[cnt] == 'u')) {
                cnt++;
                //std::cout << "cnt = " << cnt << std::endl;
            }
            return create_ans(cnt);
        }
        cnt++;
    }

    const auto y_f = str.find("y", 1);
    if (y_f != str.npos) {
        return create_ans(y_f);
    }
    

    return "";
}

std::string translate(const std::string_view str) {
    size_t st = 0;
    std::string ans;
    //int cnt = 10;
    do {
        size_t pos = str.find_first_of(' ', st);
        ans += translate_helper(str.substr(st, pos - st));
        if (pos != str.npos) {
            ans += " ";
            pos++;
        }
        //std::cout << "pos = " << pos << std::endl;
        st = pos;
        //if (--cnt <= 0) break;
    } while(st != str.npos);
    return ans;        
}
    
}  // namespace pig_latin
