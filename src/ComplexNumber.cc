#include "ComplexNumber.hh"
using namespace ComplexSpace;

ComplexNumber::ComplexNumber(float r, float i)
{
   real = r;
   imaginary = i;
}

ComplexNumber::~ComplexNumber()
{
}

bool ComplexNumber::operator==(ComplexNumber& i)
{
    if (real == i.real && imaginary == i.imaginary)
        return true;

    return false;
}

ComplexNumber ComplexNumber::Add(ComplexNumber x)
{
   ComplexNumber a;
   a.real = x.real + real;
   a.imaginary = x.imaginary + imaginary;
   return a;
}

ComplexNumber ComplexNumber::Product(ComplexNumber x)
{
   ComplexNumber a;
   a.real = (x.real * real) + (x.imaginary * imaginary * - 1);
   a.imaginary = (x.imaginary * real) +(x.real * imaginary);
   return a;
}

float ComplexNumber::Modulus()
{
    return sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
}

ComplexNumber ComplexNumber::Conjugate()
{
   ComplexNumber a;
   int new_imaginary = imaginary * -1;
   a.real = real;
   a.imaginary = new_imaginary;
   return a;
   
}

float ComplexNumber::Real()
{
    return real;
}

float ComplexNumber::Imaginary()
{
    return imaginary;
}

void ComplexNumber::Real(float r)
{
    real = r;
}

void ComplexNumber::Imaginary(float i)
{
    imaginary = i;
}

std::string ComplexNumber::ToString()
{
    std::ostringstream stream;
    if (imaginary < 0)
        stream << real << " - " << imaginary*-1 << "i";
    else
        stream << real << " + " << imaginary << "i";

    return stream.str();
}
