#include "ComplexMatrix.hh"
#include <iostream>
#include <stdlib.h> // rand
#include <time.h>

using namespace ComplexSpace;
using namespace std;

ComplexNumber CreateNumber()
{
    srand(time(NULL));
    float real = float(rand() % 19  - 9);
    float imaginary = float(rand() % 19 + -9);

    return ComplexNumber(real, imaginary);
}

ComplexNumber CreateNumber(int r, int i)
{
    return ComplexNumber(r, i);
}

ComplexVector CreateVector(int elements)
{
    ComplexVector vec = ComplexVector();
    for (int i = 0; i < elements; i++)
    {
        vec.Insert(CreateNumber());
    }

    return vec;
}

ComplexMatrix CreateMatrix(int r, int c, bool hermitian, bool unitary)
{
    ComplexMatrix mat = ComplexMatrix(r, c);
    if (hermitian)
    {
        if (mat.IsSquare())
        {

        }
        else
        {
            // error
        }
    }
    else if (unitary)
    {
        if (mat.IsSquare())
        {

        }
        else
        {
            // error
        }
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            mat[i] = CreateVector(c);
        }
    }

    return mat;
}

int main()
{
   // Testing Complex Number
    // ComplexNumber a = ComplexNumber(1, 2);
    // ComplexNumber b = ComplexNumber(2, 4);
    // ComplexNumber b1 = ComplexNumber(4, 4);

    // ComplexVector k;
    // k.Insert(a);
    // k.Insert(b);
    // k.Insert(b1);
    
    // ComplexNumber c = a.Add(b);
    // ComplexNumber d= a.Product(b);
    // ComplexNumber e= a.Conjugate();

    // cout <<"Addition "<< c.ToString()<<endl;
    // cout <<"Product "<< d.ToString()<<endl;
    // //cout<< "Conjugate " << e.ToString() <<endl;

    // //Testing Complex Vector
    // ComplexVector a1 = ComplexVector(k);
    // ComplexVector a2 = ComplexVector(k);
    // ComplexVector result_add = a1.Add(a2);
    // ComplexNumber  result_product= a1.DotProduct(a2);
    
    // cout << "Complex Vector Addition"<<endl;
    // cout << result_add.ToString() << endl;
    // // for(int i = 0; i <3 ;i++)
    // // {
    // //    cout << result_add.v[i].Real() << " " << result_add.v[i].Imaginary()<< endl;
    // // }

    // cout <<"Complex Vector DotProduct" << endl;
    // cout << result_product.Real() << " " << result_product.Imaginary() << endl;

    // //Testing ComplexMatrix
    
    // ComplexMatrix x= ComplexMatrix(2,2);
    // ComplexMatrix y= ComplexMatrix(2,2);
    // ComplexMatrix z = x.Add(y);

    // cout<< "Matrix Addition"<<endl;
    // cout << z.ToString() << endl;
    // // for(int i = 0; i<2; i++)
    // // {
    // //    for(int j=0; j<2; j++)
    // //    {
	// //   cout<< z.v[i].v[j].Real() <<" " << z.v[i].v[j].Imaginary()<< "    ";
    // //    }
    // //    cout<< endl;
    // // }

    // cout<< "Test for operator == "<<endl;
    // if( x == y)
    //    cout << "Equal"<<endl;
    // else
    //    cout<< "Not Equal"<<endl;

    // cout<< "Test for Multiplication"<<endl;
    // ComplexMatrix mult= z.Multiplication(x);
    // cout << mult.ToString() << endl;
    // for(int i=0; i<2; i++)
    // {
    //    for(int j=0; j<2 ; j++)
    //    {
	//   cout <<mult.v[i].v[j].Real() << " " <<mult.v[i].v[j].Imaginary() << "    ";
    //    }
    //    cout<< endl;
    // }
    
    ComplexNumber a = ComplexNumber(1, 2);
    ComplexNumber b = ComplexNumber(2, 2);

    ComplexNumber c = a.Add(b);

    cout << c.ToString() << endl;

    cout << a.Modulus() << endl;
    cout << a.Conjugate().ToString() << endl;

    ComplexVector x = ComplexVector(2);
    x.v[0] = a;
    x.v[1] = b;
    ComplexVector y = ComplexVector(2);
    y.v[0] = ComplexNumber(1,1);
    y.v[1] = ComplexNumber(1,0);
    
    std::vector<ComplexVector> j;
    j.push_back(x);
    j.push_back(y);
    ComplexMatrix A = ComplexMatrix(j);

    ComplexVector p = ComplexVector(1);
    p.v[0] = a;
    ComplexVector o = ComplexVector(1);
    o.v[0] = ComplexNumber(1,1);
    std::vector<ComplexVector> k;
    k.push_back(p);
    k.push_back(o);
    ComplexMatrix B = ComplexMatrix(k);

    cout << x.ToString() << endl << endl;

    cout << "Matrix A" << endl;
    cout << A.ToString() << endl << endl;
    cout << "Matrix B" << endl;
    cout << B.ToString() << endl << endl;


    // ComplexMatrix C = ComplexMatrix(2, 3);
    // cout << C.ToString() << endl << endl;

    cout << "A rows = " << A.Row() << " columns = " << A.Column() << endl;
    cout << "B rows = " << B.Row() << " columns = " << B.Column() << endl;
    
    cout << "A * B = " << endl;
    cout << A.Multiplication(B).ToString(); 

    return 0;
    
}



