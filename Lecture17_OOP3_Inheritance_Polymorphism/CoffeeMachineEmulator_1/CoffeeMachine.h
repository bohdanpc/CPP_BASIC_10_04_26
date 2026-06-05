#pragma once
#include <vector>
#include <iostream>

#include "WaterReservoir.h"
#include "DrinkProgram.h"

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
    ~CoffeeMachine();

    void addRecipe(DrinkProgram* program);
    bool IsBooted() const { return m_currentState != CoffeeMachineState::PowerOffRequest; }

    void showMenu();
    void receiveInput();
    void update();

    WaterReservoir& getWaterReservoir() { return m_waterReservoir; }
private:
    void powerOn();

    void selectNewMenuFromMain();
    
    void showListOfDrinks();
    void selectDrink();
    void prepareDrink();

    void showLowWaterError();

private:
    WaterReservoir m_waterReservoir;

    std::vector<DrinkProgram*> m_recipes;
    CoffeeMachineState m_currentState = CoffeeMachineState::Sleep;

    int m_currentChoice = -1;
};
