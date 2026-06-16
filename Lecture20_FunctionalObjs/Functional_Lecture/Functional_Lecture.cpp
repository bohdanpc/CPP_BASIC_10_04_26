#include <iostream>
#include <algorithm>
#include <vector>

int Add(int a, int b)
{
	return a + b;
}

int Multiply(int a, int b)
{
	return a * b;
}

double MultiplyDouble(double a, double b)
{
	return a * b;
}

int ExecuteOperation(int a, int b, int(*functionArg)(int, int))
{
	return functionArg(a, b);
}

bool compare(int a, int b)
{
	return a > b;
}

class Range	//Functor
{
public:
	Range(int min = 0, int max = 0) : m_min(min), m_max(max) {}

	bool operator()(int value) const
	{
		return value >= m_min && value <= m_max;
	}

private:
	int m_min = 0;
	int m_max = 0;
};

bool IsInRange50(int value, int min, int max)
{
	return value >= min && value <= max;
}

int main()
{
	Range speedLimit(0, 50);
	speedLimit(23);	//functional call of the object

	IsInRange50(23, 0, 50);
	IsInRange50(23, 0, 50);

	Range speedLimitInCrossCountry(40, 120);
	speedLimitInCrossCountry(35);


	int (*functionName)(int, int) = nullptr;

	functionName = &Add;

	std::cout << functionName(25, 10);

	functionName = &Multiply;

	std::cout << functionName(10, 10);

	ExecuteOperation(10, 25, &Add);
	ExecuteOperation(10, 25, &Multiply);
	//ExecuteOperation(10, 25, &MultiplyDouble);	//Can't do. function declaration is not compatible

	std::vector<int> array{ 1,5, 2 };

	std::sort(array.begin(), array.end(), compare);
}
