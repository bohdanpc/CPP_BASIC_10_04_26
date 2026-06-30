#include <iostream>
#include <string>

struct Book
{
    std::string name;
    std::string authorName;
    int year;
    std::string isbn;
    int price;
};

class Invoice
{
    double calculateTotal() {
        return (m_book.price - m_book.price * m_discount) * m_amount;
    }

    void safeToFile(const char* filename) {
        //Save to file implementation
    }

    void printInvoice() {
        std::cout << "Name: " << m_book.name;
        std::cout << "Discount: " << m_discount;
        std::cout << "Amount: " << m_amount;
        //...
    }

private:
    int m_discount;
    int m_amount;
    Book m_book;
};

class InvoicePrinter
{
public:
    //Print logic moved here
private:
    Invoice m_invoice;
};

class InvoiceSaver  //ABSTRACTION CLIENT CAN RELY ON
{
public:
    virtual void save(Invoice invoice) = 0;
};

class DatabaseInvoiceSaver : InvoiceSaver
{
public:
    void save(Invoice invoice) override {
        //Saving to DB
    }

private:
    Invoice m_invoice;
};

class FileInvoiceSaver : InvoiceSaver
{
public:
    void save(Invoice invoice) override {
        //Saving to file
    }
};

class SaverManager
{
public:
    void setupSaver(InvoiceSaver* saver) { m_saver = saver; }
    void save() {
        //Relies on abstraction InvoiceSaver* 
        //but not actual DatabaseInvoiceSaver or FileInvoiceSaver
    }

private:
    InvoiceSaver* m_saver;
};


class Bird
{
public:
};


class FlyingBird : public Bird
{
    virtual void fly() = 0;
};

class Duck : public FlyingBird
{
public:
    virtual void fly() override {
        //Duck way of flying
    }
};

class Penguin : public Bird
{
public:
};

class Car
{

};

class ParkingLot
{
    virtual void parkCar() = 0;
    virtual void unparkCar() = 0;
    virtual void getCapacity() = 0;
};

class FreeParkingLot : ParkingLot
{
    void parkCar() override {}
    void unparkCar() override {}
    void getCapacity() override {}
};



class Car {

}

int main()
{

}

