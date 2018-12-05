#include "Interface.hh"
#include <string>
#include <cmath>

using namespace ComplexSpace;
using namespace std;

Interface::Interface()
{
	qubits = ComplexMatrix(0, 0);
}

Interface::~Interface()
{
}

int Interface::main_option()
{
	std::string msg = "\n\n";
	msg += "Select an Option\n";
	msg += "1. Controlled-NOT\n";
	msg += "2. Toffoli Gate\n";
	msg += "3. Deutsch's Algorithm\n";
	msg += "4. Exit";

	option = Console::GetInteger(msg, 4);

	return option;
}

int Interface::get_option()
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
		throw "The inputted qubits were not in proper qubit form";
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
		throw "The inputted qubits were not in proper qubit form";
	}
}
ComplexMatrix Interface::UF(ComplexMatrix qubits)
{
	if (qubits.Row() == 4 && qubits.Column() == 1)
	{
		return ComplexMatrix::UF() * qubits;
	}
	else
	{
		throw "The inputted qubits were not in proper qubit form";
	}
}

int Interface::qubit_input(std::string msg)
{
	std::string m = msg;
	bool waitingInput = true;
	int input;
	while (waitingInput)
	{
		input = Console::GetInteger(m);
		if (input != 0 && input != 1)
			m = "Invalid input\n" + msg;
		else
			waitingInput = false;
	}
	return input;
}

ComplexMatrix Interface::create_qubit(int v)
{
	ComplexMatrix temp = ComplexMatrix(2, 1);
	if (v == 1)
		temp[1][0] = 1;
	else
		temp[0][0] = 1;
	return temp;
}

ComplexMatrix Interface::ControlNOT_function()
{
	ComplexMatrix control_bit;
	ComplexMatrix target_bit;
	int input1;
	int input2;
	input1 = qubit_input("Input the control bit (0 or 1)");
	control_bit = create_qubit(input1);

	input2 = qubit_input("Input the target bit (0 or 1)");
	target_bit = create_qubit(input2);

	ComplexMatrix tensor = ComplexMatrix(4, 1);
	tensor = control_bit.TensorProduct(target_bit);

	ComplexMatrix result = ComplexMatrix(4, 1);
	result = CNOT(tensor);
	Console::Println("");
	Console::Println("CNOT OPERATION");
	string o = "|" + std::to_string(input1) + "> CNOT |" + std::to_string(input2) + "> is:";
	Console::Println(o);

	return result;
}

ComplexMatrix Interface::Toffoli_function()
{
	ComplexMatrix control_bit1;
	ComplexMatrix control_bit2;
	ComplexMatrix target_bit;
	int input1;
	int input2;
	int input3;

	input1 = qubit_input("Input the first control bit (0 or 1)");
	control_bit1 = create_qubit(input1);

	input2 = qubit_input("Input the second control bit (0 or 1)");
	control_bit2 = create_qubit(input2);

	input3 = qubit_input("Input the target bit (0 or 1)");
	target_bit = create_qubit(input3);

	ComplexMatrix tensor1;
	tensor1 = control_bit1.TensorProduct(control_bit2);

	ComplexMatrix tensor2;
	tensor2 = tensor1.TensorProduct(target_bit);

	ComplexMatrix result = ComplexMatrix(8, 1);
	result = Toffoli(tensor2);
	Console::Println("");
	Console::Println("TOFFOLI OPERATION");
	string o = "|" + std::to_string(input1) + "> XOR ( |" + std::to_string(input2) + "> AND |" + std::to_string(input3) + "> ) is:";
	Console::Println(o);
	return result;
}

void Interface::Deutsch()
{
	int fx;
	int fy;

	ComplexMatrix result;
	ComplexMatrix target = create_qubit(0);
	ComplexMatrix control = create_qubit(1);

	target = ComplexMatrix::Hadamard() * target;
	control = ComplexMatrix::Hadamard() * control;

	fx = Console::GetInteger("Please enter f(0)");
	fy = Console::GetInteger("Please enter f(1)");

	// Perform the following equation
	// (-1)f(x)|x> ⊗ (1/√2^)*(|0> - |1>)
	ComplexNumber scalefx = pow(-1, fx);
	ComplexNumber scalefy = pow(-1, fy);

	// apply fx on first state
	target[0][0] = target[0][0] * scalefx;

	// apply fy on second state
	target[1][0] = target[1][0] * scalefy;

	// Apply another Hadamard gate to the target
	target = ComplexMatrix::Hadamard() * target;

	Console::Print("\n/****************************/");
	Console::Println("\nTarget qubit \n" + target.ToString());
	Console::Println("Control qubit \n" + control.ToString());
	if (target[0][0].Real() > 0 || target[0][0].Real() < 0)
	{
		Console::Println("F is constant");
	}
	else if (target[1][0].Real() > 0 || target[1][0].Real() < 0)
	{
		Console::Println("F is balanced");
	}
	Console::Print("/****************************/");
}
