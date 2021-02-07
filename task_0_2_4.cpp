#include <iostream>
#include <cmath>

using namespace std;

double ellipse_area(float a, float b) {
    return a * b * M_PI;
}

int main() {
    float a, b;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;

    cout << "Area of ellipse -> " << ellipse_area(a, b);
    return 0;
}

