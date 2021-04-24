#ifndef TEST_POINT_H
#define TEST_POINT_H


class Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);

    Point();

public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    void input();

    void output();
};


#endif //TEST_POINT_H
