#include <iostream>
#include "SmartHome.h"

SmartHome::SmartHome()
{
    std::cout << "C-tor SmartHome\n";
}

SmartHome::~SmartHome()
{
    std::cout << "D-tor of SmartHome\n";
}

void SmartHome::switchOn()
{
    for (int i = 0; i < m_devices.size(); i++)
    {
        m_devices[i]->switchOn();
    }
}

void SmartHome::update()
{
    std::cout << "SmartHome update cycle\n";
    for (int i = 0; i < m_devices.size(); i++)
    {
        m_devices[i]->update();
    }
}

void SmartHome::addDevice(Device* device)
{
    m_devices.push_back(device);
}

void SmartHome::removeDevice(Device* device)
{
	//#Todo - remove device from vector
}

WeatherCompatibleSmartHome::WeatherCompatibleSmartHome() 
    : currentWeather(Weather::Sunny)
{
    std::cout << "C-tor of WeatherCompatibleSmartHome\n";
}

WeatherCompatibleSmartHome::~WeatherCompatibleSmartHome()
{
    std::cout << "D-tor of WeatherCompatibleSmartHome\n";
}

void WeatherCompatibleSmartHome::update()
{
    std::cout << "Weather smart home!\n";
    if (currentWeather == Weather::HeavyStorm)
    {
        for (int i = 0; i < m_devices.size(); i++)
        {
            if (m_devices[i]->IsConnectedToOutlet())
            {
                m_devices[i]->powerOff();
            }
        }
    }

    SmartHome::update();
}
