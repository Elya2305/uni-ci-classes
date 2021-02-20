#include <iostream>

using namespace std;

int min_positive(float x1, float x2, float x3) {
    float x;
    int k = 3;

    while (x3 < 0) {
        x = x1 + x2 + x3 + 200;
        x1 = x2;
        x2 = x3;
        x3 = x;
    }
    cout << "X = " << x << "\n";
    return k;
}

int main() {
    float x = -99;
    int k = min_positive(x, x, x);
    
    cout << "k = " << k << "\n";
}
