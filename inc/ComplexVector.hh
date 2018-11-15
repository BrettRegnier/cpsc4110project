#ifndef COMPLEXVECTOR_HH
#define COMPLEXVECTOR_HH

#include <vector>

namespace ComplexSpace
{
    class ComplexVector 
    {
        private:
            std::vector<ComplexNumber> v;

        public:
            ComplexVector(std::vector<ComplexNumber> A);
            ~ComplexVecotr();

            std::vector<ComplexNumber> Add(std::vector<ComplexNumber> A);
            std::vector<ComplexNumber> DotProduct(std::vector<ComplexNumber> B);
    };
}

#endif