#include <iostream>

int main()
{
    //Get initial Npcs from the Level info
    int health1 = 100;
    int health2 = 100;

    //Game level loop
    while (true)
    {
        int npcNumber = 0;
        std::cout << "Select npc to shoot: ";
        std::cin >> npcNumber;
        std::cout << std::endl;

        if (npcNumber == 1)
            health1 -= 10;
        else if (npcNumber == 2)
            health2 -= 10;
        else
        {
            std::cout << "Missed!\n";
            continue;
        }

        bool isDeadNpc1 = health1 <= 0;
        bool isDeadNpc2 = health2 <= 0;

        const bool isAllNpcDead = isDeadNpc1 && isDeadNpc2;

        if (isAllNpcDead)
        {
            std::cout << "Level cleared! Proceed to next mission's task\n";
            break;
        }
    }

    std::cout << "Starting level 2...\n";

    return 0;
}
