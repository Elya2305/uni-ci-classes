#include <iostream>

using namespace std;

int main() {
    float A, B, C;
    cout << "A=";
    cin >> A;
    cout << "B=";
    cin >> B;
    cout << "C=";
    cin >> C;

    float average_arithmetic = (A + B + C) / 3;
    cout << "1. Simple format: " << average_arithmetic << "\n" << scientific << "   Scientific format: "
         << average_arithmetic << "\n\n";

    float average_geometric = 3 / (1 / A + 1 / B + 1 / C);
    cout << "2. Simple format: " << average_geometric << "\n" << scientific << "   Scientific format: "
         << average_geometric;
    return 0;
}