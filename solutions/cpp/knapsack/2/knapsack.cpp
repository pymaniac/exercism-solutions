#include "knapsack.h"

namespace knapsack {

int maximum_value_try1(int max_weight, const std::vector<knapsack::Item> &items) {

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

int maximum_value(int max_weight, const std::vector<knapsack::Item> &items) {
    
    size_t n = items.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(max_weight+1, 0));

    for(size_t i = 1; i <= n; i++) {
        const auto &item = items[i-1];
        for(int j = 0; j <= max_weight; j++) {
            if (item.weight <= j) {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - item.weight] + item.value);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int max_value = dp[n][max_weight];
    std::vector<Item> chosenItems;

    int currentCapacity = max_weight;
    for(size_t i = n; i > 0; i--) {
        if (dp[i][currentCapacity] != dp[i-1][currentCapacity]) {
            chosenItems.push_back(items[i-1]);
            currentCapacity -= items[i-1].weight;
        }
    }

    return max_value;
}

}  // namespace knapsack
