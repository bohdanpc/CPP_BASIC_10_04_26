#pragma once
#include <iostream>

class Position2D
{
public:
    void print()
    {
        std::cout << "Position: " << x << " " << y << std::endl;
    }

    void updatePosition(int xAdd, int yAdd)
    {
        x += xAdd; y += yAdd;
    }

private:
    int x = 0;
    int y = 0;
};


//aka template(blueprint) for "what real objects will look like"
class Vehicle
{
public:
    //constructor with parameters
    Vehicle(int massArg, double engineDisplacementInLiter);

    //default contructor
    Vehicle() {}

    //destructor
    ~Vehicle() { std::cout << "Calling destructor of Vehicle\n"; }

    //copy contructor
    Vehicle(const Vehicle& other);


    void moveBy(int xArg, int yArg); //method;
    void printPosition() { position.print(); }


    int getMass() { return mass; }
    int calculateMileage();

private:
    double getMassMileageCoefficent();
    double getEngineMileageCoefficient();

    int mass = 1600;
    int engineDisplacement = 1000;
   
    //Composition
    Position2D position;


};

class ParkingSpace
{
public:
    void addVehicle(Vehicle* vehicle);
    void removeVehicle(Vehicle* vehicle);

private:
    Vehicle* m_slots[100] = { nullptr };    //AGGREGATION
    unsigned m_freeSpaces = 100;
};