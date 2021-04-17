
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void logForStr(string str) {
    double numDouble;
    try {
        numDouble = stod(str);
    } catch (invalid_argument) {
        cout << "Invalid number " << str << "\n";
        return;
    }
    if (numDouble < 0) {
        cout << "None\n";
    } else {
        double res = log(numDouble);
        cout << fixed << scientific << "LOG(" << numDouble << ") scientific = " << res << "\n";
        cout << fixed << setprecision(5) << "LOG(" << numDouble << ") = " << res << "\n";
    }
}

int main() {
    string numbers;
    cout << "Input numbers separated by commas\n";
    cin >> numbers;

    string delimiter = ",";

    size_t pos = 0;
    string token;
    while ((pos = numbers.find(delimiter)) != string::npos) {
        token = numbers.substr(0, pos);
        logForStr(token);

        numbers.erase(0, pos + delimiter.length());
    }
    logForStr(numbers);
}