#include<iostream>
#include <cfloat>
#include <cmath>

using namespace std;

double shx(double x) {
    int counter = 3;
    int fact = 1 * 2 * 3;
    double powX = x * x * x;
    double prev = x;
    double next = x + powX / fact;
    while (fabs(next - prev) > 0.001) {
        fact *= ((counter + 1) * (counter + 2));
        powX *= (x * x);
        prev = next;
        next += (powX / fact);
        counter += 2;
    }
    return next;
}

int main() {
    float x;
    cin >> x;
    cout << shx(x);
}
