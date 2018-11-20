#include "ComplexMatrix.hh"
#include <iostream>

using namespace ComplexSpace;
using namespace std;

//working
ComplexMatrix::ComplexMatrix(int r, int c)
{
    row = r;
    column = c;
    // we need to decide how are we taking the input. either we are
    // asking the user within this function to input the entire matrix
    // or we pass in the vector<ComplexVector> in this constructor. 
    ComplexNumber a = ComplexNumber(1,2);
    ComplexVector b;
    for(int i=0; i< 2; i++)
       b.Insert(a);
    ComplexVector b1= ComplexVector(b);
     //Testing purpose start
       
       for(int j=0; j< 2; j++)
       {
	  v.push_back(b1);
	  //v[j].v.push_back(a);
       }
       //Testing purpose ends
       
       // actual code that dint work :( 
       /*
	 for(int i = 0; i<r; i++)
	 {
	 v.push_back(ComplexVector());
        for (int j = 0; j < c; j++)
        {
            v[j].v.push_back(ComplexNumber());
	    }
	    }
       */
    
}

//working
ComplexMatrix::ComplexMatrix(std::vector<ComplexVector> k)
{
    v = k;
}

ComplexMatrix::~ComplexMatrix()
{
}
//working
bool ComplexMatrix::CheckDimension(ComplexMatrix A)
{
   //fixed
   if(row == A.Row() && column == A.Column())
      return true;
   else
    return false;
}

bool ComplexMatrix::IsSquare(ComplexMatrix A)
{
    return false;
}

//working
bool ComplexMatrix::operator==(ComplexMatrix A)
{
    if (row == A.Row() && column == A.Column())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (v[i].v[j] == A.v[i].v[j])
                {
                    return true;
                }
            }
        }

        return false;
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
   vector<ComplexVector> newMatrix;
  
   if(Column() == A.Row())
   {
      ComplexVector store;
       for(int i=0; i < Row();i++)
      {
      
	 //cout <<"Row: " << Row() << " Column: " << Column() << endl;
	 ComplexVector a;
	 //ComplexVector store;
	 for(int k =0; k< Row();k++)
	 {
	    
	    ComplexNumber num = A.v[i].v[k];
	    a.v.push_back(num);
	    
 	 }
	 for(int i=0; i< 2; i++)
	    cout<< a.v[i].Real() << " " << a.v[i].Imaginary() << endl;
	 

	 ComplexVector find= ComplexVector(a);
	 for(int j=0; j< Column();j++)
	 { ComplexNumber cnum= v[j].DotProduct(find);
	   
	    store.Insert(cnum);
	 }
	    for(int i=0; i<Column(); i++)
	       cout<<store.v[i].Real() << " " << store.v[i].Imaginary() << "   " ;
	    cout << endl;
	 }
	 
      ComplexVector final = ComplexVector(store);
      newMatrix.push_back(final);

      
   }
   ComplexMatrix temp = ComplexMatrix(newMatrix);
   return temp;
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
