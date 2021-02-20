#include <iostream>

using namespace std;

int main() {
    int n;
    double a1 = 1, b1 = 1;
    double ak, bk;
    cout << "n=";
    cin >> n;

    int fact = 1;
    double sumPowTwo = 2;
    for (int i = 2; i <= n; ++i) {
        ak = 3 * b1 + 2 * a1;
        bk = 2 * a1 + b1;
        a1 = ak;
        b1 = bk;
        fact *= i;
        sumPowTwo += sumPowTwo * 2;
        cout << sumPowTwo << " " << ((1 + ak + bk) * fact) << "\n";
    }
    double S = sumPowTwo / ((1 + ak + bk) * fact);

    cout << "S = " << S;
}