#include "phone_number.h"

#include <cctype>
#include <algorithm>
#include <stdexcept>

namespace phone_number {


phone_number::phone_number(const std::string num) : _ph(num) {
    _ph.erase(std::remove_if(_ph.begin(), _ph.end(), [](char c) {
        return !std::isdigit(c); }), _ph.end());
    if(_ph.size() > 10 && _ph[0] == '1') _ph.erase(0, 1);
    if (_ph.size() != 10)
        throw std::domain_error("Invalid number");
    if (_ph[0] == '0' || _ph[0] == '1' || _ph[3] == '0' || _ph[3] == '1')
        throw std::domain_error("Invalid number N");

}
    
}  // namespace phone_number
