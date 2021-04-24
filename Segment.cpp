#include "Segment.h"
#include<iostream>

using namespace std;

void Segment::input() {
    Point point1{};
    cout << "Input point1: \n";
    point1.input();
    Segment::p1 = point1;

    cout << "Input point2: \n";
    Point point2{};
    point2.input();
    Segment::p2 = point2;
}

void Segment::output() {
    cout << "Point1: ";
    p1.output();

    cout << "Point2: ";
    p2.output();
}

void Segment::midpoint() {
    double midX = (p1.getX() + p2.getX()) / 2;
    double midY = (p1.getY() + p2.getY()) / 2;

    cout << "Midpoint: (" << midX << ", " << midY << ")";
}

double Segment::lengthSegment() {
    return distance(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

/**
 * convert lines to A1x + B1y = C1, A2x + B2y = C2 and find the intersection
 * */
Point Segment::intersection(Segment other) const {
    double A1 = this->getP2().getY() - this->getP1().getY();
    double B1 = this->getP1().getX() - this->getP2().getX();
    double C1 = A1 * this->getP1().getX() + B1 * this->getP1().getY();

    double A2 = other.getP2().getY() - other.getP1().getY();
    double B2 = other.getP1().getX() - other.getP2().getX();
    double C2 = A1 * other.getP1().getX() + B1 * other.getP1().getY();

    double det = A1 * B2 - A2 * B1;
    if (det == 0) {
        return Point{};
    } else {
        double x = (B2 * C1 - B1 * C2) / det;
        double y = (A1 * C2 - A2 * C1) / det;
        return Point{x, y};
    }
}

const Point &Segment::getP1() const {
    return p1;
}

const Point &Segment::getP2() const {
    return p2;
}