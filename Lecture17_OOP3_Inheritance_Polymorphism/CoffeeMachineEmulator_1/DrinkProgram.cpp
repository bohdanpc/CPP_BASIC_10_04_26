#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(WaterReservoir& water) :
	m_waterReservoir(water) {
}

void DrinkProgram::showInfo()
{
	std::cout << "General Drink!\n";
}

void Espresso::showInfo()
{
	std::cout << "Espresso! 50ml";
}

DrinkProgramStatus Espresso::prepare()
{
	if (m_waterReservoir.getVolume() < EsspressoVolume)
	{
		return DrinkProgramStatus::LowWater;
	}

	m_waterReservoir.useWater(EsspressoVolume);

	std::cout << "\n\nGrrr ";
	std::cout << "Using " << EsspressoVolume << "l out of "
		<< EsspressoVolume + m_waterReservoir.getVolume() << "l of water for preparation\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "\nPreparing... Espresso... ";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	for (int i = 5; i > 3; i--)
	{
		std::cout << i << ".";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << ".";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	std::cout << "..Hanging... ";
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << "DONE!\n";
	std::cout << "Enjoy your fresh ESPRESSO!\n\n";

	return DrinkProgramStatus::Success;
}
