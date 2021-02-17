#include <iostream>

using namespace std;

double func_3_b(int n) {
    double p1 = 2;
    double p2 = 3;
    for (int i = 2; i <= n; ++i) {
        p1 *= i + 1;
        p2 *= i + 2;
    }
    return p1 / p2;
}

double func_3_a(int n) {
    double p1 = 1;
    double fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact /= i;
        p1 *= (2 + fact);
    }
    return p1;
}

int main() {
    int n = 2;
    cout << func_3_b(n);
}

