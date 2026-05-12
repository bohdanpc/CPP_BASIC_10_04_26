#include <iostream>

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

/*
* Please, don't input, output your array here
* The sole purpose of this function is to
* return the result of the search, nothing else (aka Single Responsibility Principle from SOLID)
*/
bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    //#TODO, implement your code here
    return true;
}

//#2_1
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    //#TODO
    //Output result into std::cout
}

//#2_2 (Optional)
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    //#TODO
   //Output result into std::cout
}


int main()
{
    int arr_2d[ROWS][COLUMNS] = {
      {11, 12, 13, 14, 15, 16 },
      {21, 22, 23, 24, 25, 26 },
      {31, 32, 33, 34, 35, 36 },
      {41, 42, 43, 44, 45, 46 }
    };

    std::cout << find(arr_2d, 24);

    traverseTopDownRightLeftByColumns(arr_2d);
    traverseLeftRightDownTopSwitchingByRows(arr_2d);

    return 0;
}
