#include "ComplexMatrix.hh"
#include <iostream>

using namespace ComplexSpace;
using namespace std;

//working
ComplexMatrix::ComplexMatrix(int r, int c)
{
    v = std::vector<ComplexVector>();
    for (int i = 0; i < r; i++)
    {
        v.push_back(ComplexVector());
        for (int j = 0; j < c; j++)
        {
            v[i].v.push_back(ComplexNumber());
        }
    }

    scalar = ComplexNumber(1, 0);
}

//working
ComplexMatrix::ComplexMatrix(std::vector<ComplexVector> k)
{
    v = k;
    scalar = ComplexNumber(1, 0);
}
ComplexMatrix::ComplexMatrix()
{
}

ComplexMatrix::~ComplexMatrix()
{
}

//working
bool ComplexMatrix::CheckDimension(ComplexMatrix A)
{
    return Row() == A.Row() && Column() == A.Column();
}

bool ComplexMatrix::IsSquare()
{
    return Row() == Column();
}

//working
bool ComplexMatrix::operator==(ComplexMatrix B)
{
    // Checks if every value in each [row][column] are equal
    if (Row() == B.Row() && Column() == B.Column())
    {
        for (int i = 0; i < Row(); i++)
        {
            for (int j = 0; j < Column(); j++)
            {
                if (!(v[i].v[j] == B.v[i].v[j]))
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

ComplexMatrix ComplexMatrix::operator+(ComplexMatrix B)
{
    return Add(B);
}

ComplexMatrix ComplexMatrix::operator*(ComplexMatrix B)
{
    return Multiplication(B);
}

ComplexVector &ComplexMatrix::operator[](int idx)
{
    if (idx < Row())
    {
        return v[idx];
    }
    else
    {
        throw "Out of index range";
    }
}

//working
ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
    vector<ComplexVector> newMatrix;
    if (CheckDimension(A))
    {
        // we just use the built in vector addition for each row.
        for (int i = 0; i < Row(); i++)
        {
            ComplexVector added = (*this)[i].Add(A[i]);
            newMatrix.push_back(added);
        }
    }
    else
    {
        cout << "Dimension is not appropriate" << endl;
    }
    ComplexMatrix temp = ComplexMatrix(newMatrix);
    return temp;
}

ComplexMatrix ComplexMatrix::Multiplication(ComplexMatrix A)
{
    ComplexMatrix tempMatrix = ComplexMatrix(Row(), A.Column());
    // C * D where the Columns of C have to equal the rows of D

    if (Column() == A.Row())
    {
        // Could be equal to Column() or A.Row()
        int mults = Column();

        // Loop through the new matrix's dimensions
        for (int i = 0; i < tempMatrix.Row(); i++)
        {
            for (int j = 0; j < tempMatrix.Column(); j++)
            {
                for (int k = 0; k < mults; k++)
                {
                    ComplexNumber t = (v[i].v[k] * A.v[k].v[j]);
                    tempMatrix.v[i].v[j] = tempMatrix.v[i].v[j] + t;
                }
            }
        }

        ComplexNumber scale = (*this).Scalar() * A.Scalar();
        tempMatrix.Scalar(scale);
    }
    else
    {
        throw "For matrix multiplication A*B, the the columns of A do not equal the Rows of B";
    }
    return tempMatrix;
}

bool ComplexMatrix::IsHermitian()
{
    if (IsSquare())
    {
        return *this == Adjoint();
    }
    else
    {
        throw "The matrix is not a square, therefore it is not a hermitian";
    }
}

bool ComplexMatrix::IsUnitary()
{
    if (IsSquare())
    {
        return (*this * Adjoint()).IsIdentity();
    }
    else
    {
        throw "The matrix is not a square, therefore it is not a unitary";
    }
}

bool ComplexMatrix::IsIdentity()
{
    if (IsSquare())
    {
        // Could iterate through row or column since they are square.
        for (int i = 0; i < Row(); i++)
            if (v[i][i].Real() != 1)
                return false;

        return true;
    }
    else
    {
        throw "The matrix is not a square, therefore it is not an identity";
    }
}

float ComplexMatrix::ExpectedValue(ComplexMatrix hermitian)
{
    if (hermitian.IsHermitian())
    {
        // Multiply the hermitian and the matrix together.
        ComplexMatrix result = Multiplication(hermitian);

        // Calculate the dot product of this * this*hermitian
        ComplexMatrix temp = Adjoint();

        result = temp.Multiplication(result);

        return result[0][0].Real();
    }
    else
    {
        throw "The inputted matrix is not a hermitian";
    }
}

ComplexMatrix ComplexMatrix::Conjugate()
{
    ComplexMatrix conj = ComplexMatrix(Row(), Column());
    for (int i = 0; i < Column(); i++)
    {
        //conj.v.push_back(v[i].Conjugate());
        conj.v[i] = v[i].Conjugate();
    }

    return conj;
}

ComplexMatrix ComplexMatrix::TensorProduct(ComplexMatrix A)
{
    int mRows = Row();
    int mColumns = Column();

    int nRows = A.Row();
    int nColumns = A.Column();

    int newRows = mRows * nRows;
    int newColumns = mColumns * nColumns;

    ComplexMatrix newMatrix = ComplexMatrix(newRows, newColumns);

    for (int i = 0; i < newRows; i++)
    {
        for (int j = 0; j < newColumns; j++)
        {
            newMatrix[i][j] = (*this)[i / nRows][j / mRows] * A[i % nRows][j % mRows];
        }
    }

    ComplexNumber scale = (*this).Scalar() * A.Scalar();
    newMatrix.Scalar(scale);

    return newMatrix;
}
ComplexVector ComplexMatrix::Scalar_Mult(ComplexNumber a)
{
    ComplexVector temp = ComplexVector();
    for (int i = 0; i < Row(); i++)
    {
        for (int j = 0; j < Column(); j++)
        {
            temp.v.push_back(a.Product(v[i].v[j]));
        }
    }
    return temp;
}

ComplexMatrix ComplexMatrix::Transpose()
{
    ComplexMatrix tran = ComplexMatrix(Row(), Column());
    for (int i = 0; i < Row(); i++)
    {
        for (int j = 0; j < Column(); j++)
        {
            tran.v[i].v[j] = v[j].v[i];
        }
    }

    return tran;
}

ComplexMatrix ComplexMatrix::Adjoint()
{
    return Conjugate().Transpose();
}

int ComplexMatrix::Row()
{
    return v.size();
}

int ComplexMatrix::Column()
{
    return v[0].v.size();
}

std::string ComplexMatrix::ToString()
{
    std::string msg = "";

    msg = "Scalar: " + scalar.ToString() + "\n";

    for (int i = 0; i < Row(); i++)
    {
        msg += v[i].ToString() + "\n";
    }

    return msg;
}

ComplexMatrix ComplexMatrix::TensorDiv()
{

    ComplexMatrix temp = ComplexMatrix(2, 1);
    ComplexMatrix first_bit = ComplexMatrix(2, 1);
    ComplexMatrix second_bit = ComplexMatrix(2, 1);
    first_bit[0][0] = 1;
    second_bit[0][0] = 1;
    second_bit[1][0] = -1;

    if (first_bit.TensorProduct(second_bit) == (*this))
    {
        temp = first_bit;
    }
    first_bit[0][0] = -1;
    if (first_bit.TensorProduct(second_bit) == (*this))
    {
        temp = first_bit;
    }
    first_bit[0][0] = 0;
    first_bit[1][0] = 1;
    if (first_bit.TensorProduct(second_bit) == (*this))
    {
        temp = first_bit;
    }
    first_bit[1][0] = -1;
    if (first_bit.TensorProduct(second_bit) == (*this))
    {
        temp = first_bit;
    }
    return temp;
}

ComplexMatrix ComplexMatrix::Hadamard()
{
    ComplexMatrix hadamard = ComplexMatrix(2, 2);
    float number = 1.0 / sqrt(2);
    ComplexNumber scale = ComplexNumber(number, 0);

    hadamard.Scalar(scale);
    hadamard[0][0] = 1;
    hadamard[0][1] = 1;
    hadamard[1][0] = 1;
    hadamard[1][1] = -1;

    return hadamard;
}

ComplexMatrix ComplexMatrix::CNOT()
{
    ComplexMatrix cnot = ComplexMatrix(4, 4);
    cnot[0][0] = ComplexNumber(1);
    cnot[1][1] = ComplexNumber(1);
    cnot[2][3] = ComplexNumber(1);
    cnot[3][2] = ComplexNumber(1);
    return cnot;
}

ComplexMatrix ComplexMatrix::Toffoli()
{
    ComplexMatrix toffoli = ComplexMatrix(8, 8);
    toffoli[0][0] = ComplexNumber(1);
    toffoli[1][1] = ComplexNumber(1);
    toffoli[2][2] = ComplexNumber(1);
    toffoli[3][3] = ComplexNumber(1);
    toffoli[4][4] = ComplexNumber(1);
    toffoli[5][5] = ComplexNumber(1);
    toffoli[6][7] = ComplexNumber(1);
    toffoli[7][6] = ComplexNumber(1);

    return toffoli;
}

ComplexMatrix ComplexMatrix::UF()
{
    ComplexMatrix UF = ComplexMatrix(4, 4);
    UF[0][1] = ComplexNumber(1);
    UF[1][0] = ComplexNumber(1);
    UF[2][2] = ComplexNumber(1);
    UF[3][3] = ComplexNumber(1);

    return UF;
}

ComplexMatrix ComplexMatrix::Identity()
{
    ComplexMatrix ident = ComplexMatrix(2, 2);
    ident[0][0] = 1;
    ident[1][1] = 1;

    return ident;
}
