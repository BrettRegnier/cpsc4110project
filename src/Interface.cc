#include "Interface.hh"
#include <string>
#include <cmath>

using namespace ComplexSpace;
using namespace std;

Interface::Interface()
{
qubits = ComplexMatrix(0,0);
}

Interface::~Interface()
{
}


int Interface:: main_option()
{
   cout<< endl;
   cout << "Select an Option" << endl;
   cout << "1. Controlled-NOT " << endl;
   cout << "2. Toffoli Gate " << endl;
   cout << "3. Deutsch's Algorithm " << endl;

   cin >> option;
   return option;
}

int Interface:: get_option()
{
   return option;
}

ComplexMatrix Interface::CNOT(ComplexMatrix qubits)
{
	if (qubits.Row() == 4 && qubits.Column() == 1)
	{
    	return ComplexMatrix::CNOT() * qubits;
	}
	else
	{
		// error
	}
}
ComplexMatrix Interface::Toffoli(ComplexMatrix qubits)
{
	if (qubits.Row() == 8 && qubits.Column() == 1)
	{
     	return ComplexMatrix::Toffoli() * qubits;
	}
	else
	{
		// error
	}
}
ComplexMatrix Interface:: UF(ComplexMatrix qubits)
{
	if (qubits.Row() == 4 && qubits.Column() == 1)
	{
		return ComplexMatrix::UF() * qubits; 
	}
	else
	{
		// error
	}
}


ComplexMatrix Interface::qubit_input(ComplexMatrix a, int input)
{
   ComplexMatrix temp =a;
   if(input == 1)
      temp[1][0] =1;
   else
      temp[0][0]=1;
   return temp;
}

ComplexMatrix Interface:: ControlNOT_function()
{
   ComplexMatrix control_bit = ComplexMatrix(2,1);
   ComplexMatrix target_bit = ComplexMatrix(2,1);
   int input1;
   int input2;

  control:
   cout << "Input the control bit" << endl;
   cin>> input1;
   if(input1 != 0 && input1 !=1)
   {
      cout<< "Please insert either 1 or 0" << endl<<endl;
      goto control;
   }
   control_bit = qubit_input(control_bit, input1);
   
  target:
   cout << "Input the target bit" <<endl;
   cin>>input2;
   if(input2 != 0 && input2 != 1)
   {
      cout << "Please insert either 1 or 0" << endl << endl;
      goto target;
   }
   target_bit = qubit_input(target_bit, input2);
   
   ComplexMatrix tensor = ComplexMatrix(4,1);
   tensor= control_bit.TensorProduct(target_bit);

   ComplexMatrix result= ComplexMatrix(4,1);
   result= CNOT(tensor);
   cout<<endl;
   cout << "|" << input1 << " > CNOT |" << input2 << ">"<<endl;
   
   return result;
   
}

ComplexMatrix Interface:: Toffoli_function()
{
   ComplexMatrix control_bit1 = ComplexMatrix(2,1);
   ComplexMatrix control_bit2 = ComplexMatrix(2,1);
   ComplexMatrix target_bit = ComplexMatrix(2,1);
   int input1;
   int input2;
   int input3;

  control1:
   cout << "Input the first control bit" << endl;
   cin>> input1;
   if(input1 !=0 & input1 != 1)
   {
      cout << "Please insert either 1 or 0" << endl << endl;
      goto control1;
   }
   control_bit1 = qubit_input(control_bit1, input1);

  control2:
   cout << "Input the second control bit"<<endl;
   cin>>input2;
   if(input2 !=0 & input2 !=1)
   {
      cout << "Please insert either 1 or 0" << endl << endl;
      goto control2;
   }
   control_bit2 = qubit_input(control_bit2, input2);

  target:
   cout << "Input the target bit" <<endl;
   cin>>input3;
   if(input3 != 0 & input3 !=1)
   {
      cout << "Please insert either 1 or 0" <<endl << endl;
      goto target;
   }
   target_bit = qubit_input(target_bit, input3);

   ComplexMatrix tensor1 = ComplexMatrix(4,1);
   tensor1= control_bit1.TensorProduct(control_bit2);

   ComplexMatrix tensor2 = ComplexMatrix(8,1);
   tensor2 =tensor1.TensorProduct(target_bit);

   ComplexMatrix result= ComplexMatrix(8,1);
   result= Toffoli(tensor2);
   cout<<endl;
   cout<<"TOFFOLI OPERATION" <<endl;
   cout<< "|" <<input1 << " > XOR " << "( |" << input2 << " > AND |" <<input3<< " > )" <<endl;
   return result;
 
}

ComplexMatrix Interface::UF_function()
{
	try 
	{
		ComplexMatrix control_bit = ComplexMatrix(2,1);
		ComplexMatrix target_bit = ComplexMatrix (2,1);
		ComplexMatrix tensor_matrix;
		ComplexMatrix temp;
		
		control_bit = qubit_input(control_bit, 0);
		target_bit = qubit_input(target_bit, 1);
		
		control_bit = ComplexMatrix::Hadamard() * control_bit;
		target_bit = ComplexMatrix::Hadamard() * target_bit;
		
		// (-1)^f(x)|x> (x) 1^(1/2)*(|0> - |1>)
		int fx;
		int fy;
		cout << "Please insert the f(0) " <<endl;
		cin >> fx;
		cout << "Please insert the f(1) " <<endl;
		cin >> fy;
		
		target_bit = control_bit.TensorProduct(control_bit);
		
		ComplexMatrix uf = ComplexMatrix(4, 4);
		if (fx == 0 && fy == 0)
		{
			uf[0][0] = 1;
			uf[1][1] = 1;
			uf[2][2] = 1;
			uf[3][3] = 1;
		}
		
		target_bit = uf * target_bit;
		
		ComplexMatrix HI = ComplexMatrix::Hadamard().TensorProduct(ComplexMatrix::Identity());
		target_bit = HI * target_bit;
		
		// 4 cases
		// if f(0) = f(1) = 0
		// if f(0) = f(1) = 1
		// if f(0) = 0 and f(1) = 1
		// if f(0) = 1 and f(1) = 0
		
		// Take
		
		// f is constant
		// ComplexMatrix deutsch = ComplexMatrix(2, 1);
		// deutsch[0][0] = ComplexNumber(pow((-1), fx)) * control_bit[0][0];
		// deutsch[1][0] = ComplexNumber(pow((-1), fy)) * control_bit[1][0];
		
		// deutsch = ComplexMatrix::Hadamard() * deutsch;
		
   		// return deutsch;
		   
		return target_bit;
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
}
