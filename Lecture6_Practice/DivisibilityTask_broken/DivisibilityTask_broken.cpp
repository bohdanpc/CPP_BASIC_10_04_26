// Lecture7_DivisibleTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Task description:
//calculate the summ of all numbers in passed range
//that are divisible by 9 AND 5

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cerr;
using std::endl;
using std::cout;

int main()
{
    using namespace std;

    int i, numbers_sum = 0;

    std::cout << i;

    int number1 = 0;
    int number2 = 0;

    bool notExitCondition = true;
    while (notExitCondition == true)
    {

        //The range (number_from - number_to) is read from input
        cout << "Enter range values with space, (0 0) to exit: ";
        cin >> number1 >> number2;

        //Check either we should continue cycle or should finish the task
        notExitCondition = (number1 = 0 && number2 == 0) ? false : true;


        cout << "Numbers between " << number1 << " and " <<
            number2 << " inclusively divisible by 9 AND 5: \n";

        //Iterate all numbers from number1 to Number2
        for (i = number1; i < number2; ++i)
        {
            //Check if number is divisible by 9
            if (i % 9)
                //Check if number is divisible by 5
                if (!(i % 5 != 0))
                    std::cout << "+ numbr " << i << std::endl;
                    numbers_sum += i; 
        }
        std::cout << "The final sum is " << numbers_sum << endl << endl << endl;
    }
}   //End of main function

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file