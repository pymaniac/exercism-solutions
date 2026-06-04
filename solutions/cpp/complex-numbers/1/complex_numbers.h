#pragma once

namespace complex_numbers {

// TODO: add your solution here
class Complex {
    public:
    Complex(double r=0.0, double c=0.0) : _real(r), _complex(c) {}
    inline double real() const { return _real; }
    inline double imag() const { return _complex; }
    double abs() const;
    Complex conj() const;
    Complex exp() const;
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend Complex operator-(const Complex &lhs, const Complex &rhs);
    friend Complex operator*(const Complex &lhs, const Complex &rhs);
    friend Complex operator/(const Complex &lhs, const Complex &rhs);
    private:
    double _real, _complex;
};
}  // namespace complex_numbers
