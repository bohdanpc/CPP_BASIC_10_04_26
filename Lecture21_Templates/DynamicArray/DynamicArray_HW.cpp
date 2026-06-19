#pragma once
#include <cstdlib>

//typename and class keywords can be used interchangeably here
template<typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray<T>& other);   //c-py c-tor, #TODO,change signature if needed

    ~DynamicArray();

    //return *this so a chain of assignment can be supported
    //e.g. DynamicArray a, b, c, d;
    //a = b = c = d;
    DynamicArray& operator=(const DynamicArray<T>& other); //assignment operator

    //validate index always or only in _DEBUG configuration
    //e.g. #ifdef _DEBUG ... #endif
    int& operator[](std::size_t index);
    bool operator==(const DynamicArray<T>& other) const;
    bool operator!=(const DynamicArray<T>& other) const;

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(T element);

    void pop_back();    //remove last element
    T back() const;   //get last element without removal



    //OPTIONAL HARDER PART
    //https://cplusplus.com/reference/vector/vector/reserve/
    //used to allocate more memory then needed right now
    //to greatly decrease number of heap call for memory reallocation
    //and number of operations to copy old data to new memory chunk
    //push_back() method either uses existing preallocated memory, or calls reserve at the right moment
    //to increase the size by x2 of current size
    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;    //returns reserve size. Should be ALWAYS >= then actual size
    //reduce the capacity to fit its size
    //https://cplusplus.com/reference/vector/vector/shrink_to_fit/
    void shrinkToFit();
  
private:
    T* m_rawData;
};

int main()
{
    //Test every method of the DynamicArray in different test cases
}