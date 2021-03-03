#include <iostream>

using namespace std;
#define N 3


void print(float arr[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << arr[x][y];
        }
        cout << endl;
    }
}

void transp(float arr[N][N]) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            float temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    print(arr);
}

void swap(float arr[N][N], int I, int J, float A) {
    arr[I][J] = A;
}

int main() {
    float arr[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    transp(arr);
    print(arr);

    int I, J;
    float A;
    cin >> I >> J >> A;

    if (I < 3 && I >= 0 && J < 3 && J >= 0) {
        swap(arr, I, J, A);
    }
}