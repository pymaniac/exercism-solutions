#include "word_count.h"

#include <cctype>
#include <iostream>

namespace word_count {
    
// TODO: add your solution here
const std::map<std::string, int> words(const std::string &sentence) {
    std::string ss;
    size_t cur = 0;
    std::map<std::string, int> ans;
    for(auto c: sentence) {
        if (std::isalnum(c)) {
            ss.push_back(std::tolower(c));
        } else if (ss.size()) {
            if (c == '\'' && cur < sentence.length()-1 && std::isalpha(sentence[cur+1])) {
                ss.push_back(std::tolower(c));
            } else {
                ans[ss]++;
                ss.clear();
            }
        }
        cur++;
    }

    if (ss.size()) {
        ans[ss]++;
    }

    //for(const auto &[str, cnt]: ans) {
    //    std::cout << str << " " << cnt << std::endl;
    //}
    return ans;
}
}  // namespace word_count
