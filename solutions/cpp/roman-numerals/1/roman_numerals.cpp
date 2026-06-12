#include "roman_numerals.h"

#include <stdexcept>
#include <iostream>

namespace roman_numerals {

        std::string convertToRoman(unsigned int x, int p) {
            static char conv_sym[] = { 'I', 'X', 'C', 'M'};
            static char next_sym[] = { 'V', 'L', 'D'};

            switch (x) {
                case 4: return {conv_sym[p-1],next_sym[p-1]};
                case 9: return {conv_sym[p-1],conv_sym[p]};
                case 5: return {next_sym[p-1]};
                default: break;
            }
            
            std::string repeat_sym((x>5) ? x-5 : x, conv_sym[p-1]); 
            if (x>5)
                repeat_sym.insert(repeat_sym.begin(), next_sym[p-1]);
            return repeat_sym;
        }
    
        std::string convert(unsigned int i)  {
            if (!i || i > 3999) {
                throw std::domain_error("Number out of range");
            }

            std::string ans;
            for (int n = 1; i; n++, i /= 10) {
                if (! (i%10)) continue;
                ans.insert(0, convertToRoman(i%10, n));
            }
            return ans;
        }
    
}  // namespace roman_numerals
