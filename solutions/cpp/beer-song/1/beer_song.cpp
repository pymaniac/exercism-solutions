#include "beer_song.h"

#include <sstream>
#include <iostream>
#include <cctype>

namespace beer_song {

// TODO: add your solution here
std::string verse(int num_bottles) {
    std::string sb = (num_bottles) ? std::to_string(num_bottles) : "No more";
    std::string bot = (num_bottles == 1) ? "bottle" : "bottles";
    
    std::stringstream ss;
    ss << sb << " " << bot << " of beer on the wall, ";
    if (!num_bottles) sb[0] = std::tolower(sb[0]);
    ss << sb << " " << bot << " of beer." << std::endl;
    if (num_bottles) {
        std::string x = (num_bottles == 1) ? "it" : "one";
        ss << "Take " << x << " down and pass it around, ";
        --num_bottles;
        sb = std::to_string(num_bottles);
        bot = (num_bottles == 1) ? "bottle" : "bottles";
        if (!num_bottles) sb = "no more";
        ss << sb << " " << bot << " of beer on the wall." << std::endl;
    } else {
        ss << "Go to the store and buy some more, 99 bottles of beer on the wall." << std::endl;
    }
    return ss.str();
}

std::string sing(int start, int end) {
    std::stringstream ss;
    while(start >= end) {
        ss << verse(start);
        if (--start >= end) ss<<std::endl;
    }
    return ss.str();
}
}  // namespace beer_song
