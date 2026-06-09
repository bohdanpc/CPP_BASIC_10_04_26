#include <iostream>
#include <string>

class CustomString
{
public:
    CustomString();

    //Rule of THREE, don't forget to implement all 3 
    //if one of them is already needed
    CustomString(const CustomString& str);
    void operator=(const CustomString& str);
    ~CustomString();
    
    unsigned size() const { return m_size; }
    void operator+=(const char* str);

    void show() { std::cout << m_data; }

    //Example usage:
    //CustomString newString = str1 + str2;
    CustomString operator+(const CustomString& other) const
    {
        //#TODO: @students, IMPLEMENT
        //reusing existing methods is a good way to minimize
        //the code's size and reduce possible errors
    }

    bool operator==(const CustomString& other) const
    {
        //#TODO: @students
    }

    bool operator!=(const CustomString& other) const
    {
        //#TODO: @students
    }

    bool find(char c) const
    {
        //#TODO: @students, return true if symbol c was found
    }

private:
    char* m_data = nullptr;
    unsigned m_size = 0;
};


CustomString::CustomString()
{
    m_data = new char[1];
    m_data[0] = '\0';
    m_size = 1;
}

CustomString::~CustomString()
{
    delete[] m_data;
}

void CustomString::operator+=(const char* str)
{
    if (str == nullptr)
    {
        return;
    }

    const unsigned addedSize = std::strlen(str);
    const unsigned newSize = addedSize + m_size;

    char* newData = new char[newSize];
    for (unsigned i = 0; i < m_size - 1; i++)
    {
        newData[i] = m_data[i];
    }

    int j = 0;
    for (int i = m_size - 1; i < newSize; i++)
    {
        newData[i] = str[j++];
    }

    newData[newSize - 1] = '\0';

    delete[] m_data;
    m_data = newData;

    m_size = newSize;
}

//shallow copy by default!
// m_data = str.data !Wrong, only pointers change
// 
//Need to implement custom Constructor
//for the Deep copy of internal dynamic memory
CustomString::CustomString(const CustomString& str)
{
    m_data = new char[str.m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = str.m_data[i];
    }

    m_size = str.m_size;
}

void CustomString::operator=(const CustomString& str)
{
    if (this == &str)
    {
        return;
    }

    char* newData = new char[str.m_size];
    for (unsigned i = 0; i < m_size; i++)
    {
        newData[i] = str.m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_size = str.m_size;
}

int main()
{
    CustomString str;
    str += "abc";
    str += "def";
    str += "!";

    const char* empty = nullptr;
    str += empty;   //Testing empty one
    str.show();

    CustomString str2{ str };//copy c-tor
    str2.show();

    CustomString str3{ };
    str3 += "str3";
    str3.show();

    str3 = str2;    //operator=
    str3.show();
}
