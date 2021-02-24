#include <iostream>

using namespace std;
#define N 5

int max(const int arr[N]) {
    int max = arr[0];
    for (int i = 1; i < N; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {

    int arr[N];
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        arr[i] = n;
    }

    cout << "Max " << max(arr);
}