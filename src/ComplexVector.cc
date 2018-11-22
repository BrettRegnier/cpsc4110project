#include "ComplexVector.hh"
#include <iostream>

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

ComplexNumber& ComplexVector::operator[](int idx)
{
    // error checking?
    return v[idx];
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
        for (int i = 0; i < size(); i++)
        {
            temp.Insert(A[i].Conjugate() * (*this)[i]);
            num = num + temp[i];
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
       temp.v.push_back(v[i].Conjugate());
       //temp.v[i] = v[i].Conjugate();
    }
    return temp;
}

void ComplexVector::Insert(ComplexNumber b)
{
    v.push_back(b);
}

int ComplexVector::size()
{
    return v.size();
}

std::string ComplexVector::ToString()
{
    std::string msg = "| ";
    for (int i = 0; i < size(); i++)
    {
        msg += v[i].ToString() + " | ";
    }

    return msg;
}
