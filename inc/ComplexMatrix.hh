#ifndef COMPLEXMATRIX_HH
#define COMPLEXMATRIX_HH

#include <vector>
#include "ComplexVector.hh"

namespace ComplexSpace
{
    class ComplexMatrix 
    {
        private:
            /* Variables */
            // v[row][column]
            std::vector<ComplexVector> v;

            bool CheckDimension(ComplexMatrix A);

    public:
            // std::vector<ComplexVector> v;
            ComplexMatrix();
            ComplexMatrix(int r, int c);
       ComplexMatrix(std::vector<ComplexVector> k);
       
            ~ComplexMatrix();

            ComplexMatrix Add(ComplexMatrix A);
            ComplexMatrix Multiplication(ComplexMatrix A);

            bool IsSquare();
            bool IsHermitian();
            bool IsUnitary();
            bool IsIdentity();

            ComplexMatrix TensorProduct(ComplexMatrix A);
            ComplexMatrix Conjugate();
            ComplexMatrix Transpose();
            ComplexMatrix Adjoint();
            ComplexVector Scalar_Mult(ComplexNumber a);
       
            float ExpectedValue(ComplexMatrix hermitian);

            bool operator==(ComplexMatrix B);
            ComplexMatrix operator+(ComplexMatrix B);
            ComplexMatrix operator*(ComplexMatrix B);
            ComplexVector operator[](int idx);

            // First vector is row
            int Row();
            // Second vector is column
            int Column();

            std::string ToString();
    };
}

#endif
