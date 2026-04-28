#include <iostream>
using namespace std;

int main()
{
    bool running = true;
    bool hasKey = false;
    bool keyTaken = false;
    bool investigatedTheRoom = false;
    int choice;

    cout << "You wake up in a locked room...\n";

    while (running)
    {
        cout << "\nChoose action(has key: " << hasKey << ")\n";
        cout << "1 - Look around\n";

        if (investigatedTheRoom)
        {
            cout << "2 - Open wardrobe\n";
            cout << "3 - Look under the bed\n";
            cout << "4 - Try to open the door\n";
            cout << "5 - Exit\n";
        }

        cout << "Your choice: ";

        cin >> choice;

        cout << "\n";

        switch (choice)
        {
        case 1:
            cout << "A small dark room. A bed, a wardrobe, and a locked door.\n";
            investigatedTheRoom = true;
            break;

        case 2:
            cout << "You open the wardrobe. It's empty.\n";
            break;

        case 3:
            if (!keyTaken)
            {
                cout << "You found a key!\n";
                hasKey = true;
                keyTaken = true;
            }
            else
            {
                cout << "Nothing here.\n";
            }
            break;

        case 4:
            if (hasKey)
            {
                cout << "You unlocked the door and escaped!\n";
                running = false;
            }
            else
            {
                cout << "The door is locked.\n";
            }
            break;

        case 5:
            cout << "You gave up...\n";
            running = false;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout << "\nGame over.\n";
    return 0;
}