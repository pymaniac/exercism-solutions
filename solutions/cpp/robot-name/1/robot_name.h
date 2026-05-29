#pragma once

#include <string>
#include <iostream>
#include <random>

namespace robot_name {

// TODO: add your solution here
class robot {
    public:
    robot() { generate_name(); }
    const std::string name() const { 
        //std::cout << robot_name << std::endl;
        return robot_name; }
    void reset() { generate_name(); }
    
    private:
    int gen_random(int num);
    void generate_name();
    std::random_device r;
    std::string robot_name;
};
}  // namespace robot_name
