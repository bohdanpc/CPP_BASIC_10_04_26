#include <iostream>
#include <cmath>
#include <iomanip>

#include "UI.h"
#include "GameplayElements.h"



int main()
{
    //States variables    
    bool roomInvestigated = false;
    bool hasKey = false;
    bool isGameRunning = true;

    //Game loop
    while (isGameRunning)
    {
        showMenu(roomInvestigated, hasKey);
        unsigned int choice = readChoice();

        if (choice == 1)
        {
            lookAround(roomInvestigated);
            //roomInvestigate == true
            continue;
        }

        if (!roomInvestigated)
        {
            continue;
        }

        //enum class would be cool here with good named actions
        switch (choice)
        {
        case 2:
            hasKey = openWardrobe();
            break;
        case 3:
            lookUnderBed();
            break;
        case 4:
            tryOpenDoor(hasKey);
            break;
        case 5:
            isGameRunning = exit();
            break;
        }
    }
    std::cout << "Game Over\n";
    
}


