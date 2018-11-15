#include "ComplexNumber.hh"

using namespace ComplexSpace;

float ComplexNumber::Modulus()
{
    return sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
}

ComplexNumber ComplexNumber::Conjugate()
{
    imaginary *= -1;
}