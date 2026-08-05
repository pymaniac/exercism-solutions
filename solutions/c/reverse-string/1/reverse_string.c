#include "reverse_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char *reverse(const char *value) {
    int r = strlen(value);
    char *ans = malloc(r*sizeof(char));
    memcpy(ans, value, r*sizeof(char));

    --r;
    for(int l = 0; l < r; l++, r--) {
        char tmp = ans[l];
        ans[l] = ans[r];
        ans[r] = tmp;
    }

    return ans;
}
