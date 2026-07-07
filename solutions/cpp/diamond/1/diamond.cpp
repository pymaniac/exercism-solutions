#include "diamond.h"

namespace diamond {

// TODO: add your solution here
std::vector<std::string> rows(char x) {
    int d = x - 'A';
    int n = 2*d+1;
    std::vector<std::string> ans(n, std::string(n, ' '));

    int mid = n/2;
    char st = 'A';
    for(int i = 0; i <= mid; i++, st++) {
        ans[i][mid-i] = st;
        ans[i][mid+i] = st;
        ans[n-i-1] = ans[i];
    }

    return ans;
}
    
}  // namespace diamond
