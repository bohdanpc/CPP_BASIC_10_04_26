#include <iostream>

//PREPROCESSING -> Preprocessor replaces all #includes with actual content of the files

#include "Header.h"
#include "MathConst.h"


void add(int* to, int value)
{
    if (to == nullptr)
    {
        return;
    }

    *to += value;   //0xAAAA -> 15
}

void updateArray(int* arr, int size)
{
    arr = arr + 2;  //&arr[2]
    arr -= 1;       //&arr[1]
}

void printArrayAsPointer(int* arr, int size)
{
    int* end = arr + size - 1;
    while (end != arr - 1)
    {
        std::cout << *end << std::endl;
        --end;
    }
}


int main()
{
    printNumber(3);
}
