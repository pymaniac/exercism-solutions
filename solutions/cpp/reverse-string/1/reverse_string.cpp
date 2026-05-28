#include "reverse_string.h"

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(const std::string &istr) { 
    return std::string(istr.rbegin(), istr.rend());
     #ifdef TRY1
    std::string str = istr;
    auto fit = str.begin();
    auto rit = str.end()-1;
    while(fit < rit) {
        std::swap(*fit++, *rit--);
    }
    return str;
    #endif
}
    
}  // namespace reverse_string
