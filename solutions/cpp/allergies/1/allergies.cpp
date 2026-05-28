#include "allergies.h"
#include <algorithm>

namespace allergies {

// TODO: add your solution here
    int allergy_test::get_index(const std::string &food) const {
        auto it = std::find(allergy_test::allergens.begin(), allergy_test::allergens.end(), food);
        if (it == allergy_test::allergens.end()) return -1;
        return it - allergy_test::allergens.begin();
    }
    
    bool allergy_test::is_allergic_to(const std::string &food) const {
        int indx = get_index(food);
        if (indx == -1) return false;
        return (allergy_index & (1<<indx)) != 0;
    }
    
    std::unordered_set<std::string> allergy_test::get_allergies() const {
        std::unordered_set<std::string> ans;
        for(size_t i = 0; i < allergy_test::allergens.size(); i++) {
            if (allergy_index & (1<<i)) {
                ans.emplace(allergy_test::allergens[i]);
            }
        }
        return ans;
    }
}  // namespace allergies
