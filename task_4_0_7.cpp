#include<iostream>

using namespace std;

struct Auto {
    double price;
    int age;
};

Auto addAuto(double price, int age) {
    Auto *automobile = new Auto();
    automobile->price = price;
    automobile->age = age;
    return *automobile;
}

void printAvg(Auto autos[], int N) {
    int total = 0;
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        if (autos[i].age > 5) {
            total += 1;
            sum += autos[i].price;
        }
    }
    if (total != 0) {
        cout << "Avg = " << sum / total;
    } else {
        cout << "No autos";
    }
}

int main() {
    Auto autos[] = {
            addAuto(1000, 6),
            addAuto(87, 5),
            addAuto(10, 10),
    };
    printAvg(autos, 3);
}