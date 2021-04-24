#include "Point.h"
#include<iostream>

using namespace std;

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    Point::x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    Point::y = y;
}

void Point::input() {
    cout << "x=";
    cin >> x;
    cout << "y=";
    cin >> y;
}

void Point::output() {
    cout << "(" << x << ", " << y << ")";
}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() {}
