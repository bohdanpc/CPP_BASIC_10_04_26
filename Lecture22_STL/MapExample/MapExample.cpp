#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> ages;

    ages["Bob"] = 25;
    ages["Alice"] = 39;
    ages["Bodya"] = 12;

    std::cout << ages["Alice"];

    std::map<int, std::string> devices;

    devices[0] = "Xbox360";
    devices[2] = "Ps4";
    devices[4] = "Dualsene";

    //O(logN)
    std::cout << devices[0];

    //for each
    for (const auto& pair : devices)
    {
        std::cout << "Number " << pair.first << ", name " << pair.second << std::endl;
    }
}