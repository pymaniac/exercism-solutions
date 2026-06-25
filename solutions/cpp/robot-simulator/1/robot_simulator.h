#pragma once

#include <utility>
#include <string>

namespace robot_simulator {

// TODO: add your solution here
typedef struct Point Point;
struct Point {
    int x{0};
    int y{0};
};

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    MAX_DIR
};

// turn right
inline constexpr Bearing operator++(Bearing &b) { 
    b = static_cast<Bearing>((static_cast<int>(b) + 1) % static_cast<int>(Bearing::MAX_DIR));
    return b;
}

//turn left
inline constexpr Bearing operator--(Bearing &b) { 
    int mx = static_cast<int>(Bearing::MAX_DIR);
    int add_on = mx - 1;
    b = static_cast<Bearing>((static_cast<int>(b) + add_on) % mx);
    return b;
}
    
class Robot {
    private:
        Point loc;
        Bearing bearing;
    public:
        Robot(): bearing(Bearing::NORTH) {};
        Robot(const std::pair<int, int> &p, const Bearing b) {
            loc.x = p.first;
            loc.y = p.second;
            bearing = b;
        }
        inline const std::pair<int, int> get_position() const {
            return std::pair{loc.x, loc.y};
        }
        inline Bearing get_bearing() const { return bearing; }

        inline void turn_left() { --bearing;}
        inline void turn_right() { ++bearing; }
    
        void advance();
        void execute_sequence(const std::string & seq);    
};

}  // namespace robot_simulator
