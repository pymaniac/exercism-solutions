#include "rail_fence_cipher.h"

#include <iostream>

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    const size_t n = plaintext.size();
    std::string ans;

    const size_t max_offset = 2*num_rails - 2;
    size_t downward_offset = max_offset;
    size_t upward_offset = 0;
    for(int rail_num = 0; rail_num < num_rails; rail_num++) {
        int downward_dir = true;
        size_t offset = max_offset;
        for(size_t r = rail_num; r < n; r += offset) {
            ans += plaintext[r];
            if (rail_num > 0 && rail_num < num_rails-1) 
                offset = (downward_dir) ? downward_offset : upward_offset;
            downward_dir = !downward_dir;
        }
        downward_offset -= 2;
        upward_offset += 2;
    }

    return ans;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    std::string ans(ciphertext);
    const size_t csz = ciphertext.size();
    const int max_offset = (num_rails<<1) - 2;

    int downward_offset = max_offset;
    int upward_offset = 0;

    size_t i = 0;
    std::cout << "csz = " << csz << std::endl;
    for(int rn = 0; rn < num_rails; rn++) {
        bool downward_dir = true;
        size_t offset = max_offset;
        for(size_t r = rn; r < csz; r += offset) {
             ans[r] = ciphertext[i++];
            
            if (rn > 0 && rn < num_rails-1) {
                offset = (downward_dir) ? downward_offset : upward_offset;
            }
            downward_dir = !downward_dir;
        }
        downward_offset -= 2;
        upward_offset += 2;
    }

    return ans;
}
    
}