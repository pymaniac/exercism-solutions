#include <iostream>
#include "vehicle_purchase.h"

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    // TODO: Return the final decision in a sentence.
    constexpr std::string_view append_string = " is clearly the better choice.";
    return (option1 < option2) ? option1 + std::string(append_string) : option2 + std::string(append_string);
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    // TODO: Return the age-corrected resell price.
    double mult = 0.50;
    if (age < 3) {
        mult = 0.8;
    }
    else if (age < 10) {
        mult = 0.7;
    }
    return original_price * mult;
}

}  // namespace vehicle_purchase
