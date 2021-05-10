using namespace std;

#include<iostream>

enum Unit {
    KILO, METRE, LITRE, AMOUNT
};

class Product {
private:
    string title;
    int vendorCode;
    Unit unit;
    double price;
    string dateOfDelivery;

public:
    Product() {}

    Product(string title, double price) {
        this->title = title;
        this->price = price;
    }

    void print();

    const string &getTitle() const;

    static void printAll();

    static bool findByTitle(string title);

    static void buyByTitle(string title);

    static void writeToBinFile(Product &p);

    void changePrice();

};

class Toy : public Product {
private:
    int ageRestriction;

public:
    Toy(string title, double price) : Product(title, price) {
    }
};

class Food : public Product {
private:
    string shelfLife;

public:
    Food(string title, double price) : Product(title, price) {
    }
};

class Technic : public Product {
private:
    bool guaranteePresent;
    string guaranteeDate;

public:
    Technic(string title, double price) : Product(title, price) {
    }
};
