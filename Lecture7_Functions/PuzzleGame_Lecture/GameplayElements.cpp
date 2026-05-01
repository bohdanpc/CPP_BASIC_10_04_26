#include <iostream>

//Definitions
void lookAround(bool& roomInvestigated)
{
    std::cout << "A small dark room. A bed, a wardrobe and a locked door\n";
    roomInvestigated = true;
}

bool openWardrobe()
{
    std::cout << "Found a key!!!\n";
    return true;
}

void lookUnderBed()
{
    std::cout << "Nothing interesting...\n";
}

void tryOpenDoor(bool hasKey)
{
    if (hasKey)
    {
        std::cout << "Door is unlocked\n";
        std::cout << "You've won\n";
    }
    else
    {
        std::cout << "Door is locked\n";
    }
}

//DEFINITON
bool exit()
{
    std::cout << "You've died, looser\n";
    return false;
}
