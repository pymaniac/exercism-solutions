#pragma once

namespace triangle {

// TODO: add your solution here
    enum class flavor {
        equilateral,
        isosceles,
        scalene
    };
    
flavor kind(float a, float b, float c); 
}  // namespace triangle
