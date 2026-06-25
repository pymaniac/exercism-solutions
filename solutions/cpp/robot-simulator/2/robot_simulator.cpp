#include "robot_simulator.h"

namespace robot_simulator {
void Robot::advance() {
    
    switch(bearing) {
        default:
            return;
        case Bearing::NORTH:
            loc.y++;
            break;
        case Bearing::SOUTH:
            loc.y--;
            break;
        case Bearing::EAST:
            loc.x++;
            break;
        case Bearing::WEST:
            loc.x--;
            break;
    }
}

void Robot::execute_sequence(const std::string &seq)  {
    for(const auto &c: seq) {
        (this->*funcmap.at(c))();
    }
}

}  // namespace robot_simulator
