#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

class Enemy
{
public:
    Enemy(int d) : damage{ d } {}

    int GetDamage() const {
        return damage;
    }

    bool operator<(const Enemy& enemy) const
    {
        return GetDamage() < enemy.GetDamage();
    }

private:
    int damage = 10;
};

bool CompareByDamage(const Enemy& enemy, const Enemy& enemy2)
{
    return enemy.GetDamage() > enemy.GetDamage();
}

class EnemyComparator
{
public:
    bool operator()(const Enemy& enemy1, const Enemy& enemy2)
    {
        return enemy1.GetDamage() > enemy2.GetDamage();
    }
};

int main()
{
    std::vector<Enemy> enemies{ Enemy{10}, Enemy{20}, Enemy{1}, Enemy{100} };

    std::sort(enemies.begin(), enemies.end(), CompareByDamage);
    std::sort(enemies.begin(), enemies.end());

    std::sort(enemies.begin(), enemies.end(), 
        [](const Enemy& enemy, const Enemy& enemy2)
    { return enemy.GetDamage() > enemy2.GetDamage(); }
    );

    std::function<bool(const Enemy&, const Enemy&)> enemyComparator;

    enemyComparator = CompareByDamage;

    Enemy enemy1{ 10 }, enemy2{ 20 };

    enemyComparator(enemy1, enemy2);

    EnemyComparator e1;
    enemyComparator = e1;

    enemyComparator = [](const Enemy& e1, const Enemy& e2) {return e1.GetDamage() > e2.GetDamage(); };

}
