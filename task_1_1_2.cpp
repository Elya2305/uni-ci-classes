#include <iostream>
#include <algorithm>

using namespace std;

float max_mod(float a, float b, float c) {
    float arr[] = {abs(a), abs(b), abs(c)};
    float max = a;
    for (float elem : arr) {
        if (elem > a) max = elem;
    }
    return max;
}

float min_mod(float a, float b, float c) {
    float arr[] = {abs(a), abs(b), abs(c)};
    float min = a;
    for (float elem : arr) {
        if (elem < a) min = elem;
    }
    return min;
}

int main() {
    float a, b, c;
    cout << "Input three numbers separated with space\n";
    cin >> a >> b >> c;
    max_mod(a, b, c);
    cout << "Max module -> " << max_mod(a, b, c) << "\nMin module -> " << min_mod(a, b, c);
    return 0;
}
