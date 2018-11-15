#ifndef COMPLEXNUMBER_HH
#define COMPLEXNUMBER_HH

#include <string>

namespace ComplexSpace
{
    class ComplexNumber 
    {
        private:
            float real;
            float imaginary;
            int exponent;

            std::string ComplexString;

        public:
            ComplexNumber();
            ~ComplexNumber();

            ComplexNumber Add(ComplexNumber x, ComplexNumber y);
            ComplexNumber Product(ComplexNumber x, ComplexNumber y);

            float Modulus(ComplexNumber x);
            ComplexNumber Conjugate(ComplexNumber x);
    };
}

#endif