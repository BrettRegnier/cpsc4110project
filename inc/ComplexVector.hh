#ifndef COMPLEXVECTOR_HH
#define COMPLEXVECTOR_HH

#include <vector>
#include "ComplexNumber.hh"

namespace ComplexSpace
{
    class ComplexVector 
    {
        private:
            std::vector<ComplexNumber> v;

        public:
            ComplexVector(std::vector<ComplexNumber> A);
            ~ComplexVector();

            ComplexVector Add(ComplexVector A);
            ComplexVector DotProduct(ComplexVector B);
    };
}

#endif