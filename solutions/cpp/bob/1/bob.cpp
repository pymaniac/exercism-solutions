#include "bob.h"

#include <cctype>
#include <algorithm>
#include <iostream>

namespace bob {

template <typename Predicate>
bool checkString(const std::string_view &stuff, Predicate pred) {
    for(auto c: stuff) {
        if (!pred(c)) return false;
    }
    return true;
}
    
// TODO: add your solution here
std::string hey(const std::string &str) {
    // remove trailing whitespace
    std::string_view stuff = str; 
    stuff.remove_suffix(std::distance(str.rbegin(), std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !std::isspace(ch); })));

    bool space = checkString(stuff, [](char c) {return std::isspace(c);});
    if (space) return "Fine. Be that way!";
    
    bool q = stuff.back() == '?';
    bool all_caps = checkString(stuff, [](char c) {return (std::isalpha(c) == false || std::isupper(c));});
    /*bool all_caps = false;
    for(auto c: stuff) {
        if (std::isalpha(c) && !std::isupper(c)) {
            all_caps = false;
            break;
        }
    }*/
    int cnt = std::count_if(stuff.begin(), stuff.end(), [](char c) { return std::isalpha(c); });

    std::cout << cnt << " " << all_caps << std::endl;

    //if (!cnt && !q) return "Whatever.";
    if (q) {
        return (cnt && all_caps) ? "Calm down, I know what I'm doing!" : "Sure.";
    }
    return (all_caps && cnt) ? "Whoa, chill out!" : "Whatever.";
}
}  // namespace bob
