#include <iostream>

using namespace std;
int N;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countTotalDivisibleBy7(int arr[]) {
    int counter = 0;
    for (int i = 0; i < N; ++i) {
        if (sumOfDigits(arr[i]) % 7 == 0) {
            counter++;
        }
    }
    return counter;
}

int main() {
    cout << "N=";
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; ++i) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
    cout << "Total sum of digits dividable by 7: " << countTotalDivisibleBy7(arr);
}

