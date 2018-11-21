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
}

//working
ComplexMatrix::ComplexMatrix(std::vector<ComplexVector> k)
{
    // Require error checking that the input doesn't have unaligned sizes of rows
    // and columns
    v = k;
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
bool ComplexMatrix::operator==(ComplexMatrix A)
{
    if (Row() == A.Row() && Column() == A.Column())
    {
        for (int i = 0; i < Row(); i++)
        {
            for (int j = 0; j < Column(); j++)
            {
                if (!(v[i].v[j] == A.v[i].v[j]))
                {
                    return false;
                }
            }
        }

        return true;
    }
    
    return false;
}

//working
ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
   //this doesnt work
   //vector<ComplexVector> newMatrix = vector<ComplexVector>(row, column);

   vector<ComplexVector> newMatrix;
   if(CheckDimension(A))
   {
     
        for(int i = 0; i < Row(); i++)
        {
	   
	   ComplexVector added = v[i].Add(A.v[i]);
	   newMatrix.push_back(added);
	   
        }
     }
    else
    {
       cout<< "Dimension is not appropriate"<< endl;
	}
    //edit
    ComplexMatrix temp = ComplexMatrix(newMatrix);
    return temp;
    
    //before
    //return ComplexMatrix(newMatrix);
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

    }
    else
    {
        // throw error
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
        // error can't check if hermitian because not square
    }
}

ComplexMatrix ComplexMatrix::Conjugate()
{
    ComplexMatrix conj = ComplexMatrix(Row(), Column());
    for (int i = 0; i < Row(); i++)
    {
        conj.v.push_back(v[i].Conjugate());
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

    vector<ComplexVector> newMatrix = vector<ComplexVector>();

    for(int y = 0; y < newRows; y++)
    {
        ComplexVector newVector = ComplexVector();
        for(int x = 0; x < newColumns; x++)
        {
            newVector.v[x] = v[x/nRows].v[y/mRows].Product(A.v[y%nRows].v[x%mRows]);
        }
        newMatrix.push_back(newVector);
    }
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

    for (int i = 0; i < Row(); i++)
    {
        msg += v[i].ToString() + "\n";
    }

    return msg;
}