#include "binary_search.h"

#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
    int l = 0, r = (int)length-1;

    while(l <= r) {
        int mid = l + (r - l)/2;

        if (arr[mid] == value) {
            printf("mid = %d\n", mid);
            return &arr[mid];
        } else if (arr[mid] > value) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("Nothing found\n");
    return NULL;
}
