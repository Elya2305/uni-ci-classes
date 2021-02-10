#include <iostream>

using namespace std;

int max_k(int m) {
    int k = 0;
    int four = 4;
    while (four <= m) {
        four *= 4;
        k += 1;
    }
    return k;
}

int min_r(int n) {
    int start = 1;
    do {
        start *= 2;
    } while (start < n);
    return start;
}

int main() {
    int m;
    cin >> m;

    cout << max_k(m);
    cout << min_r(m);
}