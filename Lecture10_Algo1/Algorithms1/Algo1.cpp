#include <iostream>

const unsigned GAMES_NUMBER = 2;
const unsigned DAYS_NUMBER = 7;

float getMaxTimePlayedInDay(float timeInGameArray[GAMES_NUMBER][DAYS_NUMBER], int& day)
{
	float maxTimePerDay = 0.0f;
	for (int j = 0; j < DAYS_NUMBER; j++)
	{
		float timePlayedPerDay = 0;
		for (int i = 0; i < GAMES_NUMBER; i++)
		{
			timePlayedPerDay += timeInGameArray[i][j];
		}

		if (timePlayedPerDay > maxTimePerDay)
		{
			day = j;
			maxTimePerDay = timePlayedPerDay;
		}
	}

	return maxTimePerDay;
}

//Divide and Conquer
bool binarySearch(int arr[], unsigned size, int elem)
{
	int left = 0;
	int right = size - 1;
	
#ifdef _DEBUG
	int operationsCount = 0;
#endif 

	while (left <= right)
	{
		int m = left + (right - left) / 2;

#ifdef _DEBUG
		operationsCount++;
#endif

		if (arr[m] == elem)
		{
#ifdef _DEBUG
			std::cout << "Operations count: " << operationsCount << std::endl;
#endif
			return true;
		}

		if (arr[m] > elem)
		{
			right = m - 1;
		}
		else
		{
			left = m + 1;
		}
	}

#ifdef _DEBUG
	std::cout << "Operations count: " << operationsCount << std::endl;
#endif
	return false;
}

//ascending, a[0] < a[1]
enum class SortingDirection
{
	ascending,
	descending
};

bool isSorted(int arr[], int size, SortingDirection direction)
{
	//Don't forget, size-1 is the right one to not go over the array in arr[i+1]
	for (int i = 0; i < size - 1; i++)
	{
		if (direction == SortingDirection::ascending)
		{
			if (arr[i + 1] < arr[i])
			{
				return false;
			}
		}
		else
		{
			if (arr[i + 1] > arr[i])
			{
				return false;
			}
		}
	}

	return true;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,10,12,14,15,17 };

	std::cout << binarySearch(arr, sizeof(arr) / sizeof(int), 17) << std::endl;
	std::cout << binarySearch(arr, sizeof(arr) / sizeof(int), 1) << std::endl;;
	std::cout << binarySearch(arr, sizeof(arr) / sizeof(int), 4) << std::endl;;
	std::cout << binarySearch(arr, sizeof(arr) / sizeof(int), 8) << std::endl;;
	std::cout << binarySearch(arr, sizeof(arr) / sizeof(int), 26) << std::endl;;

	const unsigned GAMES_NUMBER = 2; 
	const unsigned DAYS_NUMBER = 7;
	float timeInGame[GAMES_NUMBER][DAYS_NUMBER] =
	{
		{1,2,3,3,4,5,3},
		{3,4,1,3,1,5,1},
	};

	int dayNumber = -1;
	getMaxTimePlayedInDay(timeInGame, dayNumber);
	
	std::cout << "Day most played: " << dayNumber << std::endl;
}
