#include "Console.hh"

void Console::Print(std::string msg)
{
	std::cout << msg; 
}

void Console::Println(std::string msg)
{
	Print(msg);
	std::cout << std::endl;
}

int Console::GetInteger(std::string msg)
{
	int in;
	Println(msg);
	Print("> ");
	std::cin >> in;
	return in;
}