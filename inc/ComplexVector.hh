#ifndef COMPLEXVECTOR_HH
#define COMPLEXVECTOR_HH

#include <vector>
#include "ComplexNumber.hh"

namespace ComplexSpace
{
    class ComplexVector 
    {
        private:

        public:
            std::vector<ComplexNumber> v;
            ComplexVector();
            ComplexVector(int s);
            ComplexVector(std::vector<ComplexNumber> k);
            ~ComplexVector();

            ComplexVector Add(ComplexVector A);
            ComplexNumber DotProduct(ComplexVector A);
            ComplexVector Conjugate();
            void Insert(ComplexNumber i);
            int size();

            ComplexNumber& operator[](int idx);

            std::string ToString();
    };
}

#endif