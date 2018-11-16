#include "ComplexMatrix.hh"

using namespace ComplexSpace;
using namespace std;

ComplexMatrix::ComplexMatrix(int r, int c)
{
    row = r;
    column = c;

    for (int i = 0; i < r; i++)
    {
        v.push_back(ComplexVector());
        for (int j = 0; j < c; j++)
        {
            v[j].v.push_back(ComplexNumber());
        }
    }
}

ComplexMatrix::ComplexMatrix(std::vector<ComplexVector> k)
{
    v = k;
}

ComplexMatrix::~ComplexMatrix()
{
}

bool ComplexMatrix::CheckDimension(ComplexMatrix A)
{
    return false;
}

bool ComplexMatrix::IsSquare(ComplexMatrix A)
{
    return false;
}

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


ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
    vector<ComplexVector> newMatrix = vector<ComplexVector>(row, column);
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
        // error
    }

    return ComplexMatrix(newMatrix);
}
ComplexMatrix ComplexMatrix::Multiplication(ComplexMatrix A)
{
   vector<ComplexVector> newMatrix = vector<ComplexVector>();
  
   if(Column() == A.Row())
   {
     
      for(int i=0; i < Column();i++)
      {
	 ComplexVector a;
	 for(int k =0; k< Column();k++)
	 {
	    int size = v.size();
	    ComplexNumber num = v[i].v[k + size];
	    a.v.push_back(num);
	 }
	 for(int j=0; j<Column(); j++)
	 {
	    newMatrix[j].v[i]= A.v[j].DotProduct(a);
	 }

      }
   }   
}

bool ComplexMatrix::IsHermitian()
{
    return *this == Adjoint();
}

ComplexMatrix ComplexMatrix::Conjugate()
{
    ComplexMatrix conj = ComplexMatrix(row, column);
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
    ComplexMatrix tran = ComplexMatrix(row, column);
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
