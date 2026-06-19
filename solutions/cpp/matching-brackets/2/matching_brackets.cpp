#include "matching_brackets.h"

#include <stack>

namespace matching_brackets {

// TODO: add your solution here
bool check(const std::string &inp) {
    std::stack<char> brackets;
    for(const auto c: inp) {
        switch (c) {
            default:
            continue;
        case '(':
            brackets.push(')');
            break;
        case '[':
            brackets.push(']');
            break;
        case '{':
            brackets.push('}');
            break;
        case ')':
        case ']':
        case '}':
            if (brackets.empty() || brackets.top() != c) return false;
            brackets.pop();
            break;
        }
    }
    return brackets.empty();
}
}  // namespace matching_brackets
