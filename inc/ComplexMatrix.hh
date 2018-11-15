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
            std::vector<ComplexVector> Matrix;

            bool CheckDimension(ComplexMatrix A);
            bool IsSquare(ComplexMatrix A);

            // First vector is row
            int Row();
            // Second vector is column
            int Column();


        public:
            ComplexMatrix(int r, int c);
            ~ComplexMatrix();

            ComplexMatrix Add(ComplexMatrix A);
            ComplexMatrix Multiplication(ComplexMatrix A);

            bool IsHermitian();

            ComplexMatrix TensorProduct(ComplexMatrix A);
            ComplexMatrix Conjugate();
            ComplexMatrix Transpose();
            ComplexMatrix Adjoint();
    };
}

#endif
