#include "grains.h"

uint64_t square(uint8_t index) { if (!index || index > 64) return 0; return 1ULL<<(index-1);}
uint64_t total(void) {
    uint64_t ans = 0;
    for(int i = 1; i < 65; i++) {
        ans += square(i);
    }
    return ans;
}