#include <cmath>
#include <cfloat>
#include <iostream>

using namespace std;
float NO_SOLUTION = -1;


bool equals(double x, double y) {
    return (fabs(x - y) < 2 * DBL_EPSILON);
}

double sinc(float x) {
    return equals(x, 0) ? 1 : sin(x) / x;
}

double sinc_derivative(float x) {
    return equals(x, 0) ? NO_SOLUTION : (x * cos(x) - sin(x)) / (x * x);
}

int main() {
    float x;
    cin >> x;

    cout << "Derivative = " << sinc_derivative(x);
}
