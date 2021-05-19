#include "Vector3.h"

#ifndef TEST_MATRIX3_H
#define TEST_MATRIX3_H


class Matrix3 {
private:
    Vector3 a;
    Vector3 b;
    Vector3 c;
    int matrixInternal[3][3];

public:
    Matrix3(Vector3 a, Vector3 b, Vector3 c) : a(a), b(b), c(c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double det();

    void multiplyByVector(Vector3 vector);

    void abs();


private:
    int determinantInternal(int matrix[3][3], int n);
};


#endif