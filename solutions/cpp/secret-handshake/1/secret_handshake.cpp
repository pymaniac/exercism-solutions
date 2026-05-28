#include "secret_handshake.h"

namespace secret_handshake {

    
// TODO: add your solution here
std::vector<std::string> commands(uint8_t c) {
    std::vector<std::string> ans;
    static const std::vector<std::string> lkup = {
    "wink", "double blink", "close your eyes", "jump"
    };
    
    for(int i = 0; c; c >>=1, i++) {
        if (c & 1) {
            if (i < static_cast<int>(lkup.size()))
                ans.push_back(lkup[i]);
            else
                return {ans.rbegin(), ans.rend()};
        }
    }
    return ans;
}
}  // namespace secret_handshake
