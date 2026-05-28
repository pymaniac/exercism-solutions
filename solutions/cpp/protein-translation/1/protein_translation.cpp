#include "protein_translation.h"
#include <algorithm>

namespace protein_translation {
static bool check_any_of(std::vector<std::string> a, const std::string &s) {
    return std::any_of(a.begin(), a.end(), [s](const std::string &x) {
        return s == x;
    });
}
// TODO: add your solution here
std::vector<std::string> proteins(const std::string &seq) {
    std::vector<std::string> ans;
    for(size_t i = 0; i < seq.size(); i+=3) {
        auto s = seq.substr(i, 3);
        if (s == "AUG") {
            ans.emplace_back("Methionine");
        } else if (s == "UGG") {
            ans.emplace_back("Tryptophan");
        } else if (check_any_of({"UUU", "UUC"}, s)) {
            ans.emplace_back("Phenylalanine");
        } else if (check_any_of({"UUA", "UUG"}, s)) {
            ans.emplace_back("Leucine");
        } else if (check_any_of({"UCU", "UCC", "UCA", "UCG"}, s)) {
            ans.emplace_back("Serine");
        } else if (check_any_of({"UAU", "UAC"}, s)) {
            ans.emplace_back("Tyrosine");
        } else if (check_any_of({"UGU", "UGC"}, s)) {
            ans.emplace_back("Cysteine");
        } else if (check_any_of({"UAA", "UAG", "UGA"}, s)) {
            return ans;
        }
    }
    return ans;
}
}  // namespace protein_translation
