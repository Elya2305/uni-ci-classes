#include <iostream>

using namespace std;

float min_positive(float x1, float x2, float x3) {
    float x = x1 + x2 + x3 + 200;

    while (x < 0) {
        x1 = x2;
        x2 = x3;
        x3 = x;
        x = x1 + x2 + x3 + 200;
    }
    return x;
}

int main() {

    float x = -99;

    cout << min_positive(x, x, x);
}