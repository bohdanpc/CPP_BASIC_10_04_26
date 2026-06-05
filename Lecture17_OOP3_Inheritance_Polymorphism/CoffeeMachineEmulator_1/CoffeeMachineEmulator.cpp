#include <iostream>
#include <vector>

#include "CoffeeMachine.h"

int main()
{
    CoffeeMachine machine;
    
    machine.addRecipe(new Espresso(machine.getWaterReservoir()));
    //TODO: @students, add your own recipes here once implemented

    while (machine.IsBooted())
    {
        machine.showMenu();
        machine.receiveInput();
        machine.update();
    }

    return 0;
}
