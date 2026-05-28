#include "space_age.h"

namespace space_age {

// TODO: add your solution here
    double space_age::conv_secs_to_years(const std::string &planet) const {
        auto it = space_age::conv.find(planet);
        return (it != space_age::conv.end()) ? age_in_seconds/(space_age::one_earth_year_seconds * it->second) : -1;
    }
}  // namespace space_age
