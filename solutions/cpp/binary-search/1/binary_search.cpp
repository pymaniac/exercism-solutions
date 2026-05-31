#include "binary_search.h"

#include <stdexcept>

namespace binary_search {

// TODO: add your solution here
int find(const std::vector<int> &data, int num) {
    int low = 0, high = data.size()-1;
    while(low <= high) {
        int mid = (low + high)/2;

        if (data[mid] == num) return mid;
        if (data[mid] < num) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    throw std::domain_error("not found");
}
}  // namespace binary_search
