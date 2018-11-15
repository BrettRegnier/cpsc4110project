#include "ComplexMatrix.hh"

using namespace ComplexSpace;
using namespace std;

ComplexMatrix ComplexMatrix::Add(ComplexMatrix A)
{
    vector<ComplexVector> newMatrix = vector<ComplexVector>();
    for(int i = 0; i < v.size; i++)
    {
        ComplexVector added = v[i].Add(A.v[i]);
        newMatrix.push_back(added);
    }
}