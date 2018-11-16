#include "ComplexMatrix.hh"

using namespace ComplexSpace;
using namespace std;

ComplexMatrix::ComplexMatrix()
{
}
ComplexMatrix::ComplexMatrix(int r, int c)
{
}

ComplexMatrix::ComplexMatrix(std::vector<ComplexVector> k)
{
}

ComplexMatrix::~ComplexMatrix()
{
}

ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
    vector<ComplexVector> newMatrix = vector<ComplexVector>();
    if(CheckDimension(A))
    {
        for(int i = 0; i < v.size(); i++)
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
/*
   if(v.Column() == A.v.Row())
   {
      
      for(int i=0; i < v.size();i++)
      {
	 
      }*/

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