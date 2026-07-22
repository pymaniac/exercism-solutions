#include "spiral_matrix.h"

#include <iostream>

namespace spiral_matrix {

static uint32_t helper(int sr, int sz, uint32_t sv, std::vector<std::vector<uint32_t>> &ans) {
    // first row
    int ec = sr + sz;
    
    for(int c = sr; c < ec; c++) {
        ans[sr][c] = sv++;
        //std::cout << "ans[" << sr << "][" << c << "]/ = " << ans[sr][c] << std::endl;
    }
        //std::cout << std::endl;

    ec--;
    for(int r = sr+1; r <= ec; r++) {
        ans[r][ec] = sv++;
        //std::cout << "ans[" << r << "][" << ec << " = " << ans[r][ec] << std::endl;
    }
    //std::cout << "ec = " << ec << std::endl;

    for(int c = ec-1; c >= sr; c--) {
        ans[ec][c] = sv++;
        //std::cout << "ans[" << ec << "][" << c << "] = " << ans[ec][c] << std::endl;
    }
        //std::cout << std::endl;

    for(int r = ec-1; r > sr; r--) {
        ans[r][sr] = sv++;
        //std::cout << "ans[" << r << "][" << sr << "]] = " << ans[r][sr] << std::endl;
    }
    //std::cout << std::endl;
    return sv;
}
    
// TODO: add your solution here
std::vector<std::vector<uint32_t>> spiral_matrix(int sz) {
    std::vector<std::vector<uint32_t>> ans(sz, std::vector<uint32_t>(sz));

    uint32_t sv = 1;
    for(int r = 0;sz > 0; sz-=2, r++) {
        sv = helper(r, sz, sv, ans);        
    }

    return ans;
}
    
}  // namespace spiral_matrix
