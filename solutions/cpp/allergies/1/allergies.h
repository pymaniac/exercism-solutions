#pragma once

#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>
namespace allergies {

// TODO: add your solution here
class allergy_test {
    public:
    allergy_test(uint32_t indx) : allergy_index(indx) {}
    bool is_allergic_to(const std::string &food) const;
    std::unordered_set<std::string> get_allergies() const;
    
    private:
    int get_index(const std::string &food) const;
    uint32_t allergy_index;
    inline static const std::vector<std::string> allergens = {
    "eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate",
    "pollen", "cats" };
 
};
}  // namespace allergies
