#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	//init only ONCE during program start
	std::srand(std::time(0)); //Use current time as a seed for random generator

	//the same seed value will generate the same sequence for the std::rand() output
	//so using std::time(0) value as it changes over time 

	const int GeneratingRange = 50;	//use your number if needed
	const int generatedNumber = std::rand() % (GeneratingRange + 1); //0 - 50	

	//now use std::rand() as many times as you need

	for (int i = 0; i < 10000; i++)
	{
		std::cout << std::rand() << " ";
	}

	return 0;
}