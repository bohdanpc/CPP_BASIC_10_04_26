#include <iostream>

//Simple recursion, see debug and callstack for more explanation
void printNumber(int number)
{
	if (number < 0)
	{
		return;
	}

	std::cout << "Before recursive call (number == " << number << ")" << std::endl;

	printNumber(number - 1);

	std::cout << "After recursive call (number == " << number << ")" << std::endl;
}