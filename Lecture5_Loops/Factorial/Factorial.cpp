#include <iostream>

int main()
{
	int factorial = 1;
	std::cout << "Factoria to calculate:";
	std::cin >> factorial;

	int result = 1;
	for (int i = 2; i <= factorial; i++)
	{
		result *= i;
	}

	std::cout << factorial << "! = " << result << std::endl;
}