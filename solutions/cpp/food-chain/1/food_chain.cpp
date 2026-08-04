#include "food_chain.h"

#include <vector>
#include <iostream>

namespace food_chain {

// TODO: add your solution here
std::string verse(int num) {
    static const std::vector<std::string> animals = {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
    static const std::string first_line = "I know an old lady who swallowed a ";
    static const std::string last_line = "I don't know why she swallowed the fly. Perhaps she'll die.";
    static const std::vector<std::string> lines = {"", 
    "It wriggled and jiggled and tickled inside her.",
    "How absurd to swallow a ",
    "Imagine that, to swallow a ",
    "What a hog, to swallow a ",
    "Just opened her throat and swallowed a ",
    "I don't know how she swallowed a ",
    "She's dead, of course!"};

    int i = num-1;
    int m = static_cast<int>(animals.size())-1;
    
    std::string ans = first_line + animals[i] + ".\n";
    
    ans += lines[i];
    if (i > 1 && i < m) ans += animals[i] + '!';
    if (i >= 1) ans += '\n';
    
    if (i == m) return ans;
    for(; i; i--) {
        const std::string &a = animals[i];
        //std::cout << i << " ans = " << ans;
        ans += "She swallowed the " + a + " to catch the " + animals[i-1];
        if (i == 2) {
            ans += " that wriggled and jiggled and tickled inside her";
        }
        ans += ".\n";
    }

    ans += last_line + '\n';
    return ans; 
}

std::string verses(int st, int end) {
    std::string ans;
    for(int i = st; i <= end; i++) {
        ans += verse(i);
        ans += '\n';
    }
    //ans.pop_back();
    return ans;
}

std::string sing() {
    return verses(1, 8);
}
    
}  // namespace food_chain
