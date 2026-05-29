#include <iostream>
#include "Vehicle.h"

int main()
{
    Vehicle myDailyCar{1500, 1.5};

    std::cout << myDailyCar.calculateMileage() << "L per 100 km\n";

    ParkingSpace parking;
    parking.addVehicle(&myDailyCar);

    //Going to lunch, bla-bla-bla

    parking.removeVehicle(&myDailyCar);
}


