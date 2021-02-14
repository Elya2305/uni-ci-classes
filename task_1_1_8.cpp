#include <cmath>
#include <cfloat>
#include <iostream>

using namespace std;

bool equals(double x, double y) {
    return (fabs(x - y) < 2 * DBL_EPSILON);
}

template<size_t C, size_t R>
void display(float (&mat)[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

template<size_t C, size_t R>
int rang(float (&mat)[R][C]) {
    for (int i = 0; i < R; ++i) {
        for (int j = i + 1; j < R; ++j) {
            float mult = mat[j][i] / mat[i][i];
            for (int c = i; c < C; ++c) {
                mat[j][c] = mat[j][c] - mat[i][c] * mult;
            }
        }
    }
    display(mat);
    int rank = 0;
    for (int i = 0; i < R; ++i) {
        bool zero = true;
        for (int j = 0; j < C; ++j) {
            if (!equals(mat[i][j], 0)) {
                zero = false;
            }
        }
        if (!zero) {
            rank += 1;
        }
    }
    return rank;
}

/**
 * function for calculating determinant
 * @author Elya
 * @params elements of determinant passed line by line
 * */
float det(float a1, float b1, float a2, float b2) {
    return (a1 * b2) - (b1 * a2);
}

/**
 * @author Elya
 * Function for calculating system of equations:
 * 1. a1x+b1x+c1=0;
 * 2. a2x+b2x+c2=0;
 * */
void funcSystem(float a1, float b1, float c1, float a2, float b2, float c2) {
    float d = det(a1, b1, a2, b2);

    if (equals(d, 0)) {
        float A1[2][3] = {{a1, b1, -c1},
                          {a2, b2, -c2}};
        float A2[2][2] = {{a1, b1},
                          {a2, b2}};

        int r1 = rang(A1);
        int r2 = rang(A2);

        if (equals(r1, r2)) {
            cout << "endless solutions";
        } else {
            cout << "no solutions";
        }
        return;
    }

    float x = det(-c1, b1, -c2, b2) / d;
    float y = det(a1, -c1, a2, -c2) / d;

    cout << "Two solutions:\n";
    cout << "X = " << x << "\nY = " << y;

}

int main() {
    float a1, b1, c1, a2, b2, c2;

    cout << "Enter coefficients divided by ' '\n";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    funcSystem(a1, b1, c1, a2, b2, c2);
}

