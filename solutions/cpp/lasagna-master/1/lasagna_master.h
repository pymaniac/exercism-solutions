#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    int preparationTime(const std::vector<std::string> &layers, int prep_time=2);
    struct amount quantities(const std::vector<std::string> &layers);
    void addSecretIngredient(std::vector<std::string> &ingredients, const std::vector<std::string> &friend_ingredients);
    std::vector<double> scaleRecipe(const std::vector<double> &base_vals, int portions);
    void addSecretIngredient(std::vector<std::string> &ingredients, const std::string &aunt_sec);
}  // namespace lasagna_master
