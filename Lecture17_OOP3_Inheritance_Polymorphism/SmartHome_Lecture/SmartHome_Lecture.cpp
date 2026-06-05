#include <iostream>
#include <vector>
#include <thread>
#include "Device.h"
#include "SmartHome.h"

int main()
{
    SmartHome smartHomeRegular;
    WeatherCompatibleSmartHome smartSmartHome;

    //if user sent command to switch on all devcies
    smartHomeRegular.addDevice(new PC{});
    smartHomeRegular.addDevice(new WorkingLaptop{});
    smartHomeRegular.addDevice(new CoffeeMachine{});

    smartSmartHome.addDevice(new PC{});

    smartHomeRegular.switchOn();


    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        smartHomeRegular.update();
        smartSmartHome.update();
    }
}