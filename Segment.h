#ifndef TEST_SEGMENT_H
#define TEST_SEGMENT_H

#include <cmath>
#include "Point.h"

class Segment {
private:
    Point p1;
    Point p2;
public:
    const Point &getP1() const;

    const Point &getP2() const;

    void input();

    void output();

    void midpoint();

    double lengthSegment();

    Point intersection(Segment other) const;

private:
    static double distance(double x1, double y1, double x2, double y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    }
};


#endif //TEST_SEGMENT_H
