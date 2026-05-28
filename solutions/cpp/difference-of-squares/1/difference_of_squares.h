#pragma once

namespace difference_of_squares {

// TODO: add your solution here
inline int square_of_sum(int i) {
    auto x = (i * (i+1))/2; return x*x;
}

    inline int sum_of_squares(int n) {
        if (n == 1) return 1;
        return n*n + sum_of_squares(n-1);
    }

    inline int difference(int n) {
        return square_of_sum(n) - sum_of_squares(n);
    }
    
}  // namespace difference_of_squares
