#include <iostream>
#include <algorithm>    //binary_search, sort
#include <functional>   //std::greater, std::less

int sum(int arr[], int size)		//4 * size bytes for arr + 8 byte for pointer variable
{
    int sum = 0;					// 4 bytes for sum
    for (int i = 0; i < size; i++)	// 4 bytes for i
    {
        sum += arr[i];
    }

    return sum;
}

//N-1 + N-2 + N-3 + N-4 ... 1 = N/2 * (N+1) = O(N^2)
void selectionSort(int arr[], unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        unsigned int min_idx = i;

        for (unsigned int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            std::swap(arr[min_idx], arr[i]);
    }
}


int partition(int array[], int low, int high)
{
    int pivot = array[high];

    // idx of greater element
    int pointerIdx = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            pointerIdx++;

            // swap element at i with element at j
            std::swap(array[pointerIdx], array[j]);
        }
    }

    std::swap(array[pointerIdx + 1], array[high]);
    return (pointerIdx + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int partition_idx = partition(array, low, high);    //sort around pivotPoint
        quickSort(array, low, partition_idx - 1);
        quickSort(array, partition_idx + 1, high);
    }
}

//Using pointer arithmetics - similar interface as of std::sort
void quickSort2(int* arrayBeg, int* arrayEnd)
{
    const int size = arrayEnd - arrayBeg;
    quickSort(arrayBeg, 0, size - 1);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    constexpr unsigned int SIZE = 10;
    int arr[SIZE] = { 22, 31 , 5, 7, 3, 2, 9, 1, 6, 10 };
     
    quickSort(arr, 0, SIZE - 1);
    print(arr, SIZE);

    //custom linear find
    int* found = std::find(arr, arr + SIZE, 5);
    
    if (found != nullptr)
    {
        std::cout << "Found with lienar search element: " << * found << std::endl;
    }
    //Built-in Binary Search, works ONLY for sorted arrays
    std::cout << "Found with binary search: " << std::binary_search(arr, arr + SIZE, 22) << std::endl;

    //Quick sort with pretier interface
    quickSort2(arr, arr + SIZE);


    //IntroSort //  https://www.geeksforgeeks.org/introsort-cs-sorting-weapon/
    std::sort(arr, arr + SIZE);
    std::sort(arr, arr + SIZE, std::less<int>());   //or std::greater<int>());  -> using functions as parameters (?_?) (Lecture 22)

    print(arr, SIZE);

    return 0;

}

