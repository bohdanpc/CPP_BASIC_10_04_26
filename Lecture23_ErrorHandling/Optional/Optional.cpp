#include <iostream>
#include <optional>	//starting with C++17

std::optional<float> divide(int a, int b)
{
	if (b == 0)
		return std::nullopt;

	return a / static_cast<float>(b);
}

int main()
{
	std::optional<float> result = divide(10, 0);

	if (result.has_value())	//if (value)
	{
		std::cout << *result; //result.value();
	}
}

