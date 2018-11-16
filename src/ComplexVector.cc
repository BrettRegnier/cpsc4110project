#include "ComplexVector.hh"

using namespace ComplexSpace;

ComplexVector::ComplexVector(std::vector<ComplexNumber> k)
{
    v = k;
}

ComplexVector::ComplexVector(int s) 
{
    for (int i = 0; i < s; i++)
    {
        v.push_back(ComplexNumber());   
    }
}

ComplexVector::ComplexVector()
{
    v = std::vector<ComplexNumber>();
}

ComplexVector::~ComplexVector()
{
}


ComplexVector ComplexVector::Add(ComplexVector A)
{
    ComplexVector temp = ComplexVector();
  
   if (size() == A.size())
   {
      for(int i=0; i< A.size(); i++)
      {
	 temp.Insert( A.v[i].Add(v[i]));
      }           
   }
   else
   {
      //error
   }
   
   return temp;
}

ComplexNumber ComplexVector::DotProduct(ComplexVector A)
{
    ComplexVector temp = ComplexVector();
    ComplexNumber num = ComplexNumber();
    if (size() == A.size())
    {
        for (int i = 0; i < v.size(); i++)
        {
            temp.Insert(A.v[i].Product(v[i]));
            num = num.Add(temp.v[i]);
        }
    }
    else
    {
        //error
    }

    return num;
}

ComplexVector ComplexVector::Conjugate()
{
    ComplexVector temp = ComplexVector();
    for (int i = 0; i < v.size(); i++)
    {
        temp.v[i] = v[i].Conjugate();
    }
}

void ComplexVector::Insert(ComplexNumber b)
{
    v.push_back(b);
}

int ComplexVector::size()
{
    return v.size();
}
