#include "acronym.h"
#include <cctype>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>

namespace acronym {

// TODO: add your solution here

static char getFirstLetter(const char *token) {
    int i = 0;
    for(; !std::isalpha(token[i]); i++);
    return std::toupper(token[i]);
}    
    
const std::string acronym(std::string str) {
    char *strp = str.data();
    const char *delimiters = " -";
    char *savePtr;
    char *myPtr = strtok_r(strp, delimiters, &savePtr);
    std::string ans;

    if (myPtr == NULL)
        ans.push_back(std::toupper(str[0]));

    while(myPtr != NULL) {
        ans.push_back(getFirstLetter(myPtr));
        myPtr = strtok_r(NULL, delimiters, &savePtr);
    }

    return ans;
}
    
}  // namespace acronym
