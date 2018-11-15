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
            ComplexVector(std::vector<ComplexNumber> k);
            ComplexVector(int s);
            ComplexVector();
            ~ComplexVector();

            ComplexVector Add(ComplexVector A);
            ComplexNumber DotProduct(ComplexVector A);
            ComplexVector Conjugate();
            void Insert(ComplexNumber i);
            int size();
    };
}

#endif