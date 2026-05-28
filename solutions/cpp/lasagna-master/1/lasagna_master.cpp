#include "lasagna_master.h"
#include <algorithm>

namespace lasagna_master {

// TODO: add your solution here
    int preparationTime(const std::vector<std::string> &layers, int prep_time) {
        return layers.size() * prep_time;
    }

    struct amount quantities(const std::vector<std::string> &layers) {
        int n = std::count(layers.begin(), layers.end(), "noodles");
        int s = std::count(layers.begin(), layers.end(), "sauce");
        return { n*50, s*0.2 };
    }

    void addSecretIngredient(std::vector<std::string> &ingredients, const std::vector<std::string> &friend_ingredients) {
        ingredients.pop_back();
        ingredients.push_back(friend_ingredients.back());
    }

    std::vector<double> scaleRecipe(const std::vector<double> &base_vals, int portions) {
        std::vector<double> ans(base_vals.size());
        double mult = portions/2.0;
        std::transform(base_vals.begin(), base_vals.end(), ans.begin(), [&mult](double v) {return v*mult;});
        //for (auto b: base_vals) { ans.push_back(b*mult); }
        return ans;
    }

    void addSecretIngredient(std::vector<std::string> &ingredients, const std::string &aunt_sec) {
        ingredients.back() = aunt_sec;
    }

}  // namespace lasagna_master
