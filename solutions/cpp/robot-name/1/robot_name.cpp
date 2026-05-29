#include "robot_name.h"

#include <sstream>
#include <iomanip>

namespace robot_name {

// TODO: add your solution here
int robot::gen_random(int num) {
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, num);
    return uniform_dist(e1);
}
    
void robot::generate_name() {
    char a = 'A' + gen_random(0x7FFFFFFF) % 26;
    char b = 'A' + gen_random(0x7FFFFFFF) % 26;
    int c = gen_random(1232424443) % 1000;
    std::stringstream ss;
    ss << a << b << std::setfill('0') << std::setw(3) << c;
    robot_name = ss.str();
}
    
}  // namespace robot_name
