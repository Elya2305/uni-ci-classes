#include <iostream>

using namespace std;
#define N 5

void sumParAndNot(const int arr[N]) {
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 1; i < N; ++i) {
        if (arr[i] % 2 == 0) {
            sum1 += arr[i];
        }
        if (arr[i] % 2 != 0) {
            sum2 += arr[i];
        }
    }
    cout << "Sum of parni = " << sum1 << "\n";
    cout << "Sum of not parni = " << sum2;

}

int main() {

    int arr[N];
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;

        arr[i] = n;
    }

    sumParAndNot(arr);
}