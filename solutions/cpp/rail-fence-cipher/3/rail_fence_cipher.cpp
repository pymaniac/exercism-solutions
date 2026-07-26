#include "rail_fence_cipher.h"

#include <iostream>

namespace rail_fence_cipher {

static std::string helper(const std::string& input, int num_rails, bool encode) {
    const size_t n = input.size();
    std::string ans(input);
    
    auto encode_func = [&](size_t &i, size_t r) -> void {
        ans[i++] = input[r];
    };

    auto decode_func = [&](size_t &i, size_t r) -> void {
        ans[r] = input[i++];
    };

    const size_t max_offset = (num_rails<<1) - 2;
    size_t downward_offset = max_offset;
    size_t upward_offset = 0;
    size_t i = 0;
    
    for(int rail_num = 0; rail_num < num_rails; rail_num++) {
        int downward_dir = true;
        size_t offset = max_offset;
        for(size_t r = rail_num; r < n; r += offset) {
            if (encode) encode_func(i, r); else decode_func(i, r);
            if (rail_num > 0 && rail_num < num_rails-1) 
                offset = (downward_dir) ? downward_offset : upward_offset;
            downward_dir = !downward_dir;
        }
        downward_offset -= 2;
        upward_offset += 2;
    }

    return ans;
}
    
std::string encode(const std::string& plaintext, int num_rails) {
    return helper(plaintext, num_rails, true);
}

std::string decode(const std::string& ciphertext, int num_rails) {
    return helper(ciphertext, num_rails, false);
}
    
}