#include "complex_numbers.h"

#include <cmath>
#include <iostream>

namespace complex_numbers {
    
double Complex::abs() const {
    return std::sqrt(_real*_real + _complex*_complex);
}
    
Complex Complex::conj() const {
    return {_real, -_complex};    
}

Complex Complex::exp() const {
    //std::cout << std::exp(_real) * std::cos(_complex) << " " <<  std::sin(_complex) << std::endl;
    double x = std::exp(_real);
    return {x * std::cos(_complex), x * std::sin(_complex)};
}

Complex operator+(const Complex &lhs, const Complex &rhs) {
    return {lhs.real() + rhs.real(), lhs.imag() + rhs.imag()};
}
    
Complex operator-(const Complex &lhs, const Complex &rhs) {
    return {lhs.real() - rhs.real(), lhs.imag() - rhs.imag()};
}
    
Complex operator*(const Complex &lhs, const Complex &rhs) {
    return {lhs.real() * rhs.real() - lhs.imag() * rhs.imag(),
    lhs.real() * rhs.imag() + lhs.imag() * rhs.real()};
}
    
Complex operator/(const Complex &lhs, const Complex &rhs) {
    double c = rhs.real();
    double d = rhs.imag();
    double conj_other = c*c + d*d;
    return {(lhs.real() * c + lhs.imag() * d)/conj_other, (lhs.imag()*c - lhs.real()*d)/conj_other};
}
    
}  // namespace complex_numbers
