#include "all_your_base.h"

#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace all_your_base {
    
// TODO: add your solution here
std::vector<unsigned int> convert(unsigned int in_base, const std::vector<unsigned int> &in_digits, unsigned int out_base) {
    if (in_base < 2 || out_base < 2) {
        throw std::invalid_argument("Invalid arg");
    }

    unsigned int input_number = 0;
    unsigned int cnt = 1;
    for(auto it = in_digits.rbegin(); it != in_digits.rend(); it++, cnt *= in_base) {
        if (*it >= in_base) {
            throw std::invalid_argument("invalid positive digit");
        }
        input_number += *it * cnt;
    }
    
    //std::cout << input_number << std::endl;
    std::vector<unsigned int> ans;
    // kinda of funny requirement, 0 converts to an empty array.
    for (; input_number; input_number /= out_base) {
        ans.push_back(input_number%out_base);
        //std::cout << "red: " << input_number <<  " ans " << ans.front() <<std::endl;
    }

    if (ans.size() > 1)
        std::reverse(ans.begin(), ans.end());
    return ans;
}
}  // namespace all_your_base
