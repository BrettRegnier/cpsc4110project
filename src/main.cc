#include "ComplexMatrix.hh"
#include <iostream>

using namespace ComplexSpace;
using namespace std;

int main()
{
   // Testing Complex Number
    ComplexNumber a = ComplexNumber(1, 2);
    ComplexNumber b = ComplexNumber(2, 4);
    ComplexNumber b1 = ComplexNumber(4, 4);

    ComplexVector k;
    k.Insert(a);
    k.Insert(b);
    k.Insert(b1);
    
    ComplexNumber c = a.Add(b);
    ComplexNumber d= a.Product(b);
    ComplexNumber e= a.Conjugate();

    cout <<"Addition "<< c.ToString()<<endl;
    cout <<"Product "<< d.ToString()<<endl;
    //cout<< "Conjugate " << e.ToString() <<endl;

    //Testing Complex Vector
    ComplexVector a1 = ComplexVector(k);
    ComplexVector a2 = ComplexVector(k);
    ComplexVector result_add = a1.Add(a2);
    ComplexNumber  result_product= a1.DotProduct(a2);
    
    cout << "Complex Vector Addition"<<endl;
    for(int i = 0; i <3 ;i++)
    {
       cout << result_add.v[i].Real() << " " << result_add.v[i].Imaginary()<< endl;
    }

    cout <<"Complex Vector DotProduct" << endl;
    cout << result_product.Real() << " " << result_product.Imaginary() << endl;

    //Testing ComplexMatrix
    
    ComplexMatrix x= ComplexMatrix(2,2);
    ComplexMatrix y= ComplexMatrix(2,2);
    ComplexMatrix z = x.Add(y);

    cout<< "Matrix Addition"<<endl;
    for(int i = 0; i<2; i++)
    {
       for(int j=0; j<2; j++)
       {
	  cout<< z.v[i].v[j].Real() <<" " << z.v[i].v[j].Imaginary()<< "    ";
       }
       cout<< endl;
    }

    cout<< "Test for operator == "<<endl;
    if( x == y)
       cout << "Equal"<<endl;
    else
       cout<< "Not Equal"<<endl;

    cout<< "Test for Multiplication"<<endl;
    ComplexMatrix mult= z.Multiplication(x);
    for(int i=0; i<2; i++)
    {
       for(int j=0; j<2 ; j++)
       {
	  cout <<mult.v[i].v[j].Real() << " " <<mult.v[i].v[j].Imaginary() << "    ";
       }
       cout<< endl;
    }

    return 0;
    
}

