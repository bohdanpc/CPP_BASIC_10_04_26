#include <iostream>


class Animal    //BASE CLASS
{
public:
    //Interface functions
    virtual void eat() = 0;
    virtual void move() = 0;

    std::string getName() const { return name; superSecret; }

protected:
    std::string name;
    int age;
    int gender;

private:
    int superSecret;
};

class Dog : public Animal
{
public:
    void bark() { 
        age = 10;
        gender = 25;
        std::cout << "Barking!\n"; 
    }

    //polymorphism
    virtual void eat() override
    {
        std::cout << "Chewing really fast my fav meat\n";
    }

    virtual void move() override
    {
        std::cout << "Moving on 4 legs\n";
    }

    std::string getName() const { return "Dog " + name; }

private:
    int owner;
};

class DogAlabai : public Dog
{
public:
    void securePerimiter() { std::cout << "Securing perimiter very well!\n"; }
};

void updateAnimal(Animal& animal)
{
    animal.move();
    animal.eat();
}

void updateDog(Dog& dog)
{
    dog.eat();
    dog.move();
    dog.bark();
}


void eatFunction(Animal& generalAn)
{
	generalAn.eat();    //Depending on ACTUAL type of the object, the correct eat() function will be called
}

int main()
{
    Dog dog;

    dog.eat();      // Dog :: eat

    //eatFunction(myAnimal);
    eatFunction(dog);

    Animal* ptrToAnyAnimal = nullptr;
    ptrToAnyAnimal = new Dog{};

    ptrToAnyAnimal->eat();

    Animal* arrayOfAnimals[10];
    arrayOfAnimals[0] = new Dog{};
    arrayOfAnimals[1] = new DogAlabai{};


    for (int i = 0; i < 3; i++)
    {
        arrayOfAnimals[i]->eat();
        arrayOfAnimals[i]->move();
    }
}
