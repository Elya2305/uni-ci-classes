#include <iostream>
#include <cmath>

using namespace std;

double func(int n, double x) {
    int fact = 1;
    double res = 1;
    for (int i = 1; i < n; ++i) {
        fact *= i;
        res += pow(x, i) / fact;
    }
    return res;
}


int main() {
    int n;
    double x;
    cin >> n >> x;

    cout << func(n, x);

}
