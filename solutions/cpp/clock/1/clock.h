#pragma once

#include <string>

namespace date_independent {

class clock {
public:
    clock(int h, int m): hour(h), min(m) {}
    static clock at(int hour, int min);
    clock plus(int num);
    operator std::string() const;
    bool operator ==(const clock &other) const;
    bool operator !=(const clock &other) const;
private:
    int hour, min;
};
    
}  // namespace date_independent
