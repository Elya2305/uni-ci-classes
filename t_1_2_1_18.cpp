
#include <iostream>

using namespace std;

int main() {
    unsigned int n;
    unsigned int k;
    cin >> n;
    cin >> k;
    unsigned int res = (1 << k) | n;


    cout << res;
}
