#include "ComplexMatrix.hh"

using namespace ComplexSpace;
using namespace std;

ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
    vector<ComplexVector> newMatrix = vector<ComplexVector>();
    for(int i = 0; i < Matrix.size; i++)
    {
        ComplexVector added = Matrix[i].Add(A.Matrix[i]);
        newMatrix.push_back(added);
    }
}