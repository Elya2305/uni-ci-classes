#include <iostream>
#include <cmath>

using namespace std;

double len(float a1, float b1, float a2, float b2) {
    return sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
}

double square(double a, double b, double c) {
    double p = (a + b + c) / 3;
    return pow(p * (p - a) * (p - b) * (p - c), 1 / 2);
}

int main() {
    float a1, b1, a2, b2, a3, b3;

    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;

    double a = len(a1, b1, a2, b2);
    double b = len(a1, b1, a3, b3);
    double c = len(a2, b2, a3, b3);

    cout << "S = " << square(a, b, c);
    return 0;
}