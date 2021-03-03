#include <iostream>

using namespace std;
int M, N;

int main() {
    M = 2;
    N = 3;

    float arr[M][N];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Input " << (i + 1) << " " << (j + 1) << " element of mass\n";
            float a;
            cin >> a;
            arr[i][j] = a;
        }
    }
}

