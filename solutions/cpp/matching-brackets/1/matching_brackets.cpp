#include "matching_brackets.h"

#include <stack>

namespace matching_brackets {

// TODO: add your solution here
bool check(const std::string &inp) {
    std::stack<char> brackets;
    for(const auto c: inp) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) return false;
            auto t = brackets.top();
            if (c == ')' && t != '(') return false;
            if (c == ']' && t != '[') return false;
            if (c == '}' && t != '{') return false;
            brackets.pop();
        }
    }
    return brackets.empty();
}
}  // namespace matching_brackets
