#include <vld.h>
#include <iostream>

int* allocateRandomMemory(int size)
{
    int* memoryInt = new int[size];
    for (int i = 0; i < size; i++)
    {
        memoryInt[i] = i;
    }
    return memoryInt;
}

void func()
{
    int* randomMemoryPointer = allocateRandomMemory(30);    //30 * sizeof(int) = 30 * 4
    int* randomMemoryPointer2 = allocateRandomMemory(20);   // 20 * 4 bytes

    //WOrk with it

    //delete
}

int main()
{
    func();

    int* addressFromP3 = static_cast<int*>(0xfa234312aa);


    //
}

