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

int Console::GetInteger(std::string msg, int expectedMax)
{
	int in = -1;
	Println(msg);
	Print("> ");
	std::cin >> in;
	
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		Println(msg);
		Print("> ");
		std::cin >> in;
	}
	return in;
}