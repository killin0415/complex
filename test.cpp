#include <iostream>

#include "complex.h"
using namespace complex;

int main() {
    ComplexNumber i(2, 4), j(1, 3);
    std::cout << i.distance(j) << std::endl;
    return 0;
}