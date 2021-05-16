#include<iostream>
#include <fstream>

using namespace std;

struct Polinom {
    double coef;
    int deg;
    int num;
};

void writeToBinFile(Polinom polinom) {
    fstream file;
    file.open("polinom.txt", fstream::out | fstream::binary | fstream::app);
    if (!file) {
        cout << "Error in creating file...\n";
    }

    file.write((char *) &polinom, sizeof(Polinom));
    file.close();
}

void derivative(int num) {
    fstream file;
    file.open("polinom.txt", fstream::in | fstream::binary);
    if (!file) {
        cout << "Error in opening file...\n";
    }
    Polinom polinom;
    while (file.read((char *) &polinom, sizeof(Polinom))) {
        if (polinom.num == num) {
            cout << "Derivative: " << polinom.coef * polinom.deg << "x^" << polinom.deg - 1 << endl;
        }
    }
    file.close();
}

int main() {
    Polinom p1 = {12, 2, 1};
    Polinom p2 = {9, 3, 2};
    Polinom p3 = {56, 5, 3};

    writeToBinFile(p1);
    writeToBinFile(p2);
    writeToBinFile(p3);

    derivative(p1.num);
};