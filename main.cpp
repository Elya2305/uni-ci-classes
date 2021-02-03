#include <iostream>
#include <cmath>

using namespace std;

double task_03_b(double x) {
    return pow(x, 4) + pow(x, 3) + pow(x, 2) + x + 1;
}

double task_03_b_v_2(double x) {
    return (pow(x, 5) - 1) / (x - 1);
}

int main() {
    float x;
    cout << "X=";
    cin >> x;

    cout << "Result: " << task_03_b(x) << "\n";
    cout << "Result: " << task_03_b_v_2(x);

    return 0;
}