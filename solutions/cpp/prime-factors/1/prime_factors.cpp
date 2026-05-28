#include "prime_factors.h"

namespace prime_factors {

// TODO: add your solution here
std::vector<long long> of(long long num) {
    std::vector<long long> ans;
    
    while((num & 0x1) == 0) {
        ans.emplace_back(static_cast<long long>(2));
        num >>= 1;
    }

    for (long long i = 3; i * i <= num; i+=2) {
        while (num % i == 0) {
            ans.emplace_back(i);
            num /= i;
        }
    }

    if (num > 2) { ans.emplace_back(num); }
    return ans;
}
    
}  // namespace prime_factors
