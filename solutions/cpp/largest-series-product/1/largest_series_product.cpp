#include "largest_series_product.h"

#include <cctype>
#include <numeric>
#include <stdexcept>
#include <iostream>

namespace largest_series_product {

// TODO: add your solution here
int largest_product(const std::string &series, int span) {
    if(span < 0 || series.size() < static_cast<size_t>(span)) {
        throw std::domain_error("Invalid input");
    }

    auto calcProd = [&](int l, int r) -> int {
        return std::accumulate(series.begin()+l, series.begin()+r, 1, [](int prod, unsigned char c) {
        return (prod * (c - '0'));
    });
    };
    
    int ans = 0;
    int prevans = 0;
    for(int l = 0, r = span-1; r < static_cast<int>(series.size()); l++, r++) {
        int lv = series[l] - '0', rv = series[r] - '0';
        if (lv < 0 || lv > 9 || rv < 0 || rv > 9) {
            throw std::domain_error("Not valid series");
        }

        int prev = (l > 0) ? series[l-1] - '0' : 1;
        int newans = (!ans || !prev) ? calcProd(l, r+1) : prevans*rv/prev;
        //std::cout << prev << " " << lv << " " << " " << rv << " " << ans << " " << newans << std::endl;
        ans = std::max(ans, newans);
        prevans = newans;
    }

    return ans;
}
}  // namespace largest_series_product
