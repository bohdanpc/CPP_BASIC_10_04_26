#pragma once
#include <string>

class Device
{
public:
    virtual ~Device() = default;

    virtual void switchOn() = 0;
    virtual void update() = 0;

    virtual void powerOff();
    virtual bool IsConnectedToOutlet();
};

class PC : public Device
{
public:
    void switchOn() override;
    void powerOff() override;
    bool IsConnectedToOutlet() override;
    void update() override;
};

class WorkingLaptop : public PC
{
public:
    void update() override;

private:
    int time = 0;
    void mute();
};

class CoffeeMachine : public Device
{
public:
    void switchOn() override;
    void update() override;

private:
    std::string m_coffeeName;
};
