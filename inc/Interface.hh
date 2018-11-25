
#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <iostream>
#include <string>
#include "ComplexMatrix.hh"



namespace ComplexSpace
{   
   class Interface
   {
   private:
      ComplexMatrix qubits;
      int option;      
      
   public:
      Interface();
       ~Interface();
      int main_option();
      int get_option();
      ComplexMatrix qubit_input(ComplexMatrix a,int input);
      ComplexMatrix ControlNOT_function();
      ComplexMatrix Toffoli_function();
      ComplexMatrix CNOT(ComplexMatrix qubits);
      ComplexMatrix Toffoli(ComplexMatrix qubits);
      //ComplexMatrix parsing(string input);
      void draw();
      
   };
}
#endif



   
