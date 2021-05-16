#include<iostream>
#include <fstream>

using namespace std;

struct Toy {
    string title;
    double price;
    int minAge;
    int maxAge;
};

Toy initStruct(string title, double price, int minAge, int maxAge) {
    Toy *toll = new Toy{};
    toll->title = title;
    toll->price = price;
    toll->maxAge = maxAge;
    toll->minAge = minAge;
    return *toll;
}

void writeToBinFile(Toy toy) {
    fstream file;
    file.open("toys.txt", fstream::out | fstream::binary | fstream::app);
    if (!file) {
        cout << "Error in creating file...\n";
    }

    file.write((char *) &toy, sizeof(Toy));
    file.close();
}

/**
 * toys with prices <= @param price for children 5 y.o.
 * */
void printToysTaskA(double price) {
    fstream file;
    file.open("toys.txt", fstream::in | fstream::binary);
    if (!file) {
        cout << "Error in opening file...\n";
    }
    Toy toy;
    while (file.read((char *) &toy, sizeof(Toy))) {
        if (toy.maxAge >= 5 && toy.price <= price) {
            cout << "Toy found: " << toy.title << endl;
        }
    }
    file.close();
}

/**
 * toys for children 4 and 10 y.o.
 * */
void printToysTaskB() {
    fstream file;
    file.open("toys.txt", fstream::in | fstream::binary);
    if (!file) {
        cout << "Error in opening file...\n";
    }
    Toy toy;
    while (file.read((char *) &toy, sizeof(Toy))) {
        if (toy.maxAge >= 10) {
            cout << "Toy found: " << toy.title << endl;
        }
    }
    file.close();
}


int main() {
    Toy toll = initStruct("toll", 12, 0, 10);
    Toy ball = initStruct("ball", 19, 3, 99);
    Toy car = initStruct("car", 120, 0, 13);

    writeToBinFile(toll);
    writeToBinFile(ball);
    writeToBinFile(car);

    printToysTaskA(20);
    printToysTaskB();
}