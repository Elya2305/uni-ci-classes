#include <iostream>

using namespace std;

/**
 * function for calculating f(x,y)
 * f(x,y) = 1 + x^2*y + x^4+y^2 + ... + x^(2*n-2)*y^(n-1)
 * */
float func(int n, float x, float y) {
    float res = 1;
    float powY = 1;
    float powX = 1;
    for (int i = 1; i < n; ++i) {
        powX *= x * x;
        powY *= y;
        res += powX * powY;
    }
    return res;
}

int main() {
    int n = 4;
    float x = 2;
    float y = 2;

    cout << "Result = " << func(n, x, y);
}