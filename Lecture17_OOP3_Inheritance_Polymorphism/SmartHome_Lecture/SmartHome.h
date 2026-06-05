#pragma once
#include <vector>
#include "Device.h"

class SmartHome
{
public:
    SmartHome();
    virtual ~SmartHome();

    void switchOn();
    virtual void update();

    void addDevice(Device* device);
    void removeDevice(Device* device);

protected:
    std::vector<Device*> m_devices;
};


class WeatherCompatibleSmartHome : public SmartHome
{
public:
    WeatherCompatibleSmartHome();
    ~WeatherCompatibleSmartHome();

    virtual void update();

private:
    enum class Weather
    {
        Sunny,
        Rain,
        HeavyStorm
    };

    Weather currentWeather;
};
