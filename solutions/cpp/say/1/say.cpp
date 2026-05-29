#include "say.h"
#include <stdexcept>
#include <vector>
#include <iostream>

namespace say {

static const std::vector<std::string> digits{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    static const std::vector<std::string> teens1{"", "", "twen", "thir", "for", "fif", "six", "seven", "eigh", "nine"};
    static const std::vector<std::string> teens2{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static std::string isSpace(const std::string &v, const std::string &delim="") {
    if (delim.size()) return "";
    return ((v.size()) ? " ": "");
}

static std::string helper(int num) {
    if (!num) { 
        return ""; 
    }
        
    int o = num % 10;
    int t = (num/10) % 10;
    int h = num/100;

    //std::cout << num << ":::" <<  h << " :" << t << " " << o << std::endl;

    std::string ans;

    if (h > 0) {
        //return "";
        ans = digits[h] + " hundred";
    }
    //std::cout << h << " " << t << " " << o << std::endl;

    //return "";
    auto delim = "";
    if (t) {
        auto ts = teens1[t];
        if (ts == "") {
            ans = ans + isSpace(ans) + teens2[o];
            return ans;
        }
        ans = ans + isSpace(ans) + ts + "ty";
        delim = "-";
    }

    if (o) {
        ans = ans + isSpace(ans, delim) + delim + digits[o];
    } 
    return ans;
}

// TODO: add your solution here
std::string in_english(int64_t num) {
    if (num < 0) {
        throw std::domain_error("unhandled num");
    }
    int b = num/1000000000;
    if (b > 999) {
        throw std::domain_error("unhandled num");
    }

    std::string ans;
    if (b) ans = helper(b) + " billion";
    int m = (num/1000000) % 1000;
    if (m) ans = ans + isSpace(ans) + helper(m) + " million";
    int t = (num/1000) % 1000;
    if (t) ans = ans + isSpace(ans) + helper(t) + " thousand";
    int h = num % 1000;
    if (h) {
        ans = ans + isSpace(ans) + helper(h);
    } else if (ans.size() == 0) { return "zero"; } 
    return ans;
}

}  // namespace say
