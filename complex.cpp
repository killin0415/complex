#include <string.h>

#include <cmath>
#include <iomanip>
#include <iostream>

#define pres(a) std::fixed << std::setprecision(2) << a

#include "complex.h"
namespace complex {
std::ostream &operator<<(std::ostream &os, ComplexNumber const &imag) {
    std::string out;
    if (imag._real == 0) {
        if (imag._imagine == 0)
            return os << 0;
        return os << pres(imag._imagine) << "i";
    }
    if (imag._imagine == 0)
        return os << pres(imag._real);
    if (imag._imagine < 0)
        return os << pres(imag._real) << "-" << pres(-imag._imagine) << "i";
    return os << pres(imag._real) << "+" << pres(imag._imagine) << "i";
}

bool operator==(ComplexNumber const &imag, ComplexNumber const &obj) {
    return obj._real == imag._real && obj._imagine == imag._imagine;
}

bool operator==(ComplexNumber const &imag, double const &obj) {
    return obj == imag._real && imag._imagine == 0;
}

ComplexNumber ComplexNumber::conjugate() {
    return ComplexNumber(_real, -_imagine);
}

double ComplexNumber::len() {
    return std::sqrt(std::pow(this->_real, 2) + std::pow(this->_imagine, 2));
}

double ComplexNumber::distance(ComplexNumber const &imag) {
    return (*this - imag).len();
}

ComplexNumber ComplexNumber::operator+(ComplexNumber const &imag) {
    ComplexNumber res;
    res._real = this->_real + imag._real;
    res._imagine = this->_imagine + imag._imagine;
    return res;
}
ComplexNumber ComplexNumber::operator-(ComplexNumber const &imag) {
    ComplexNumber res;
    res._real = this->_real - imag._real;
    res._imagine = this->_imagine - imag._imagine;
    return res;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber const &imag) {
    ComplexNumber res;
    res._real = this->_real * imag._real - this->_imagine * imag._imagine;
    res._imagine = this->_real * imag._imagine + this->_imagine * imag._real;
    return res;
}
ComplexNumber ComplexNumber::operator/(ComplexNumber const &imag) {
    ComplexNumber res;
    res._real = (this->_real * imag._real + this->_imagine * imag._imagine) / (std::pow(imag._real, 2) + std::pow(imag._imagine, 2));
    res._imagine = (this->_imagine * imag._real - this->_real * imag._imagine) / (std::pow(imag._real, 2) + std::pow(imag._imagine, 2));
    return res;
}
}  // namespace complex
