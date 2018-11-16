#include "ComplexMatrix.hh"
#include <iostream>

using namespace ComplexSpace;
using namespace std;

int main()
{
    ComplexNumber a = ComplexNumber(1, 2);
    ComplexNumber b = ComplexNumber(2, 4);

    ComplexNumber c = a.Add(b);

    cout << c.ToString();
}

// Make a 