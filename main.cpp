#include <iostream>

using namespace std;

double func(int n, double x) {
    int fact = 1;
    double res = 1;
    double power = x;
    for (int i = 1; i < n; ++i) {
        power = power * x;
        fact *= i;
        res += power / fact;
    }
    return res;
}


int main() {
    int n;
    double x;
    cin >> n >> x;

    cout << func(n, x);

}
