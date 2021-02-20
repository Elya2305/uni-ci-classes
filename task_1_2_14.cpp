#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Input numbers (the last one must be 0)\n";
    int a = 0;
    double sum = 0;
    double dob = 1;
    int n = -1;

    do {
        cin >> a;
        sum += a;
        if (a != 0) {
            dob *= a;
        }
        n++;
    } while (a != 0);

    cout << "Average arithmetical: " << sum / n << "\n";
    cout << "Average geometrical: " << pow(dob, 1.0 / n) << "\n";
}