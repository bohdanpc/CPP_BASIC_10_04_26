#include "Device.h"
#include <iostream>

void Device::powerOff() {}

bool Device::IsConnectedToOutlet()
{
    return false;
}

void PC::switchOn()
{
    std::cout << "Power on computer, login into windows\n";
}

void PC::powerOff()
{
    std::cout << "PC power off protocol\n";
}

bool PC::IsConnectedToOutlet()
{
    return true;
}

void PC::update() {}

void WorkingLaptop::update()
{
    if (time > 18)
    {
        mute();
    }
}

void WorkingLaptop::mute()
{
    std::cout << "Muting pc!\n";
}

void CoffeeMachine::switchOn()
{
    std::cout << "Preparing your favorite coffee\n";
    std::cout << "Coffee name: " << m_coffeeName;
}

void CoffeeMachine::update() {}