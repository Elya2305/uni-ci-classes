#include <cmath>
#include <iostream>
#include "Matrix3.h"

using namespace std;

double Matrix3::det() {
    int matrix[3][3] = {{this->a.getX(), this->a.getY(), this->a.getZ()},
                        {this->b.getX(), this->b.getY(), this->b.getZ()},
                        {this->c.getX(), this->c.getY(), this->c.getZ()}};

    return determinantInternal(matrix, 3);
}

int Matrix3::determinantInternal(int matrix[3][3], int n) {
    int det = 0;
    int submatrix[3][3];
    if (n == 2) return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det = det + (pow(-1, x) * matrix[0][x] * determinantInternal(submatrix, n - 1));
    }
    return det;
}

void Matrix3::multiplyByVector(Vector3 vector) {
    int matrix[3][3] = {{this->a.getX(), this->a.getY(), this->a.getZ()},
                        {this->b.getX(), this->b.getY(), this->b.getZ()},
                        {this->c.getX(), this->c.getY(), this->c.getZ()}};
    int vect[] = {vector.getX(), vector.getY(), vector.getZ()};
    int result[3];

    for (int &i : result) {
        i = 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i] += (matrix[i][j] * vector[j]);
        }
    }

    cout << "AFTER MULTIPLYING" << endl;
    for (int i : result) {
        cout << i << "  " << endl;
    }
}

void Matrix3::abs() {
    int A[3][3] = {{this->a.getX(), this->a.getY(), this->a.getZ()},
                   {this->b.getX(), this->b.getY(), this->b.getZ()},
                   {this->c.getX(), this->c.getY(), this->c.getZ()}};

    double sum = 0;
    int r = 3;
    int c = 3;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            sum += A[i][j];
        }
        for (int i = 0; i < r; i++) {
            A[i][j] /= sum;
        }
        sum = 0;
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            cout << A[i][j];
        }
        cout << endl;
    }
}
