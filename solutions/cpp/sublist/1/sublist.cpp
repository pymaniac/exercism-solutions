#include "sublist.h"

#include <algorithm>
#include <iterator>

namespace sublist {

static List_comparison check_sublist(const std::vector<int> &sub, const std::vector<int> &super, List_comparison c) {
    auto it = super.begin();
    while(it != super.end()) {
        it = std::find(it, super.end(), sub[0]);
        auto nit = std::next(it);
        if (it == super.end()) break;
    
        size_t n = sub.size();
        size_t m = std::distance(it, super.end());
        if (m < n) break;
    
        size_t i = 0;
        for(; i < n; i++, it++) {
            if(sub[i] != *it) break;
        }
    
        if (i == n) return c;
        it = nit;
    }
    return List_comparison::unequal;
    
}
    
// TODO: add your solution here
List_comparison sublist(const std::vector<int> &l1, const std::vector<int> &l2) {
    std::size_t n = l1.size(), m = l2.size();

    if (n == m) {
        for(size_t i = 0; i < n; i++) {
            if (l1[i] != l2[i]) return List_comparison::unequal;
        }
        return List_comparison::equal;
    }

    if (!n) return List_comparison::sublist;
    if (!m) return List_comparison::superlist;
    
    if (n < m) {
        return check_sublist(l1, l2, List_comparison::sublist);
    }

    return check_sublist(l2, l1, List_comparison::superlist);
}

}  // namespace List_comparison::sublist
