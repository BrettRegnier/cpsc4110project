#pragma once

#include <string>
#include <iostream>

class Console
{
  private:
  public:
	static void Print(std::string msg);
	static void Println(std::string msg);
	static int GetInteger(std::string msg);
	static int GetInteger(std::string msg, int expectedMax);
};