#include <string.h>

#include <iostream>

namespace complex {
class ComplexNumber {
   public:
    friend std::ostream &operator<<(std::ostream &os, ComplexNumber const &imag);
    friend bool operator==(ComplexNumber const &imag, ComplexNumber const &obj);
    friend bool operator==(ComplexNumber const &imag, double const &obj);

    ComplexNumber() : _real(0), _imagine(0){};
    ComplexNumber(double real, double imagine) : _real(real), _imagine(imagine){};
    ComplexNumber(double real) : _real(real), _imagine(0){};

    ComplexNumber conjugate();
    double len();

    double distance(ComplexNumber const &imag);

    ComplexNumber operator+(ComplexNumber const &imag);
    ComplexNumber operator-(ComplexNumber const &imag);
    ComplexNumber operator*(ComplexNumber const &imag);
    ComplexNumber operator/(ComplexNumber const &imag);

    double real = _real;
    double imagine = _imagine;

   private:
    double _real;
    double _imagine;
};
}  // namespace complex
