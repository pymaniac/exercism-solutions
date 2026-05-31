#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher {

static int get_index(char t) {
    if(t >= 'a' && t <= 'z') {
        return(t - 'a');
    }
        
    return (t - 'A');
}

static void update_answer(char t, std::string &ans) {
    if (std::isdigit(t)) {
        ans.push_back(t);
    } else {
        ans.push_back('z' - get_index(t));
    }
}

std::string decode(const std::string &cipher) {
    std::string ans;
    for(auto t: cipher) {
        if (std::isspace(t)) continue;
        update_answer(t, ans);
    }
    return ans;
}
    
std::string encode(const std::string &str) {
    std::string ts;
    int cnt = 0;
    for(auto t: str) {
        if (!std::isalnum(t)) continue;
        if(++cnt % 6 == 0) { ts.push_back(' '); cnt++; }
        update_answer(t, ts);
    }

    return ts;
}
    
}  // namespace atbash_cipher
