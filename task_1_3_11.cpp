#include<iostream>

using namespace std;

int main() {
    int n, m;
    n = 10;
    m = 13;

    int commonOnes = 0;
    int totalCommon = 0;

    for (int i = sizeof(m) * CHAR_BIT; i >= 0; --i) {
        int elemM = ((m >> i) & 1);
        int elemN = ((n >> i) & 1);
        if (elemM && elemN) commonOnes++;
        if (elemM == elemN) totalCommon++;
    }
    cout << "Common ones of " << n << " and " << m << " = " << commonOnes << "\n";
    cout << "Total common bytes = " << totalCommon;
}
