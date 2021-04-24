#include "Triangle.h"
#include<iostream>

using namespace std;

int main() {
    Segment s1;
    s1.input();
    Segment s2;
    s2.input();
    Point point = s1.intersection(s2);
    point.output();

    Triangle triangle{};
    triangle.input();
    triangle.output();
    double P = triangle.perimeter();
    double S = triangle.square();
    cout << "P=" << P << "\n";
    cout << "S=" << S << "\n";
}