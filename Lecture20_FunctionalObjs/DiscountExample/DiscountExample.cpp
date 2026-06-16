#include <iostream>

class DiscountStrategy
{
public:
    virtual double Apply(double price) const = 0;
    virtual ~DiscountStrategy() = default;
};

class PercentageDiscountStrategy : public DiscountStrategy
{
public:
    PercentageDiscountStrategy(double p)
        : m_percent(p) {
    }

    double Apply(double price) const override
    {
        return price * (1.0 - m_percent / 100.0);
    }

    void changePercentage(double newPercentage) { m_percent = newPercentage; }

private:
    double m_percent;
};

class FixedDiscountStrategy : public DiscountStrategy
{
public:
    FixedDiscountStrategy(double a)
        : m_amount(a) {
    }

    double Apply(double price) const override
    {
        return std::max(price - m_amount, 0.0);
    }

private:
    double m_amount;
};

class PercentageDiscountFunctional
{
public:
    PercentageDiscountFunctional(double p)
        : m_percent(p)
    {
    }

    void UpdatePercentage(double newPercentage) { m_percent = newPercentage; }

    double operator()(double price) const
    {
        return price * (1.0 - m_percent / 100.0);
    }

private:
    double m_percent;
};

double Apply15Percent(double price)
{
    return price * (1.0 - 0.15);
}

int main()
{
    //Classic procedural way
    std::cout << Apply15Percent(100);

    //OOP Polymorphic way
    DiscountStrategy* discount = new PercentageDiscountStrategy(15);
    FixedDiscountStrategy* fixedDiscount = new FixedDiscountStrategy(10);

    std::cout << discount->Apply(100);

    //Functional way
    PercentageDiscountFunctional functionalDisccount(10);
    std::cout << functionalDisccount(200);
}