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
    for(int i = 0; i < v.size(); i++)
    {
        ComplexVector added = v[i].Add(A.v[i]);
        newMatrix.push_back(added);
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

