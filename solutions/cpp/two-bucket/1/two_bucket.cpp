#include "two_bucket.h"

#include <queue>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace two_bucket {

// TODO: add your solution here
measure_result measure(int bucket1_capacity, int bucket2_capacity,
                       int target_volume,  bucket_id start_bucket) {

    measure_result res = {};
    
    std::queue<std::pair<int, int>> q;
    std::set<std::pair<int, int>> visited;
    auto add_to_queue = [&] (std::pair<int, int> new_val) -> void {
        if (visited.find(new_val) == visited.end()) {
            q.emplace(new_val);
            visited.emplace(new_val);
        }
    };

    visited.emplace(0, 0);
    if (start_bucket == bucket_id::one) {
        add_to_queue(std::pair<int, int>{bucket1_capacity, 0});
        visited.emplace(0, bucket2_capacity);
    } else {
        add_to_queue(std::pair<int, int>{0, bucket2_capacity});
        visited.emplace(bucket1_capacity, 0);
    }
    
    int cnt = 0;    
    while(!q.empty()) {
        size_t sz = q.size();
        cnt++;
        for(size_t i = 0; i < sz; i++) {
            const auto [w1, w2] = q.front();
            q.pop();
            std::cout << "sz = " << sz << " cnt = " << cnt << " w1 = " << w1 << " w2 = " << w2 << std::endl;
                    
            if (w1 == target_volume || w2 == target_volume) {
                res.num_moves = cnt;
                res.goal_bucket = (w1 == target_volume) ? bucket_id::one : bucket_id::two;
                res.other_bucket_volume = (w1 == target_volume) ? w2 : w1;
                return res;
            }
            
            // Pour
            if (w1 > 0 && w2 < bucket2_capacity) {
                auto p = std::min(w1, bucket2_capacity - w2);
                add_to_queue(std::pair<int, int>{w1-p, w2+p});
            }

            if (w2 > 0 && w1 < bucket1_capacity) {
                auto p = std::min(w2, bucket1_capacity - w1);
                add_to_queue(std::pair<int, int>{w1+p, w2-p});
            }
            
            // drain
            add_to_queue(std::pair<int, int>{0, w2});
            add_to_queue(std::pair<int, int>{w1, 0});

            // fill
            add_to_queue(std::pair<int, int>{bucket1_capacity, w2});
            add_to_queue(std::pair<int, int>{w1, bucket2_capacity});
        }
    }
    throw std::runtime_error("Cannot reach goal");
    return res;
}
}  // namespace two_bucket
