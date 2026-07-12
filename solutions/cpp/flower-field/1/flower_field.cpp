#include "flower_field.h"

#include <iostream>

namespace flower_field {

// TODO: add your solution here
std::vector<std::string> annotate(const std::vector<std::string> &field) {
    if (!field.size()) return {};
    
    std::size_t n = field.size(), m = field[0].size();
    std::vector<std::string> ans = field;
    
    for(int i = 0; i < static_cast<int>(n); i++) {
        const auto &str = field[i];
        std::cout << str << std::endl;
        for(int j = 0; j < static_cast<int>(m); j++) {
            if (str[j] != '*') continue;
            for(int r = -1; r < 2; r++) {
                int ni = i + r;
                if (ni < 0 || ni >= static_cast<int>(n)) continue;
                for(int c = -1; c < 2; c++) {
                    int nj = c + j;
                    if (nj < 0 || nj >= static_cast<int>(m)) continue;
                    if (field[ni][nj] != '*') {
                        int v = ans[ni][nj] - '0';
                        if(v < 0 || v > 9) v = 0;
                        v++;
                        ans[ni][nj] = '0' + v;
                    }
                }
            }
        }
    }

    return ans;
        
    
    
}

}  // namespace flower_field
