#include <iostream>

using namespace std;

/**
 * x(k) = ((-1)^k * x^k)/k
 * */
float func(int k, float x) {
    float powX = x;
    float one = k % 2 == 0 ? 1 : -1;
    for (int i = 2; i <= k; ++i) {
        powX *= powX;
    }
    return one * (powX / k);
}

int main() {
    int k;
    float x;
    cout << "k=";
    cin >> k;
    cout << "x=";
    cin >> x;

    cout << "\nResult : " << func(k, x);
}