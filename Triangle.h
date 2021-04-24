#ifndef TEST_TRIANGLE_H
#define TEST_TRIANGLE_H

#include "Segment.h"

class Triangle {
private:
    Segment segment1;
    Segment segment2;
    Segment segment3;

public:
    void input();

    void output();

    double perimeter();

    double square();

    const Segment &getSegment1() const;

    void setSegment1(const Segment &segment1);

    const Segment &getSegment2() const;

    void setSegment2(const Segment &segment2);

    const Segment &getSegment3() const;

    void setSegment3(const Segment &segment3);

};


#endif //TEST_TRIANGLE_H
