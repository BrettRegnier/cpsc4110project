#pragma once

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
            ComplexNumber scalar;

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
            ComplexVector& operator[](int idx);
       ComplexMatrix TensorDiv();
			ComplexNumber Scalar() { return scalar; }
			void Scalar(ComplexNumber i) { scalar = i; }

            // First vector is row
            int Row();
            // Second vector is column
            int Column();

			// Returns a graphical version of the matrix in string form.
            std::string ToString();
			
			static ComplexMatrix Hadamard();
			static ComplexMatrix CNOT();
			static ComplexMatrix Toffoli();
			static ComplexMatrix UF();
			static ComplexMatrix Identity();
    };
}
