#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int n;
    cin >> n;

    int count = 0;
    for (int a : arr) {
        if (a < n) count += 1;
    }
    cout << "Count = " << count;
}


