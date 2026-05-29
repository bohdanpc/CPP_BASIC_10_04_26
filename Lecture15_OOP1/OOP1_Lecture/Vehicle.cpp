#include <iostream>
#include "Vehicle.h"

//constructor with 2 args
Vehicle::Vehicle(int massArg, double engineDisplacementInLiter)
{
    std::cout << "Calling  constructor\n";

    mass = massArg;
    engineDisplacement = static_cast<int>(engineDisplacementInLiter * 1000);
}

//copy contructor
Vehicle::Vehicle(const Vehicle& other)
{
    std::cout << "Copy c-tor\n";

    mass = other.mass;
    engineDisplacement = other.engineDisplacement;
    position = other.position;
}

void Vehicle::moveBy(int xArg, int yArg) //method
{
    position.updatePosition(xArg, yArg);
}

int Vehicle::calculateMileage()
{
    const double massCoefficient = getMassMileageCoefficent();
    const double engineCoefficient = getEngineMileageCoefficient();
    
    return massCoefficient * engineCoefficient * 4;
}

//private functions, can be used only inside other methods of the class Vehicle
double Vehicle::getMassMileageCoefficent()
{
    double massCoefficient = 1.0;

    if (mass > 3000)
    {
        massCoefficient = 3.0;
    }
    else if (mass > 2000)
    {
        massCoefficient = 2.0;
    }
    else if (mass > 1600)
    {
        massCoefficient = 1.5;
    }
   
    return massCoefficient;
}

double Vehicle::getEngineMileageCoefficient()
{
    double engineCoefficient = 1.0;

    if (engineDisplacement > 3000)
    {
        engineCoefficient = 4.0;
    }
    else if (engineDisplacement > 2000)
    {
        engineCoefficient = 3.0;
    }
    return engineCoefficient;
}

void ParkingSpace::addVehicle(Vehicle* vehicle)
{
    //if not full
    if (m_freeSpaces > 0)
    {   
        //find next free slot
        for (int i = 0; i < 100; i++)
        {
            //if free
            if (m_slots[i] == nullptr)
            {
                m_slots[i] = vehicle;
            }
        }
        m_freeSpaces--;
    }
    else
    {
        std::cout << "FULL PARKING!\n";
    }
}

void ParkingSpace::removeVehicle(Vehicle* vehicle)
{
    //find vehicle in array
    for (int i = 0; i < 100; i++)
    {
        if (m_slots[i] == vehicle)
            m_slots[i] = nullptr;

        m_freeSpaces++;
    }
}
