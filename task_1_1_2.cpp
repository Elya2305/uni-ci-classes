#include <iostream>
#include <algorithm>

using namespace std;

float max_mod(float a, float b, float c) {
    float arr[] = {abs(a), abs(b), abs(c)};
    float *res = max_element(arr, arr + 3);
    return float(*res);
}

float min_mod(float a, float b, float c) {
    float arr[] = {abs(a), abs(b), abs(c)};
    float *res = min_element(arr, arr + 3);
    return float(*res);
}

int main() {
    float a, b, c;
    cout << "Input three numbers separated with space\n";
    cin >> a >> b >> c;
    max_mod(a, b, c);
    cout << "Max module -> " << max_mod(a, b, c) << "\nMin module -> " << min_mod(a, b, c);
}

