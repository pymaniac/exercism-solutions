#pragma once

#include <string>

namespace phone_number {

// TODO: add your solution here
class phone_number {
    public:
    phone_number(const std::string n);
    inline std::string number() {return _ph; };
    private:
    std::string _ph;
};
    
}  // namespace phone_number
