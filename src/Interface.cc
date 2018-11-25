#include "Interface.hh"
#include <string>

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
ComplexMatrix Interface::Toffoli(ComplexMatrix qubits)
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
   cout << "Input the control bit" << endl;
   cin>> input1;
   control_bit = qubit_input(control_bit, input1);
   
   
   cout << "Input the target bit" <<endl;
   cin>>input2;
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
   
   cout << "Input the first control bit" << endl;
   cin>> input1;
   control_bit1 = qubit_input(control_bit1, input1);

   cout << "Input the second control bit"<<endl;
   cin>>input2;
   control_bit2 = qubit_input(control_bit2, input2);

   cout << "Input the target bit" <<endl;
   cin>>input3;
   target_bit = qubit_input(target_bit, input3);

   ComplexMatrix tensor1 = ComplexMatrix(4,1);
   tensor1= control_bit1.TensorProduct(control_bit2);

   ComplexMatrix tensor2 = ComplexMatrix(8,1);
   tensor2 =tensor1.TensorProduct(target_bit);

   ComplexMatrix result= ComplexMatrix(8,1);
   result= Toffoli(tensor2);
   cout<<endl;
   cout<<"TOFFOLI OPERATION" <<endl;
   cout<< "|" <<input1 << " > XOR " << "( |" << input2 << " > AND |" <<input3<< " >" <<endl;
   return result;
 
}
