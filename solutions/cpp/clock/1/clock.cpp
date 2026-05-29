#include "clock.h"

#include <iomanip>
#include <sstream>

namespace date_independent {

clock clock::at(int hr, int min){
    int m = min % 60;
    hr += min/60;
    int h = hr % 24;
    if (m < 0) {
        --h;
        m += 60;
    }
    if (h < 0) h += 24;
    return clock(h, m);
}

clock clock::plus(int mins_to_add) {
    return clock::at(hour, min + mins_to_add);
}    

clock::operator std::string() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << min;
    return ss.str();
}

bool clock::operator==(const clock& other) const {
    return (hour == other.hour) && (min == other.min); 
}

bool clock::operator!=(const clock& other) const {
    return (hour != other.hour) || (min != other.min);
}
    
}  // namespace date_independent
