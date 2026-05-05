#include <iostream>

int calculate_average(int array[], unsigned SIZE)
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i];
    }

    // the result of division may be rational, 
    // but we don't really care for rational part in the integer-like evaluation system
    return sum / SIZE;
}

int getSizeOfArray(int array[])
{
    //return 8 bytes always, the size of computer address
    return sizeof(array);
}

void createArray()
{
    double positions[] = { 3.0, 5.0, 10.0 };    //3 elements * 8 byte of double = 24

    std::cout << sizeof(positions) << std::endl;
}

bool isLineAllLetters(const char line[])
{
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (!std::isalpha(line[i]))
        {
            return false;
        }
    }

    return true;
}

void toUpperCase(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= ('a' - 'A');  //see ASCII table
        }
    }
}

void array_2d()
{
    int table[3][4] = { 1, 5, 6, 7,
                       2, 7, 1, 2,
                       3, 6, 7 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const unsigned NAME_SIZE = 6;
    char name[NAME_SIZE] = { 'B', 'o', 'h', 'd', 'a', 'n' };

    for (int i = 0; i < NAME_SIZE; i++)
    {
        std::cout << name[i];
    }

    // -> In short

    char name2[] = "Bohdan";    // same as -> {'B', 'o', 'h', 'd','a','n', '\0'}
    std::cout << name2;
}
