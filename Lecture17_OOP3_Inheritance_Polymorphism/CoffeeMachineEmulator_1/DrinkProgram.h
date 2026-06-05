#pragma once
#include "WaterReservoir.h"

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    CleanNeeded,    //Not implemented
    //TODO OPTIONAL HW, add new status if needed

    Count
};

class DrinkProgram
{
public:
    DrinkProgram(WaterReservoir& water);

    virtual void showInfo();
    virtual DrinkProgramStatus prepare() = 0;

    virtual ~DrinkProgram() {}

protected:
    WaterReservoir& m_waterReservoir; //Aggregation, Drink program doesn't own WaterReservoir
};

class Espresso : public DrinkProgram
{
public:
    Espresso(WaterReservoir& water) : DrinkProgram(water) {}

    DrinkProgramStatus prepare() override;
    void showInfo() override;

private:
    const float EsspressoVolume = 0.05f;
};

class Capuccino : public DrinkProgram
{
    //#TODO, students: Implement similarily to the Espresso class
public:

private:

};

class Tea : public DrinkProgram
{
    //#TODO: students implement
};