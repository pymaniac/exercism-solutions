#pragma once

#include <string>
#include <unordered_map>

namespace space_age {

// TODO: add your solution here
    class space_age {
        public:
        space_age(uint64_t age_secs) : age_in_seconds(age_secs) {}
        uint64_t seconds() const { return age_in_seconds; }
        double on_earth() const { return conv_secs_to_years("Earth"); }
        double on_mercury() const { return conv_secs_to_years("Mercury"); }
        double on_venus() const { return conv_secs_to_years("Venus"); }
        double on_mars() const { return conv_secs_to_years("Mars"); }
        double on_jupiter() const { return conv_secs_to_years("Jupiter"); }
        double on_uranus() const { return conv_secs_to_years("Uranus"); }
        double on_neptune() const { return conv_secs_to_years("Neptune"); }
        double on_saturn() const { return conv_secs_to_years("Saturn"); }
    
        private:
        uint64_t age_in_seconds{0};
        static constexpr uint64_t one_earth_year_seconds = 31'557'600;
        double conv_secs_to_years(const std::string &planet) const;
        static inline const std::unordered_map<std::string, double> conv{
            {"Mercury", 0.2408467},
            {"Venus", 0.61519726},
            {"Earth", 1.0},
            {"Mars",	1.8808158},
            {"Jupiter",	11.862615},
            {"Saturn",	29.447498},
            {"Uranus",	84.016846},
            {"Neptune",	164.79132}
        };
    };
}  // namespace space_age
