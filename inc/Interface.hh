#pragma once

#include <iostream>
#include <string>
#include "Console.hh"
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
		int qubit_input(std::string msg);
		ComplexMatrix create_qubit(int v);
		ComplexMatrix ControlNOT_function();
		ComplexMatrix Toffoli_function();
		ComplexMatrix CNOT(ComplexMatrix qubits);
		ComplexMatrix Toffoli(ComplexMatrix qubits);
		ComplexMatrix UF(ComplexMatrix qubits);
		ComplexMatrix UF_function();
		void Deutsch();

		//ComplexMatrix parsing(string input);
		void draw();
	};
}