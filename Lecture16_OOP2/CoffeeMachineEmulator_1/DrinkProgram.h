#pragma once
#include "WaterReservoir.h"

enum class DrinkType
{
    Espresso,
    Cappuccino
};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    CleanNeeded,    //Not implemented
    //TODO HW, add new status if needed

    Count
};

class DrinkProgram
{
public:
    DrinkProgram(DrinkType type, WaterReservoir& water);

    void showInfo();
    DrinkProgramStatus prepare();

private:
    DrinkType m_drinkType;

    const float EsspressoVolume = 0.05f;

    WaterReservoir& m_waterReservoir; //Aggregation, Drink program doesn't own WaterReservoir
};
