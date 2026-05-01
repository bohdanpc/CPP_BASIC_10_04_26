#include <iostream>

void showMenu(bool fullMenu, bool hasKey)
{
    std::cout << "Choose action: (has key : " << hasKey << ")\n";
    std::cout << "1 - Look around\n";

    if (fullMenu)
    {
        std::cout << "2 - Open wardbrobe\n";
        std::cout << "3 - Under the bed\n";
        std::cout << "4 - Try open the door\n";
        std::cout << "5 - Exit\n";
    }
}

unsigned int readChoice()
{
    std::cout << "Choice: ";
    unsigned int choice = 0;
    std::cin >> choice;

    return choice;
}