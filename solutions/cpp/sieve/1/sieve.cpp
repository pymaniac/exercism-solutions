#include "sieve.h"

namespace sieve {

    static void sift(std::vector<bool>& sieve, int prime) {
        for(std::size_t i = prime*prime; i < sieve.size(); i += prime) {
            sieve[i] = false;
        }
    }
    
// TODO: add your solution here
std::vector<int> primes(uint32_t n) {
    std::vector<int> ans;
    if (n < 2) return ans;
    std::vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false; 
    for(std::size_t i = 2; i < sieve.size(); i++)
        sift(sieve, i);

    for(std::size_t i = 0; i < sieve.size(); i++) {
        if (sieve[i]) ans.push_back(i);
    }

    return ans;
}

}  // namespace sieve
