#pragma once

#include <sstream>
#include <cmath>

namespace ComplexSpace
{
class ComplexNumber
{
  private:
    float real;
    float imaginary;

  public:
    ComplexNumber(float r = 0, float i = 0);
    ~ComplexNumber();

    ComplexNumber Add(ComplexNumber x);
    ComplexNumber Product(ComplexNumber x);

    float Modulus();
    ComplexNumber Conjugate();

    float Real();
    float Imaginary();

    void Real(float r);
    void Imaginary(float i);

    ComplexNumber operator+(ComplexNumber x);
    ComplexNumber operator*(ComplexNumber x);
    bool operator==(ComplexNumber i);

    std::string ToString();
};
} // namespace ComplexSpace
