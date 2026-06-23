#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::vector<int> elements;
    
    for (int i = 0; i < 10; i++)
    {
        elements.push_back(i + 1);
    }

    for (int i = 0; i < elements.size(); i++)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    auto toRemove = std::remove(elements.begin(), elements.end(), 5);

    for (int i = 0; i < elements.size(); i++)
    {
        std::cout << elements[i] << " ";
    }

    elements.erase(toRemove);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    for (int i = 0; i < elements.size(); i++)
    {
        std::cout << elements[i] << " ";
    }

}
