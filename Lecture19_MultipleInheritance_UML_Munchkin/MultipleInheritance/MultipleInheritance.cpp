#include <iostream>
#include <string>
#include <vector>

class GameObject
{
public:
    GameObject() { std::cout << "Game object c-tor\n"; }
    virtual void update() = 0;
    std::string getName() const { return "Rollback: General Game Object"; }

private:
    int positionX = 0;
    int positionY = 0;
};

class Health
{
public:
    Health() { std::cout << "Health component c-tor\n"; }
    void onDamageReceived()
    {
        currentHealth -= 10;
    }

protected:
    int currentHealth = 100;
};

class Vehicle : public GameObject, public Health
{
public:
    Vehicle() = default;
    void update() override
    {
        std::cout << "Movement update\n";
    }
private:
    int m_power = 150;
};

class Player : public GameObject, public Health
{
public:
    Player() : GameObject(), Health()
    { 
        std::cout << "Player c-tor\n";
    }

    void update() override
    {
        std::cout << "Input update\n";
        std::cout << "Save\load data update\n";
    }
};



int main()
{
    std::vector<GameObject*> gameObjects;

    Vehicle vehicle;
    Player player;

    //while (true)
    {
        for (int i = 0; i < gameObjects.size(); i++)
            gameObjects[i]->update();
    }
}
