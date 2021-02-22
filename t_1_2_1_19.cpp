#include <iostream>
#include <cmath>

using namespace std;

bool isSimple(int n) {
    for (int i = 2; i <= pow(n, 0.5); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 10;

    int i = 2;
    while (i < n) {
        if (isSimple(i)) {
            cout << i << "\n";
        }
        i++;
    }


}