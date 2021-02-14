#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

bool equals(double x, double y) {
    return (fabs(x - y) < 2 * DBL_EPSILON);
}

bool isNearlyZero(double x) {
    return equals(x, 0);
}

float descriminant(float a, float b, float c) {
    return b * b - 4 * a * c;
}

void biSquareEquation(float a, float b, float c) {
    if (isNearlyZero(a)) {
        if (isNearlyZero(b)) {
            if (isNearlyZero(c)) {
                cout << "Infinity solutions";
            } else {
                cout << "No solutions";
            }
        } else {
            float x = -c / b;
            if (x >= 0) {
                cout << "Two solutions: +-" << sqrt(x);
            }
        }
    } else {
        float D = descriminant(a, b, c);
        if (D < 0) {
            cout << "No solutions";
            return;
        }
        float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        if (D == 0 && x1 >= 0) {
            cout << "Solutions: +-" << sqrt(x1);
            return;
        }

        if (x1 >= 0 && x2 >= 0) {
            cout << "Solutions: +-" << sqrt(x1) << "; +-" << sqrt(x2);
        } else {
            if (x1 >= 0) {
                cout << "Solutions: +-" << sqrt(x1);
            }
            if (x2 >= 0) {
                cout << "Solutions: +-" << sqrt(x2);
            }
        }
    }
}


int main() {
    float a, b, c;
    a = 2;
    b = 2;
    c = 2;

    biSquareEquation(a, b, c);
}

