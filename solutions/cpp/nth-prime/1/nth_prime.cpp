#include "nth_prime.h"

#include <cmath>
#include <vector>
#include <stdexcept>
#include <iostream>

namespace nth_prime {

static void fillSieve(std::vector<bool> &s, int prime) {
    for(size_t i = prime*prime; i < s.size(); i++ ) {
        if (i % prime == 0) s[i] = false;
    }
}
    
// TODO: add your solution here
int nth(int n) {
    if (n <= 0) { throw std::domain_error("invalid"); }
    if (n < 3) { return n+1; }
    int lognr = std::log(n) + 1;
    int sz = static_cast<int>(n*(lognr + std::log(lognr))+2);
    std::vector<bool> sieve(sz, true);
    sieve[0] = false;
    sieve[1] = false;
    
    for(size_t i = 2; i < sieve.size(); i++) {
        if (sieve[i] == false) continue;
        fillSieve(sieve, i);
    }

    for(size_t i = 0; i < sieve.size(); i++) {
        if (sieve[i] == true) n--;
        if (!n) return i;
    }
    
    return -1;
}
}  // namespace nth_prime
