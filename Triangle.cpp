#include "Triangle.h"
#include<iostream>

using namespace std;

void Triangle::input() {
    cout << "Input segment #1\n";
    Segment segment1{};
    segment1.input();
    this->setSegment1(segment1);

    cout << "Input segment #2\n";
    Segment segment2{};
    segment2.input();
    this->setSegment2(segment2);

    cout << "Input segment #3\n";
    Segment segment3{};
    segment3.input();
    this->setSegment3(segment3)
}

void Triangle::output() {
    cout << "Segment #1\n";
    segment1.output();

    cout << "Segment #2\n";
    segment2.output();

    cout << "Segment #3\n";
    segment3.output();
}

const Segment &Triangle::getSegment1() const {
    return segment1;
}

void Triangle::setSegment1(const Segment &segment1) {
    Triangle::segment1 = segment1;
}

const Segment &Triangle::getSegment2() const {
    return segment2;
}

void Triangle::setSegment2(const Segment &segment2) {
    Triangle::segment2 = segment2;
}

const Segment &Triangle::getSegment3() const {
    return segment3;
}

void Triangle::setSegment3(const Segment &segment3) {
    Triangle::segment3 = segment3;
}

double Triangle::perimeter() {
    double a = segment1.lengthSegment();
    double b = segment2.lengthSegment();
    double c = segment3.lengthSegment();

    return a + b + c;
}

double Triangle::square() {
    double a = segment1.lengthSegment();
    double b = segment2.lengthSegment();
    double c = segment3.lengthSegment();

    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


