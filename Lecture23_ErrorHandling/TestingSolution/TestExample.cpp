#include <iostream>
#include <iomanip>

bool isEqual(const char* str1, const char* str2)
{
    if (strlen(str1) == strlen(str2))
    {
        return true;
    }

    return false;
}

//Using it is faster and easier to validate current implementation of the algorithm
//without need of constant std::cin reenter of input data
void VALIDATE_IS_EQUAL(const char* str1, const char* str2, bool expected)
{
    static unsigned TestCaseNumber = 1;

    const bool equal = isEqual(str1, str2);

    std::cout << "Test case #" << TestCaseNumber << ": ";
    std::cout << std::setw(8) << std::left << ((equal == expected) ? "SUCCESS" : "FAIL");

    std::cout << " ----- comparing " << str1 << " == " << str2 << " -> " << equal << ", expected " << expected << std::endl;

    TestCaseNumber++;
}

int main()
{
    VALIDATE_IS_EQUAL("abc", "dcefa", false);
    VALIDATE_IS_EQUAL("abc", "abc", true);
    VALIDATE_IS_EQUAL("abc", "abd", false);
    VALIDATE_IS_EQUAL("abc", "abcf", false);
    VALIDATE_IS_EQUAL("abc", "ABC", false);
    VALIDATE_IS_EQUAL("", "", true);
}
