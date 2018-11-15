#include "ComplexNumber.hh"

using namespace ComplexSpace;

ComplexNumber::ComplexNumber(float r, float i)
{
   real = r;
   imaginary = i;
   exponent = 0;
}

ComplexNumber::~ComplexNumber()
{
}

ComplexNumber ComplexNumber::Add(ComplexNumber x)
{
   ComplexNumber a;
   a.real= x.real + real;
   a.imaginary= x.imaginary + imaginary;
   return a;
}

ComplexNumber ComplexNumber::Product(ComplexNumber x)
{
   ComplexNumber a;
   a.real= x.real * real;
   a.imaginary= x.imaginary * imaginary * -1;
   return a;
}

float ComplexNumber::Modulus()
{
    return sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
}

ComplexNumber ComplexNumber::Conjugate()
{
    imaginary *= -1;
}