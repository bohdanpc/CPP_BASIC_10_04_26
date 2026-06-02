#pragma once
#include <vector>
#include <iostream>

#include "WaterReservoir.h"
#include "DrinkProgram.h"

class CoffeeGrainsContainer
{
    //not used yet
};


enum class CoffeeMachineState
{
    Sleep,
    PowerOffRequest,
    
    MainMenu,
    
    WaterReservoir,
    CoffeeGrain,    //Not implemented yet

    DrinkSelection,
    DrinkPreparation,

    LowWaterError,
};


class CoffeeMachine
{
public:
    ~CoffeeMachine() 
    {
        //TODO HW: clear recipes memory from vector}
    }

    bool IsBooted() const { return !m_powerOffRequest; }

    void showMenu();
    void receiveInput();
    void update();

private:
    void powerOn();
    void powerOff();

    void selectNewMenuFromMain();
    
    void showListOfDrinks();
    void prepareDrink();
    void selectDrink();

    void showLowWaterError();

private:
    WaterReservoir m_waterReservoir;

    DrinkProgram m_recipes[2]{ DrinkProgram{DrinkType::Espresso, m_waterReservoir}, DrinkProgram{DrinkType::Cappuccino, m_waterReservoir} };
    
    CoffeeMachineState m_currentState = CoffeeMachineState::Sleep;

    int m_currentChoice = -1;
    bool m_powerOffRequest = false;
};
