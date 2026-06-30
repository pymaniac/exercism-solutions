#include "perfect_numbers.h"

#include <cmath>
#include <stdexcept>

namespace perfect_numbers {

classification classify(int n) {
    if (n <= 0) {
        throw std::domain_error("Invalid number");
    }
    
    int sum = (n == 1) ? 0 : 1;
    int limit = std::sqrt(n);
    for(int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            int d = n/i;
            if (d == i) d = 0;
            sum += i + d;
        }
    }

    if (sum == n) return classification::perfect;
    if (sum < n) return classification::deficient;
    return classification::abundant;
}
    
}  // namespace perfect_numbers
