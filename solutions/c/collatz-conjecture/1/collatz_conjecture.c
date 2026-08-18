#include "collatz_conjecture.h"

int steps(int start) {
    if (start <= 0) return ERROR_VALUE;
    int ret = 0;
    while(start != 1) {
        ret++;
        if (start & 1) { 
            start = start*3 + 1;
        } else {
            start >>= 1;
        }
    }
    return ret;
}