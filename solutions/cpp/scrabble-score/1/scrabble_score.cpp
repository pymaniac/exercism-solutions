#include "scrabble_score.h"

#include <array>
#include <string_view>

namespace scrabble_score {

constexpr std::array<char, 26> make_scrabble_table() {
    std::array<char, 26> table = {};

    auto assign = [&] (const std::string_view &letters, int points) {
        for(const auto &l: letters) {
            table[l - 'A'] = points;
        }
    };

    assign("AEIOULNRST", 1);
    assign("DG", 1);
    assign("BCMP", 3);
    assign("FHVWY", 4);
    assign("K", 5);
    assign("JX", 8);
    assign("QZ", 10);

    return table;
}
    
// TODO: add your solution here
unsigned int score(const std::string &word) {
    const std::array<char, 26> rubric = make_scrabble_table();

    int ans = 0;
    for(const auto &w: word) {
        int indx = w - 'a';
        if (indx < 0) indx = w - 'A';
        ans += rubric[indx];
    }

    return ans;
}

}  // namespace scrabble_score
