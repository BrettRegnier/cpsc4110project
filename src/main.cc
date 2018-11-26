#include "ComplexMatrix.hh"
#include "Interface.hh"
#include <iostream>
#include <stdlib.h> // rand
#include <time.h>

using namespace ComplexSpace;
using namespace std;

ComplexNumber CreateNumber()
{
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
    ComplexVector vec = ComplexVector(elements);
    for (int i = 0; i < elements; i++)
    {
        vec[i] = CreateNumber();
    }

    return vec;
}

ComplexMatrix CreateMatrix(int r, int c, bool hermitian = false, bool unitary = false)
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
/*
  Shah ; I had to remove it to the Interface class since it was used
  by the functions there/ 
ComplexMatrix CNOT(ComplexMatrix qubits)
{
    if (qubits.Row() == 4 && qubits.Column() == 1)
    {
        ComplexMatrix cnot = ComplexMatrix(4, 4);
        cnot[0][0] = ComplexNumber(1);
        cnot[1][1] = ComplexNumber(1);
        cnot[2][3] = ComplexNumber(1);
        cnot[3][2] = ComplexNumber(1);
        return cnot * qubits;
    }
    else
    {
        // error
    }
}

ComplexMatrix Toffoli(ComplexMatrix qubits)
{
    if (qubits.Row() == 8 && qubits.Column() == 1)
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

        return toffoli * qubits;
    }
    else
    {
        // error
    }
}
*/
int main()
{
   Interface a=Interface();

   cout <<"QUAUNTUM PROJECT" << endl << endl;
   //a.main_option() ;
   while(a.main_option())
   {
      switch(a.get_option())
      {
	 case 1:
	 {
	    ComplexMatrix result = ComplexMatrix(4,1);
	    result = a.ControlNOT_function();
	    cout<< result.ToString();
	    break;
	 }
	 case 2:
	 {
	    ComplexMatrix result2 = ComplexMatrix (8,1);
	    result2 = a.Toffoli_function();
	    cout<< result2.ToString();
	    
	    break;
	 }
	 case 3:
	 {  // Deutsch's algorithm function
	    break;
	 }
	 default:
	    break;
      }
   }
   
   return 0;
   

    // needed for random number seed.
/*    srand(time(NULL)); 
       
    ComplexNumber a = ComplexNumber(1, 2);
    ComplexNumber b = ComplexNumber(2, 2);

    ComplexNumber c = a.Add(b);
    cout << "ComplexNumber Addition" << endl;
    cout << c.ToString() << endl<<endl;
    
    cout << "ComplexNumber Modulus"<< endl;
    cout << a.Modulus() << endl<<endl;

    cout << "ComplexNumber Conjugate" << endl;
    cout << a.Conjugate().ToString() << endl<<endl;

    ComplexVector x = ComplexVector(2);
    x.v[0] = a;
    x.v[1] = b;
    ComplexVector y = ComplexVector(2);
    y.v[0] = ComplexNumber(1,1);
    y.v[1] = ComplexNumber(1,0);
    
    std::vector<ComplexVector> j;
    j.push_back(x);
    j.push_back(y);

    cout <<"ComplexVector Addition " << endl;
    ComplexVector result = y.Add(x);
    cout<< result.ToString() << endl<<endl;

    cout<< "ComplexVector DotProduct" << endl;
    ComplexNumber result_mult = y.DotProduct(x);
    cout << result_mult.ToString() << endl << endl;

    cout << "Add Vector ComplexVector Conjugate" << endl;
    cout << result.Conjugate().ToString()<<endl;
       
    ComplexMatrix A = ComplexMatrix(j);

    ComplexVector p = ComplexVector(1);
    p.v[0] = a;
    ComplexVector o = ComplexVector(1);
    o.v[0] = ComplexNumber(1,1);
    std::vector<ComplexVector> k;
    k.push_back(p);
    k.push_back(o);
    
    ComplexMatrix B = ComplexMatrix(k);
    cout<< "Complex Vecor " << endl;
    cout << x.ToString() << endl << endl;

    cout << "Matrix A" << endl;
    cout << A.ToString() << endl << endl;
    cout << "Matrix B" << endl;
    cout << B.ToString() << endl << endl;


    // ComplexMatrix C = ComplexMatrix(2, 3);
    // cout << C.ToString() << endl << endl;

    cout << "A rows = " << A.Row() << " columns = " << A.Column() << endl;
    cout << "B rows = " << B.Row() << " columns = " << B.Column() << endl;

    cout << "A + A = " << endl;
    cout << A.Add(A).ToString()<<endl;
    cout << "A * B = " << endl;
    cout << A.Multiplication(B).ToString()<<endl;

    
    cout << "A Transpose " <<endl;
    cout << A.Transpose().ToString()<< endl;

    cout << "A Conjugate()" <<endl;
    cout << A.Conjugate().ToString() <<endl;

    cout <<"A Adjoint" << endl;
    cout << A.Adjoint().ToString() << endl;

    cout <<"Scalar Mult" <<endl;
    cout <<A.Scalar_Mult(c).ToString()<<endl;
    
    cout << "A Tensor Product B" << endl;
    cout << A.TensorProduct(B).ToString() <<endl;

    cout << "generated number " << CreateNumber().ToString() << endl;
    cout << "generated vector " << CreateVector(2).ToString() << endl;
    cout << "generated matrix " << endl << CreateMatrix(2,2).ToString() << endl;

    ComplexMatrix tenA = ComplexMatrix(2,1);
    tenA[0][0] = CreateNumber(1, 0);
    tenA[1][0] = CreateNumber(-1, 2);

    ComplexMatrix tenB = ComplexMatrix(1,2);
    tenB[0][0] = CreateNumber(3, 1);
    tenB[0][1] = CreateNumber(3, 0);
    cout << tenA.ToString() << endl;
    cout << tenB.ToString() << endl;

    cout << "tenA Tensor Product tenB" << endl;
    cout << tenA.TensorProduct(tenB).ToString() << endl;

    ComplexMatrix basis00 = ComplexMatrix(4, 1);
    basis00[0][0] = ComplexNumber(1, 0);
    cout << "2 Qubit matrix in super position |00>" << endl;
    cout << basis00.ToString() << endl;
    cout << "CNOT of |00>" << endl;
    cout << CNOT(basis00).ToString() << endl;

    ComplexMatrix basis01 = ComplexMatrix(4, 1);
    basis01[1][0] = ComplexNumber(1, 0);
    cout << "2 Qubit matrix in super position |01>" << endl;
    cout << basis01.ToString() << endl;
    cout << "CNOT of |01>" << endl;
    cout << CNOT(basis01).ToString() << endl;

    ComplexMatrix basis10 = ComplexMatrix(4, 1);
    basis10[2][0] = ComplexNumber(1, 0);
    cout << "2 Qubit matrix in super position |10>" << endl;
    cout << basis10.ToString() << endl;
    cout << "CNOT of |10>" << endl;
    cout << CNOT(basis10).ToString() << endl;

    ComplexMatrix basis11 = ComplexMatrix(4, 1);
    basis11[3][0] = ComplexNumber(1, 0);
    cout << "2 Qubit matrix in super position |11>" << endl;
    cout << basis11.ToString() << endl;
    cout << "CNOT of |11>" << endl;
    cout << CNOT(basis11).ToString() << endl;

    ComplexMatrix basis110 = ComplexMatrix(8, 1);
    basis110[6][0] = ComplexNumber(1, 0);
    cout << "3 Qubit matrix in super position |110>" << endl;
    cout << basis110.ToString() << endl;
    cout << "toffoli of |110>" << endl;
    cout << Toffoli(basis110).ToString() << endl;

    ComplexMatrix basis111 = ComplexMatrix(8, 1);
    basis111[7][0] = ComplexNumber(1, 0);
    cout << "3 Qubit matrix in super position |111>" << endl;
    cout << basis111.ToString() << endl;
    cout << "toffoli of |111>" << endl;
    cout << Toffoli(basis111).ToString() << endl;
    
  
    
    return 0;
*/  
}



