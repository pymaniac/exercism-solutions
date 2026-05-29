#include "sum_of_multiples.h"

#include <numeric>
#include <iostream>

namespace sum_of_multiples {

// TODO: add your solution here
uint32_t to(std::vector<uint32_t> base_vals, uint32_t num) {
    uint32_t ans = (num * (num+1))/2;
    std::vector<uint32_t> all_nums(num);
    std::iota(all_nums.begin(), all_nums.end(), 1);
    for(auto v: base_vals) {
        auto prod = v;
        for(uint32_t i = prod; prod < num; i++) {
            all_nums[prod-1] = 0;
            prod += v;
        }
    }
    //std::cout << ans << std::endl;
    //for(auto v: all_nums) {
    //    std::cout << v << " ";
    //}
    //std::cout << std::endl;
    
    ans = ans - std::accumulate(all_nums.begin(), all_nums.end(), 0);
    return ans;
}
}  // namespace sum_of_multiples
