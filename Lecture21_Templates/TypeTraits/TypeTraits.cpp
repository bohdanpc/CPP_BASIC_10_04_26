#include <iostream>
#include <type_traits>

class Player
{
public:
    Player() {}
    ~Player() {}
};

class Foo
{
    ~Foo() = delete;
};

enum class Colors
{
    REd, Blue, Yellow
};

int main()
{
    std::cout << std::is_floating_point<float>::value << std::endl; //true
    std::cout << std::is_floating_point<Player>::value << std::endl; //false
    std::cout << std::is_floating_point<double>::value << std::endl; //true

    std::cout << std::is_enum<int>::value; //false
    std::cout << std::is_enum<Colors>::value; // true

    std::cout << std::is_destructible<Player>::value; //true
    std::cout << std::is_destructible<Foo>::value; //false

    std::cout << std::is_same<Player, Player>::value; //true
    std::cout << std::is_same<Player, Player&>::value; //false
}
