//Task description:
//calculate the summ of all numbers in passed range inclusively
//that are divisible by 3 AND 4

#include <iostream>

int main()
{
    using namespace std;

    unsigned int number1 = 0;
    unsigned int number2 = 0;

    while (true)
    {
        int numbers_sum = 0;
        cout << "Enter range values with space, (0 0) to exit: ";
        cin >> number1 >> number2;

        //Check either we should continue cycle or should finish the task
        const bool exit = !(number1 > 0 && number2 > 0);
        if (exit)
        {
            break;
        }

        cout << "Numbers between " << number1 << " and " << number2 << " inclusively divisible by 3 AND 4: \n";

        for (int i = number1; i <= number2; i++)
        {
            if (i % 3 == 0 && i % 4 == 0)  //0 -> false, 1, 2, -1, -> true
            {
                cout << "+ number " << i << std::endl;
                numbers_sum += i;
            }
        }

        cout << "The final sum is " << numbers_sum << endl << endl << endl;
    }
}
