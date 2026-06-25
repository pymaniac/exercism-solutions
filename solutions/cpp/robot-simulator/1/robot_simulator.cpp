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
        switch (c) {
        case 'A':
        case 'a':
            advance();
            break;
        case 'R':
        case 'r':
            turn_right();
            break;
        case 'L':
        case 'l':
            turn_left();
            break;
        }
    }
}

}  // namespace robot_simulator
