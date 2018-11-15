#ifndef COMPLEXMATRIX_HH
#define COMPLEXMATRIX_HH

#include <vector>
#include <string>
#include "ComplexNumber.hh"

namespace ComplexSpace
{
    class ComplexMatrix 
    {
        private:
            /* Variables */
            std::vector<std::vector<ComplexNumber>> Matrix;

            bool CheckDimension(std::vector<std::vector<ComplexNumber>> A, std::vector<std::vector<ComplexNumber>> B);
            bool IsSquare(std::vector<std::vector<ComplexNumber>> A);

            // First vector is row
            int Row();
            // Second vector is column
            int Column();

        public:
            ComplexMatrix();
            ~ComplexMatrix();

            std::vector<ComplexNumber> Add(std::vector<ComplexNumber> A, std::vector<ComplexNumber> B);
            std::vector<ComplexNumber> DotProduct(std::vector<ComplexNumber> A, std::vector<ComplexNumber> B);

            std::vector<std::vector<ComplexNumber>> Add(std::vector<std::vector<ComplexNumber>> A, std::vector<std::vector<ComplexNumber>> B);
            std::vector<std::vector<ComplexNumber>> Multiplication(std::vector<std::vector<ComplexNumber>> A, std::vector<std::vector<ComplexNumber>> B);

            bool IsHermitian(std::vector<std::vector<ComplexNumber>> A);

            std::vector<std::vector<ComplexNumber>> TensorProduct(std::vector<std::vector<ComplexNumber>> A, std::vector<std::vector<ComplexNumber>> B);
    };
}

#endif