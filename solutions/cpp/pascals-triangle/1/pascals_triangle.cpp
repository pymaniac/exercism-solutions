#include "pascals_triangle.h"

#include <iostream>

namespace pascals_triangle {

// TODO: add your solution here
const std::vector<std::vector<int>> generate_rows(unsigned int n) {
    std::cout << n << std::endl;
    std::vector<std::vector<int>> ans(n, std::vector<int>(0));
    for(unsigned int i = 0; i < n; i++) {
        ans[i].push_back(1);
        for(unsigned int j = 1; j < i; j++) {
            ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        if (i)
            ans[i].push_back(1);
    }
    return ans;
}

}  // namespace pascals_triangle
