#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    float number;
    cout << "Number:";
    cin >> number;
    std::cout << std::fixed << setprecision(3) << "Log10: " << log10(number);
    return 0;
}