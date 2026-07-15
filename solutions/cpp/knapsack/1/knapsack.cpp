#include "knapsack.h"

namespace knapsack {

int maximum_value(int max_weight, const std::vector<knapsack::Item> &items) {

    auto solve = [&](auto &self, int indx, int remaining_wt) -> int {

        if (indx >= static_cast<int>(items.size()) || remaining_wt <= 0)
            return 0;
        
        int skip_amt = self(self, indx+1, remaining_wt);

        int incl_amt = 0;
        if (items[indx].weight <= remaining_wt) {
            incl_amt = items[indx].value + self(self, indx+1, remaining_wt-items[indx].weight);
        }

        return std::max(skip_amt, incl_amt);
    };

    return solve(solve, 0, max_weight);
 }
    
}  // namespace knapsack
