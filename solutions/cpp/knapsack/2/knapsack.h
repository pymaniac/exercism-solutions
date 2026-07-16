#pragma once

#include <vector>

namespace knapsack {

typedef struct Item Item;
struct Item {
    int weight;
    int value;
    Item(int wt, int val) : weight(wt), value(val) {};
};
    
// TODO: add your solution here
int maximum_value(int max_weight, const std::vector<knapsack::Item> &items);

}  // namespace knapsack
