#include <iostream>
#include <functional>

class A {
public:
    int x = 10;

    std::function<int()> getLambda()
    {
        return [this]() {
            return x;
        };
    }
};

int main()
{
    std::function<int()> f;

    {
        A a;
        f = a.getLambda();
    } 
    //a object is destroyed here
    //capture this ptr and hence this->x inside of f is no longer valid

    std::cout << f();   //Undefined Behavior (it may be 10 (but not guaranteed), crash, or trash value)
}
