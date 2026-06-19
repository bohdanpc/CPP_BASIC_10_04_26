#include <iostream>
#include <vector>
#include "Vector2d.h"
#include "VectorNd.h"

template<class T>
T max(T a, T b)
{
	return a > b ? a : b;
}

//template specialization
//special case for const char*
template<>
const char* max(const char* str1, const char* str2)
{
	return (std::strlen(str1) > std::strlen(str2)) ? str1 : str2;
}

//to have the ability for 2 different types
template<class T, class U>
bool isEqual(T a, U b)
{
	return a == b;
}

int main()
{
	std::vector<int> m_array1;
	std::vector<double> m_arrayDouble;

	VectorNd<int, 3> Vector3d;
	VectorNd<double, 10> vector10dDouble;

	Vector2d<int> positionOfPlayer;
	Vector2d<int> positionOfPlayer2;
	int length = positionOfPlayer.GetLength();

	Vector2d<double> precisePosition;
	double lengthPrecise = precisePosition.GetLength();


	std::cout << max("abc", "d");
	std::cout << max(5.0, 24.1);

	std::cout << max<double>(5.0, 3.0f);

	std::cout << isEqual(95, 'c');
	std::cout << isEqual<int, char>(91, 'a');
}
