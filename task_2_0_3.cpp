#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double arr[10];

    for (int i = 0; i < 10; ++i) {
        double n;
        cin >> n;

        arr[i] = n;
    }

    double sum = 0;
    for (double a : arr) {
        if (a > M_E) sum += a;
    }

    cout << "Sum + " << sum;

}
